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
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {
    int n, q;

    cin >> n;
    vector<int> v(n + 4), pref(n + 4), cnt(n + 3), suff(n + 3);

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) pref[i] = v[i] + pref[i - 1];


    for (int i = n; i >= 1; i--) suff[i] = suff[i + 1] + pref[i];

    for (int i = 1; i <= n; i++) cnt[1] += pref[i];
    for (int i = 2; i <= n; i++) cnt[i] = cnt[i - 1] - v[i - 1] * (n - i + 2);
    for (int i = 2; i <= n; i++) cnt[i] += cnt[i - 1];

    vector<int> curr{0};
    for (int i = 1; i <= n; i++) curr.push_back(curr.back() + n - i + 1);

    kar(curr);

    cin >> q;

    while (q--) {
        int l, r, ans = 0;
        cin >> l >> r;


        int lef = lower_bound(all(curr), l) - curr.begin();
        int right = upper_bound(all(curr), r) - curr.begin();


        if (lef == right) {
            int st = l - curr[lef - 1];
            int en = r - curr[lef - 1];

            ans += suff[lef + st - 1] - suff[lef - 1 + en + 1] - pref[lef - 1] * (en - st + 1);
            kar(suff[st] - suff[en+1]);

            cout << ans << endl;
            continue;
        }


        // isar
        int beki = curr[lef] - l + 1;
        ans += suff[n - beki + 1] - beki * pref[lef - 1];


        beki = r - curr[right - 1];
        ans += (suff[right] - suff[right + beki]) - pref[right - 1] * (beki);


        if (lef + 2 <= right) ans += cnt[right - 1] - cnt[lef];

        cout << ans << endl;
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
