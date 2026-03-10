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
    // we'll make intervals of b
    // for each interval we will fix the longest increasing subsequence verifying the conditions of left and right

    int n, k, req = -INF, ans = 0;
    cin >> n >> k;
    vector<int> v(n + 3), b(k);
    vector<pair<int, int>> vp;
    v[n + 1] = INF;
    v[0] = -n - 1;

    for (int i = 1; i <= n; i++) cin >> v[i];

    for (auto &x: b) cin >> x;
    set<int> s(all(b));
    b.clear();
    for (int i = 1; i <= n; i++) {
        if (s.find(i) == s.end())b.pb(i);
    }
    s = set<int>(all(b));

    for (auto &x: b) {
        cin >> x;
        if (vp.empty()) {
            vp.pb({x, x});
            continue;
        }
        auto [l, r] = vp.back();
        if (x == r + 1) {
            vp.pop_back();
            vp.pb({l, x});
        } else vp.pb({x, x});
    }

    for (int i = 1; i <= n; i++) {
        if (s.find(i) != s.end())req++;
        else if (v[i] < req)
            return void(cout << -1 << endl);
        else
            req = v[i] + 1;
    }


    for (auto [l, r]: vp) {
        int lef = v[l - 1], righ = v[r + 1];
        if (righ - lef < r - l)return void(cout << -1 << endl);
        lef;
        righ = righ - (r - l) - 2;

        vector<int> store;
        for (int i = l; i <= r; i++) {
            lef++, righ++;
            if (v[i] > righ || v[i] < lef) continue;
            int x = v[i] - lef;
            int pos = upper_bound(all(store), x) - store.begin();
            if (pos == store.size()) store.pb(x);
            else store[pos] = x;
        }
        ans += (r - l + 1) - store.size();
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