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

const int N = 2e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

vector<int> graph[N], depth(N), dp(2e6);
int up[N][30], value[N], Xor[N];
vector<int> key[30];
int n, m;

void dfs(int parent) {
    for (int i = 1; i < 22; i++)
        up[parent][i] = up[up[parent][i - 1]][i - 1];

    for (auto child: graph[parent]) {
        if (up[parent][0] == child)continue;
        depth[child] = depth[parent] + 1;
        up[child][0] = parent;
        dfs(child);
    }
}

int Binary_Lifting(int a, int k) {
    for (int i = 20; i >= 0; i--)
        if (k & (1 << i))
            a = up[a][i];
    return a;
}

int Lca(int a, int b) {
    if (depth[b] > depth[a]) swap(a, b);

    int k = depth[a] - depth[b];
    a = Binary_Lifting(a, k);
    if (a == b) return a;

    for (int i = 20; i >= 0; i--) {
        if (up[a][i] == up[b][i]) continue;
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}

void dfs2(int curr, int parent = 0) {
    for (auto child: graph[curr]) {
        if (child == parent) continue;
        dfs2(child, curr);
        value[curr] |= value[child];
    }
    value[curr] ^= Xor[curr];
    for (int i = 0; i < m; i++) {
        if ((1 << i) & value[curr])
            key[i].pb(curr);
    }
}

int work(int mask) {
    if (mask == (1 << m) - 1)return 0;
    int &ret = dp[mask];
    if (ret != -1)return ret;
    ret = INF;

    for (int i = 0; i < m; i++) {
        if (mask & (1 << i))continue;
        for (auto x: key[i]) {
            int nw_mask = mask | value[x];
            ret = min(ret, 1 + work(nw_mask));
        }
        break;
    }

    return ret;
}

void init1() {
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        value[i] = Xor[i] = 0;
    }
}

void init2() {
    for (int i = 0; i <= m; i++) key[i].clear();
    for (int i = 0; i <= (1 << m); i++) dp[i] = -1;
}

void Solve() {
    cin >> n;
    init1();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    cin >> m;
    init2();
    dfs(1);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        Xor[Lca(a, b)] |= (1 << i);
        value[a] |= (1 << i);
        value[b] |= (1 << i);
    }
    dfs2(1);

    cout << work(0) << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}