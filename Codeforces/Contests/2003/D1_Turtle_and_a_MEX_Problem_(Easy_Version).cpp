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
    int n, m, mx = 0;
    cin >> n >> m;

    vector<pair<int,int>> vp(n, {-1, -1});
    map<int, vector<int>> graph;

    for (int i = 0; i < n; i++) {
        int sz;

        cin >> sz;

        mx = max(mx, sz + 5);
        vector<int> v(sz), vis(sz + 3);

        for (auto& x : v) cin >> x;
        for (auto x : v) if (x <= sz + 2) vis[x] = 1;

        for (int j = 0; j <= sz + 2; j++) {
            if (!vis[j]) {
                if (vp[i].F == -1) vp[i].F = j;
                else if (vp[i].S == -1) vp[i].S = j;
            }
        }


    }

    kar(vp);
    for (auto [u,v] : vp) {
        graph[u].pb(v);
    }
    vector<int> dp(mx + 5, -1);

    function<int(int)> work = [&](int x) {
        int& ret = dp[x];
        if (ret != -1) return ret;
        ret = x;
        for (auto child : graph[x]) {
            ret = max(ret, work(child));
        }

        return ret;
    };


    int mx_ans = -1;
    for (auto [u, v] : vp) {
        mx_ans = max(mx_ans, work(u));
    }

    for (int i = 0; i <= min(mx, m); i++) work(i);
    for (auto& x : dp) x = max(x, mx_ans);
    int ans = 0;
    for (int i = 0; i <= min(mx, m); i++) {
        ans += work(i);
    }
    if (m > mx) {
        ans += m * (m + 1) / 2 - (mx) * (mx + 1) / 2;
    }
    cout << ans << endl;
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
