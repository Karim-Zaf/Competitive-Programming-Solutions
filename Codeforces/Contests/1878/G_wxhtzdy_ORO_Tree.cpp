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
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

const int LG = 30;

vector<int> graph[N], depth(N), a(N);
int up[N][30];
int nearest[LG][N];
int pref[LG][N];


bool bit(int x, int b) {
    return ((1 << b) & x) != 0;
}

void dfs(int parent) {
    for (int i = 1; i < 28; i++) up[parent][i] = up[up[parent][i - 1]][i - 1];
    for (int b = 0; b < LG; b++) {
        if (bit(a[parent], b)) nearest[b][parent] = parent;
        else nearest[b][parent] = nearest[b][up[parent][0]];

    }

    for (int b = 0; b < LG; b++) {
        pref[b][parent] = bit(a[parent], b) + pref[b][up[parent][0]];
    }

    for (auto child : graph[parent]) {
        if (up[parent][0] == child) continue;
        depth[child] = depth[parent] + 1;
        up[child][0] = parent;
        dfs(child);
    }
}


int Binary_Lifting(int a, int k) {
    for (int i = 28; i >= 0; i--) if (k & (1 << i)) a = up[a][i];
    return a;
}

int Lca(int a, int b) {
    if (depth[b] > depth[a]) swap(a, b);

    int k = depth[a] - depth[b];
    a = Binary_Lifting(a, k);
    if (a == b) return a;

    for (int i = 28; i >= 0; i--) {
        if (up[a][i] == up[b][i]) continue;
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[Lca(u, v)];
}


int get(int u, int v,int lc, int bit) {
    int cnt = pref[bit][u] + pref[bit][v] - 2 * pref[bit][up[lc][0]];
    return cnt;
}


int work(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int lc = Lca(u, v), ret = 0;


    for (int b = 0; b < LG; b++) {
        int z = nearest[b][u];
        if (depth[z] < depth[lc] || !z) continue ;
        int pot = 0;
        for (int j = 0; j < LG; j++) {
            int one = get(u, z, z, j) != 0;
            int two = get(v, z, lc, j) != 0;
            pot += one + two;
        }
        ret = max(ret, pot);
    }


    for (int b = 0; b < LG; b++) {
        int z = nearest[b][v];
        if (depth[z] < depth[lc] || !z) continue ;
        int pot = 0;
        for (int j = 0; j < LG; j++) {
            int one = get(u, z, lc, j) != 0;
            int two = get(v, z, z, j) != 0;
            pot += one + two;
        }
        ret = max(ret, pot);
    }

    return ret;
}

int n, q;

void init() {

    for (int i = 0; i <= n; i++) {
        graph[i].clear();
    }
}


void Solve() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);

    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << work(u, v) << " ";
    }
    cout << endl;
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
