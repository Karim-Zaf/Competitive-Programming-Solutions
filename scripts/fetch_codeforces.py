#!/usr/bin/env python3
"""
Codeforces Solution Fetcher
===========================
Fetches all accepted solutions from Codeforces and organizes them.
Uses nodriver (undetected Chrome) + Chrome cookies to bypass Cloudflare.
Supports resume if interrupted.

Usage:
    python3 fetch_codeforces.py              # Fetch all
    python3 fetch_codeforces.py --readme-only # Regenerate README only
    python3 fetch_codeforces.py --no-skip    # Re-fetch everything

Requirements:
    pip install nodriver pycookiecheat requests beautifulsoup4
"""

import argparse
import asyncio
import json
import re
import sys
import time
from collections import defaultdict
from datetime import datetime
from pathlib import Path

import nodriver as uc
import nodriver.cdp.network as cdp_network
import requests
from bs4 import BeautifulSoup
from pycookiecheat import chrome_cookies

CF_API = "https://codeforces.com/api"
CF_URL = "https://codeforces.com"
DELAY = 2  # seconds between page loads
REPO_ROOT = Path(__file__).resolve().parent.parent


def sanitize_filename(name: str) -> str:
    name = re.sub(r'[<>:"/\\|?*]', '_', name)
    name = re.sub(r'\s+', '_', name)
    name = re.sub(r'_+', '_', name)
    return name.strip('_.')


def lang_extension(language: str) -> str:
    lang = language.lower()
    if 'c++' in lang or 'gnu c++' in lang:
        return '.cpp'
    if 'python' in lang or 'pypy' in lang:
        return '.py'
    if 'java' in lang:
        return '.java'
    if 'kotlin' in lang:
        return '.kt'
    if 'rust' in lang:
        return '.rs'
    if 'go' in lang:
        return '.go'
    if 'c#' in lang:
        return '.cs'
    if 'javascript' in lang:
        return '.js'
    if 'ruby' in lang:
        return '.rb'
    if 'haskell' in lang:
        return '.hs'
    return '.txt'


def classify(contest_id: int) -> str:
    return 'GYM' if contest_id >= 100000 else 'Contests'


def get_filepath(sub: dict) -> Path:
    problem = sub['problem']
    contest_id = problem['contestId']
    index = problem['index']
    name = problem.get('name', 'Unknown')
    ext = lang_extension(sub['programmingLanguage'])
    category = classify(contest_id)
    safe_name = sanitize_filename(name)
    filename = f"{index}_{safe_name}{ext}"
    return REPO_ROOT / "Codeforces" / category / str(contest_id) / filename


# ── API functions (no auth needed) ──────────────────────────────────────

def fetch_submissions(handle: str) -> list[dict]:
    cache_file = REPO_ROOT / 'scripts' / 'submissions_cache.json'

    # Try API first
    print(f"[*] Fetching submissions for {handle}...")
    try:
        resp = requests.get(f"{CF_API}/user.status",
                            params={'handle': handle, 'from': 1, 'count': 100000},
                            timeout=60)
        resp.raise_for_status()
        data = resp.json()
        if data['status'] != 'OK':
            raise RuntimeError(f"API error: {data.get('comment', 'Unknown')}")
        all_subs = data['result']

        # Cache for next time
        with open(cache_file, 'w') as f:
            json.dump(all_subs, f)
        print(f"[+] Cached {len(all_subs)} submissions")
    except Exception as e:
        print(f"[!] API failed: {e}")
        if cache_file.exists():
            print("[*] Using cached submissions...")
            with open(cache_file) as f:
                all_subs = json.load(f)
        else:
            raise

    ac_subs = [s for s in all_subs if s.get('verdict') == 'OK']

    best: dict[tuple, dict] = {}
    for sub in ac_subs:
        key = (sub['problem']['contestId'], sub['problem']['index'])
        if key not in best or sub['id'] > best[key]['id']:
            best[key] = sub

    subs = sorted(best.values(), key=lambda s: s['problem']['contestId'])
    print(f"[+] {len(all_subs)} total, {len(ac_subs)} AC, "
          f"{len(subs)} unique problems")
    return subs


