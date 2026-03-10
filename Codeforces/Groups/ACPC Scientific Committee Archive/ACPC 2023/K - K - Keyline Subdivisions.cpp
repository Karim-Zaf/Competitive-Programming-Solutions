/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'

int const N = 2e6 + 10;

vector<int> graph[N], sz(N, 1), par(N);

void dfs(int curr, int parent = 0) {
    par[curr] = parent;
    for (auto child : graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
        sz[curr] += sz[child];
    }
}


void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> spec(k), ans;

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (auto& x : spec) cin >> x;

    dfs(1);


    set<pair<int, int>> s;

    for (auto x : spec) s.insert({sz[x], x});

    for (int d = 0; d <= n; d++) {
        while (s.begin()->first < d) {
            auto [sizi , node] = *s.begin();
            s.erase(s.begin());
            s.insert({sz[par[node]], par[node]});
        }
        if (prev(s.end())->first <= d + 1) ans.push_back(d);
    }
    for (auto x : ans) cout << x << " ";
    cout << endl;
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
