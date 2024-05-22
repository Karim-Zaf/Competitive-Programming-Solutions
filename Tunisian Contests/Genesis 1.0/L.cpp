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
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1), graph[n + 1];

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    function<vector<int>(int, int)> dfs = [&](int curr, int parent) -> vector<int> {

        vector<vector<int>> vect;
        vector<int> ret;

        for (auto child: graph[curr]) {
            if (child == parent) continue;
            vect.pb(dfs(child, curr));
            for (auto x: vect.back()) ret.pb(x);
        }

        if (vect.size() == 2) {
            int one = 0, two = 0;
            for (auto z: vect[0])one += lower_bound(all(vect[1]), z) - vect[1].begin();
            for (auto z: vect[1])two += lower_bound(all(vect[0]), z) - vect[0].begin();
            ans += max(one, two);
        }

        sort (all(ret));
        ans += lower_bound(all(ret), a[curr]) - ret.begin();
        
        ret.pb(a[curr]);

        sort(all(ret));
        return ret;
    };

    dfs(1, -1);
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
