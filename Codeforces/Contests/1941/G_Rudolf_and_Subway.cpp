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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

vector<int> graph[N], related[N];
set<int> colors[N], cols;
int vis[N], dist[N], ans[N];
int n, m, e, b;


void bfs(int parent) {
    queue<int> q;
    q.push(parent);
    dist[parent] = 0;
    while (!q.empty()) {
        parent = q.front();

        q.pop();
        for (auto c: colors[parent]) {
            if (!ans[c])continue;
            dist[parent] = min(dist[parent], ans[c]);
        }
        for (auto c: colors[parent]) {
            ans[c] = min(ans[c], dist[parent] + 1);
            if (ans[c] == INF)continue;
            for (auto child: related[c]) {
                if (vis[child] || child == parent)continue;
                colors[child].erase(c);
                dist[child] = min(dist[child], ans[c]);
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}

void (init()) {
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        colors[i].clear();
        vis[i] = 0;
        dist[i] = INF;
    }
    for (auto c: cols) {
        ans[c] = INF;
        related[c].clear();
    }
    cols.clear();
}

void Solve() {
    cin >> n >> m;
    init();
    for (int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        graph[u].pb(v);
        graph[v].pb(u);
        colors[u].insert(c);
        colors[v].insert(c);
        related[c].pb(v);
        related[c].pb(u);
        cols.insert(c);
    }
    cin >> e >> b;
    if (e == b) {
        cout << 0 << endl;
        return;
    }
    set<int> colsb = colors[b];
    bfs(e);
    int res = INF;
    for (auto c: colsb)res = min(res, ans[c]);
    cout << res << endl;
    init();
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    for (int i = 0; i < N; i++) ans[i] = INF;
    while (Test_case--) Solve();
}