def fetch_contest_names() -> dict[int, str]:
    cache_file = REPO_ROOT / 'scripts' / 'contests_cache.json'
    print("[*] Fetching contest list...")
    try:
        resp = requests.get(f"{CF_API}/contest.list", timeout=30)
        resp.raise_for_status()
        data = resp.json()
        if data['status'] == 'OK':
            cache = {str(c['id']): c['name'] for c in data['result']}
            with open(cache_file, 'w') as f:
                json.dump(cache, f)
            result = {int(k): v for k, v in cache.items()}
            print(f"[+] {len(result)} contest names loaded & cached")
            return result
    except Exception as e:
        print(f"[!] API failed: {e}")
        if cache_file.exists():
            print("[*] Using cached contest names...")
            with open(cache_file) as f:
                cache = json.load(f)
            return {int(k): v for k, v in cache.items()}
    return {}


# ── Metadata ────────────────────────────────────────────────────────────

def load_metadata() -> tuple[list[dict], set[tuple]]:
    meta_file = REPO_ROOT / 'problems.json'
    if meta_file.exists():
        with open(meta_file) as f:
            metadata = json.load(f)
        keys = {(p['contestId'], p['index']) for p in metadata}
        return metadata, keys
    return [], set()


def save_metadata(metadata: list[dict]):
    metadata.sort(key=lambda m: (m['contestId'], m['index']))
    meta_file = REPO_ROOT / 'problems.json'
    with open(meta_file, 'w', encoding='utf-8') as f:
        json.dump(metadata, f, indent=2, ensure_ascii=False)


# ── Browser-based source fetching ──────────────────────────────────────

async def setup_browser():
    """Launch browser and inject Chrome cookies via CDP."""
    print("[*] Extracting cookies from Chrome...")
    cookies = chrome_cookies('https://codeforces.com')
    print(f"[+] Got {len(cookies)} cookies")

    httponly_names = {'JSESSIONID', 'X-User', 'X-User-Sha1', 'cf_clearance'}

    print("[*] Launching browser...")
    browser = await uc.start(headless=False)
    page = await browser.get('about:blank')

    for name, value in cookies.items():
        await page.send(cdp_network.set_cookie(
            name=name,
            value=value,
            domain='.codeforces.com',
            path='/',
            http_only=(name in httponly_names),
            secure=(name == 'cf_clearance'),
        ))

    print("[+] Cookies injected via CDP")
    return browser, page


async def get_source_from_page(page, contest_id: int, submission_id: int,
                                is_gym: bool) -> str | None:
    """Navigate to submission page and extract source code."""
    prefix = "gym" if is_gym else "contest"
    url = f"{CF_URL}/{prefix}/{contest_id}/submission/{submission_id}"

    try:
        page = await page.browser.get(url)
        await asyncio.sleep(DELAY)

        # Wait for page to be ready (up to 10 seconds)
        for _ in range(5):
            title = await page.evaluate('document.title')
            if 'Submission' in title or 'Codeforces' in title:
                break
            await asyncio.sleep(2)

        # Extract source code
        code = await page.evaluate('''
            (() => {
                let el = document.getElementById("program-source-text");
                if (el) return el.innerText;
                return null;
            })()
        ''')
        return code
    except Exception as e:
        print(f"    [!] Error: {e}")
        return None


async def get_source_via_ajax(page, submission_id: int) -> str | None:
    """Use Codeforces AJAX endpoint to get source code (faster)."""
    try:
        result = await page.evaluate('''
            (() => {
                try {
                    var csrf = Codeforces.getCsrfToken();
                    var xhr = new XMLHttpRequest();
                    xhr.open("POST", "/data/submitSource", false);
                    xhr.setRequestHeader("Content-Type",
                        "application/x-www-form-urlencoded");
                    xhr.setRequestHeader("X-Csrf-Token", csrf);
                    xhr.send("submissionId=''' + str(submission_id) + '''");
                    if (xhr.status === 200) {
                        var data = JSON.parse(xhr.responseText);
                        return data.source || null;
                    }
                    return null;
                } catch(e) {
                    return null;
                }
            })()
        ''')
        return result
    except Exception:
        return None


