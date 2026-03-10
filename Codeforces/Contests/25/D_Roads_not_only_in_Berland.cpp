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

vector<int> graph[N], vis(N), v;
set<pair<int, int>> vp;

void dfs(int curr, int parent = 0) {
    if (vis[curr])return;
    vis[curr] = 1;
    for (auto child: graph[curr]) {
        if (child == parent) continue;
        if (vis[child])continue;
        pair<int, int> p = {curr, child};
        if (curr > child)swap(p.F, p.S);
        if (vp.find(p) != vp.end()) vp.erase(p);
        dfs(child, curr);
    }
}

void Solve() {
    int n;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
        if (u > v) swap(u, v);
        vp.insert({u, v});
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (vis[i])continue;
        v.pb(i);
        dfs(i);
    }

    cout << vp.size() << endl;
    auto it = vp.begin();
    for (int i = 0; i < vp.size(); i++) {
        cout << it->F << " " << it->S << " " << 1 << " " << v[i] << endl;
        it++;
    }
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