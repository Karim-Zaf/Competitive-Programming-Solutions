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

int n;
vector<int> fib(30), sz(N, 1), ok(N);
set<int> graph[N];

void dfs_init(int curr, int parent = -1) {
    sz[curr] = 1;
    for (auto child : graph[curr]) {
        if (child == parent) continue;
        dfs_init(child, curr);
        sz[curr] += sz[child];
    }
}

bool dfs(int curr, int parent = -1, int sz_tree = n) {
    if (sz_tree == 1) return true;
    bool ans = false;

    vector<int> act(all(graph[curr]));

    for (auto child : act) {
        if (child == parent) continue;
        int sz_child = sz[child];
        if (!ok[sz_child] || !ok[sz_tree - sz_child]) {
            ans |= dfs(child, curr, sz_tree);
            continue ;
        }


        graph[curr].erase(child);
        graph[child].erase(curr);
        // we cut the edge
        dfs_init(child, -1), dfs_init(curr, -1);

        ans |= dfs(child, -1, sz_child) & dfs(curr, -1, sz_tree - sz_child);

        if (ans) return true;
        graph[curr].insert(child);
        graph[child].insert(curr);
    }
    return ans;
}

void Solve() {


    fib[1] = fib[2] = 1;

    for (int i = 3; i < 30; i++) fib[i] = fib[i - 1] + fib[i - 2];

    for (int i = 0; i < 30; i++)
        if (fib[i] < N) {
            ok[fib[i]] = 1;
        }


    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    if (!ok[n]) return void(cout << "NO");

    dfs_init(1);
    cout << (dfs(1) ? "YES" : "NO");

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