async def refresh_session(browser):
    """Navigate back to homepage to refresh CSRF token."""
    page = await browser.get('https://codeforces.com')
    await asyncio.sleep(2)
    body = await page.evaluate('document.body.innerText')
    logged_in = 'Kairm_Zaf' in body
    if not logged_in:
        print("    [!] Session lost, re-injecting cookies...")
        cookies = chrome_cookies('https://codeforces.com')
        for name, value in cookies.items():
            await page.send(cdp_network.set_cookie(
                name=name, value=value,
                domain='.codeforces.com', path='/',
                http_only=(name in {'JSESSIONID', 'X-User',
                                     'X-User-Sha1', 'cf_clearance'}),
                secure=(name == 'cf_clearance'),
            ))
        page = await browser.get('https://codeforces.com')
        await asyncio.sleep(2)
    return page


async def fetch_all_sources(submissions: list[dict], contests_cache: dict,
                             skip_existing: bool = True):
    """Main async loop: fetch all source codes using browser."""
    metadata, existing_keys = load_metadata() if skip_existing else ([], set())
    metadata_dict = {(m['contestId'], m['index']): m for m in metadata}

    to_fetch = []
    skipped = 0
    for sub in submissions:
        problem = sub['problem']
        key = (problem['contestId'], problem['index'])
        filepath = get_filepath(sub)
        if skip_existing and key in existing_keys and filepath.exists():
            skipped += 1
        else:
            to_fetch.append(sub)

    total = len(to_fetch)
    print(f"\n[*] {total} to fetch, {skipped} already done")

    if total == 0:
        print("[+] Nothing to fetch!")
        save_metadata(list(metadata_dict.values()))
        return list(metadata_dict.values())

    browser, page = await setup_browser()
    cur_page = await browser.get('https://codeforces.com')
    await asyncio.sleep(3)

    body = await cur_page.evaluate('document.body.innerText')
    if 'Kairm_Zaf' not in body:
        print("[!] WARNING: Not logged in!")
    else:
        print("[+] Logged in as Kairm_Zaf")

    fetched = 0
    ajax_fails_in_row = 0
    failed = []

    for i, sub in enumerate(to_fetch, 1):
        problem = sub['problem']
        contest_id = problem['contestId']
        index = problem['index']
        name = problem.get('name', 'Unknown')
        is_gym = contest_id >= 100000
        category = classify(contest_id)
        filepath = get_filepath(sub)

        print(f"[{i}/{total}] {contest_id}{index} - {name} ({category})",
              end='', flush=True)

        # Refresh session every 40 problems or after 2 consecutive failures
        if (i > 1 and i % 40 == 0) or ajax_fails_in_row >= 2:
            print(" [refreshing]", end='', flush=True)
            cur_page = await refresh_session(browser)
            ajax_fails_in_row = 0
            await asyncio.sleep(1)

        # Try AJAX first
        source = await get_source_via_ajax(cur_page, sub['id'])

        if source is None:
            ajax_fails_in_row += 1
            # Immediate refresh + retry AJAX once
            cur_page = await refresh_session(browser)
            await asyncio.sleep(1)
            source = await get_source_via_ajax(cur_page, sub['id'])

        if source is None:
            # Fallback: navigate to submission page
            prefix = "gym" if is_gym else "contest"
            url = f"{CF_URL}/{prefix}/{contest_id}/submission/{sub['id']}"
            try:
                nav_page = await browser.get(url)
                await asyncio.sleep(DELAY + 2)
                code = await nav_page.evaluate("""
                    (() => {
                        let el = document.getElementById("program-source-text");
                        return el ? el.innerText : null;
                    })()
                """)
                if code:
                    source = code
                cur_page = await browser.get('https://codeforces.com')
                await asyncio.sleep(1)
            except Exception as e:
                print(f" [nav err]", end='', flush=True)
        else:
            ajax_fails_in_row = 0

        if source is None:
            print(" -> FAILED")
            failed.append({
                'contestId': contest_id, 'index': index,
                'name': name, 'submissionId': sub['id']
            })
            continue

        filepath.parent.mkdir(parents=True, exist_ok=True)
        filepath.write_text(source, encoding='utf-8')
        fetched += 1
        print(f" -> OK")

        rating = problem.get('rating')
        tags = problem.get('tags', [])
        contest_name = contests_cache.get(contest_id, '')
        problem_url = (f"https://codeforces.com/"
                       f"{'gym' if is_gym else 'contest'}/"
                       f"{contest_id}/problem/{index}")

        metadata_dict[(contest_id, index)] = {
            'contestId': contest_id,
            'contestName': contest_name,
            'index': index,
            'name': name,
            'rating': rating,
            'tags': tags,
            'category': category,
            'file': str(filepath.relative_to(REPO_ROOT)),
            'submissionId': sub['id'],
            'language': sub['programmingLanguage'],
            'url': problem_url,
            'creationTime': sub.get('creationTimeSeconds', 0),
            'participantType': sub['author']['participantType']
        }

        if fetched % 20 == 0:
            save_metadata(list(metadata_dict.values()))
            print(f"    [*] Progress saved ({fetched} fetched)")

        await asyncio.sleep(DELAY * 0.3)

    final_metadata = list(metadata_dict.values())
    save_metadata(final_metadata)
    browser.stop()

    print(f"\n{'='*50}")
    print(f"[+] Done! Fetched: {fetched}, Skipped: {skipped}, "
          f"Failed: {len(failed)}")

    if failed:
        failed_file = REPO_ROOT / 'scripts' / 'failed.json'
        with open(failed_file, 'w') as f:
            json.dump(failed, f, indent=2)
        print(f"[!] Failed: {failed_file}")

    return final_metadata


