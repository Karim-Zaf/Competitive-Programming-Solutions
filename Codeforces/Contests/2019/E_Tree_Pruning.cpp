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

const int N = 5e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> graph[N], depth(N), mp[N], vis(N), par(N);

void dfs(int curr, int parent = 0) {
    depth[curr] = depth[parent] + 1;

    par[curr] = parent;
    mp[depth[curr]].pb(curr);

    for (auto child : graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
    }

}

void Solve() {
    int n;
    cin >> n;


    for (int i = 1; i <= n; i++) {
        depth[i] = vis[i] = par[i] = 0;
        graph[i].clear();
        mp[i].clear();
    }
    vis[0] = 1;

    for (int i = 1, v, u; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);

    int ans = INF, cnt = 0;


    for (int dep = n; dep >= 1; dep--) {
        for (auto Node : mp[dep]) {
            int curr = Node;
            while (!vis[curr]) {
                vis[curr] = 1;
                cnt++;
                curr = par[curr];
            }
        }
        ans = min(ans, n - cnt);
        cnt -= mp[dep].size();
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
