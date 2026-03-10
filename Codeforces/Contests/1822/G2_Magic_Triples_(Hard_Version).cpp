/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
#ifndef ONLINE_JUDGE

#include "debug.cpp"

#else
#define kar(...)
#endif
#define pb push_back
#define all(x) x.begin(),x.end()

const int N = 3e5 + 30, mod = 1e9 + 7;


vector<int> primes;

void sieve() {
    vector<int> visited(N);
    for (int i = 2; i < N; i++) {
        if (visited[i]) continue;
        primes.push_back(i);
        for (int j = i; j < N; j += i)
            visited[j] = 1;
    }
}

void Solve() {
    int n;
    ll ans = 0;
    cin >> n;
    map<int, int> mp;
    vector<int> v;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (!mp[x])v.pb(x);
        mp[x]++;
    }

    for (auto x: v) {
        int occ = mp[x], xx = x;


        vector<int> div{1};
        for (auto &prime: primes) {
            if (prime * prime > x) break;
            if (x % prime) continue;
            int cnt = 0, curr = 1;
            vector<int> nw_div, prd;
            int p = prime * prime;
            while (x % p == 0) {
                cnt++;
                curr *= prime;
                prd.pb(curr);
                x /= p;
            }
            while (x % prime == 0) x /= prime;

            if (prd.empty()) continue;

            for (auto &d: div) {
                for (auto &curr: prd)
                    nw_div.pb(d * curr);
            }
            for (auto &d: nw_div) {
                div.pb(d);
                ans += 1ll * occ * mp[xx / d] * mp[xx / d / d];
            }
        }

        ans += 1ll * occ * (occ - 1) * (occ - 2);
    }

    cout << ans << '\n';
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    sieve();
    while (Test_case--) Solve();
}