# ── README generation ───────────────────────────────────────────────────

def generate_readme(metadata: list[dict] = None):
    if metadata is None:
        meta_file = REPO_ROOT / 'problems.json'
        if meta_file.exists():
            with open(meta_file) as f:
                metadata = json.load(f)
        else:
            print("[!] No problems.json found")
            return

    problems = metadata
    if not problems:
        print("[!] No problems to generate README from")
        return

    total = len(problems)
    contest_count = sum(1 for p in problems if p['category'] == 'Contests')
    gym_count = sum(1 for p in problems if p['category'] == 'GYM')

    rating_dist = defaultdict(int)
    for p in problems:
        if p.get('rating'):
            rating_dist[p['rating']] += 1

    tag_dist = defaultdict(int)
    for p in problems:
        for tag in p.get('tags', []):
            tag_dist[tag] += 1

    lines = []
    lines.append("# Competitive Programming Solutions\n")
    lines.append("My accepted solutions for competitive programming "
                  "problems, primarily from "
                  "[Codeforces](https://codeforces.com/profile/Kairm_Zaf).\n")
    lines.append(f"**Handle:** "
                  f"[Kairm_Zaf](https://codeforces.com/profile/Kairm_Zaf)  ")
    lines.append(f"**Total Problems Solved:** {total}  ")
    lines.append(f"**Contest Problems:** {contest_count}  ")
    lines.append(f"**GYM Problems:** {gym_count}  ")
    lines.append(f"**Last Updated:** "
                  f"{datetime.now().strftime('%Y-%m-%d')}\n")

    # Rating distribution
    lines.append("## Rating Distribution\n")
    lines.append("| Rating | Count | Bar |")
    lines.append("|--------|-------|-----|")
    max_count = max(rating_dist.values()) if rating_dist else 1
    for rating in sorted(rating_dist.keys()):
        count = rating_dist[rating]
        bar_len = int(count / max_count * 20)
        bar = '█' * bar_len
        lines.append(f"| {rating} | {count} | {bar} |")
    lines.append("")

    # Tags
    lines.append("## Topics\n")
    sorted_tags = sorted(tag_dist.items(), key=lambda x: -x[1])
    tag_badges = [f"`{tag}` ({count})" for tag, count in sorted_tags]
    lines.append(" · ".join(tag_badges))
    lines.append("")

    # By rating
    lines.append("## Problems by Rating\n")
    by_rating = defaultdict(list)
    for p in problems:
        r = p.get('rating') or 'Unrated'
        by_rating[r].append(p)

    for rating in sorted(by_rating.keys(),
                          key=lambda x: x if isinstance(x, int) else 99999):
        probs = sorted(by_rating[rating],
                       key=lambda p: (p['contestId'], p['index']))
        lines.append(f"<details>")
        lines.append(f"<summary><b>Rating {rating}</b> "
                      f"({len(probs)} problems)</summary>\n")
        lines.append("| # | Problem | Tags | Solution |")
        lines.append("|---|---------|------|----------|")
        for p in probs:
            tags_str = ', '.join(p.get('tags', []))
            prob_link = (f"[{p['contestId']}{p['index']} - {p['name']}]"
                          f"({p['url']})")
            sol_link = f"[Solution]({p['file']})"
            lines.append(f"| {p['contestId']}{p['index']} | "
                          f"{prob_link} | {tags_str} | {sol_link} |")
        lines.append("\n</details>\n")

    # By contest
    lines.append("## Problems by Contest\n")
    by_contest = defaultdict(list)
    for p in problems:
        by_contest[p['contestId']].append(p)

    for cid in sorted(by_contest.keys()):
        probs = sorted(by_contest[cid], key=lambda p: p['index'])
        contest_name = probs[0].get('contestName') or f'Contest {cid}'
        category = probs[0]['category']
        lines.append(f"<details>")
        lines.append(f"<summary><b>{contest_name}</b> [{category}] "
                      f"({len(probs)} problems)</summary>\n")
        lines.append("| Problem | Rating | Tags | Solution |")
        lines.append("|---------|--------|------|----------|")
        for p in probs:
            tags_str = ', '.join(p.get('tags', []))
            rating_str = str(p['rating']) if p.get('rating') else '-'
            prob_link = f"[{p['index']}. {p['name']}]({p['url']})"
            sol_link = f"[Solution]({p['file']})"
            lines.append(f"| {prob_link} | {rating_str} | "
                          f"{tags_str} | {sol_link} |")
        lines.append("\n</details>\n")

    # Templates + footer
    lines.append("## Templates\n")
    lines.append("Reusable algorithm and data structure templates "
                  "in `Templates/`.\n")
    lines.append("---\n")
    lines.append("*Auto-generated by "
                  "[fetch_codeforces.py](scripts/fetch_codeforces.py)*")

    readme_path = REPO_ROOT / 'README.md'
    readme_path.write_text('\n'.join(lines), encoding='utf-8')
    print(f"[+] README.md generated ({total} problems indexed)")


# ── Main ────────────────────────────────────────────────────────────────

def main():
    global DELAY

    parser = argparse.ArgumentParser(
        description='Fetch Codeforces solutions and organize them')
    parser.add_argument('--handle', default='Kairm_Zaf')
    parser.add_argument('--no-skip', action='store_true',
                        help='Re-fetch all solutions')
    parser.add_argument('--readme-only', action='store_true',
                        help='Only regenerate README')
    parser.add_argument('--delay', type=float, default=DELAY,
                        help=f'Delay between requests (default: {DELAY}s)')
    args = parser.parse_args()

    DELAY = args.delay

    if args.readme_only:
        generate_readme()
        return

    contests_cache = fetch_contest_names()
    submissions = fetch_submissions(args.handle)

    metadata = asyncio.run(
        fetch_all_sources(submissions, contests_cache,
                          skip_existing=not args.no_skip)
    )
    generate_readme(metadata)


if __name__ == '__main__':
    main()
