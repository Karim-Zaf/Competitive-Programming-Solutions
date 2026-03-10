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
    int n, x;
    cin >> n >> x;
    vector<int> v(n + 1), pref(n + 1), ans(n + 2);
    vector<pair<int,int>> vp;

    set<int> s{0, n + 1};
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) vp.pb({v[i], i});
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];

    sort(rall(vp));
    ans[vp[0].S] = 1;
    for (auto& [x , pos] : vp) {
        auto it = s.lower_bound(pos);
        int r = *it, l = *prev(it);

        if (pref[r - 1] - pref[l] >= v[l]) ans[pos] |= ans[l];
        if (pref[r - 1] - pref[l] >= v[r]) ans[pos] |= ans[r];

        s.insert(pos);
    }

    cout << accumulate(all(ans), 0ll) << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
