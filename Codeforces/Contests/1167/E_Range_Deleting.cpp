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
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e9 + 10;


void Solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 2);
    ll ans = 0;

    vector<int> mp[k + 3];

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) mp[v[i]].pb(i);

    set<int> s;

    vector<int> pref_mn(k + 4, INF), pref_mx(k + 4, -INF), suff_mx;
    for (int i = 1; i <= n; i++) {
        auto it = s.upper_bound(v[i]);
        if (it != s.end()) pref_mn[v[i]] = *it;
        if (!s.empty() && *prev(s.end()) > v[i]) pref_mx[v[i]] = *prev(s.end());
        s.insert(v[i]);
    }


    suff_mx = pref_mx;

    for (int i = k; i >= 1; i--) suff_mx[i] = max(suff_mx[i], suff_mx[i + 1]);
    for (int i = 1; i <= k; i++) pref_mn[i] = min(pref_mn[i], pref_mn[i - 1]);
    for (int i = 1; i <= k; i++) pref_mx[i] = max(pref_mx[i], pref_mx[i - 1]);

    for (int x = k; x >= 1; x--) {
        int l = 1, r = x - 1, res = 0;

        while (l <= r) {
            int md = l + (r - l) / 2;
            if (pref_mn[md] <= md || pref_mx[md] > x) { // not possible
                r = md - 1;
            } else {
                res = md;
                l = md + 1;
            }
        }
        ans += res + 1;
        if (suff_mx[x] >= x)break;
    }

    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}