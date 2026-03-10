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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

/*----------------------------------------Lazy--------------------------------------------*/

int Tree[4 * N], a[N];
int lazy[4 * N], n;
int upd[4 * N];

int merge(int a, int b) { return a + b; }

void unlazy(int id) {
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id] += lazy[id];
    lazy[l] += lazy[id], lazy[r] += lazy[id];
    upd[l] = upd[r] = 1, upd[id] = lazy[id] = 0;
}

void build(int ns = 1, int ne = n, int id = 0) {
    if (ns == ne) {
        Tree[id] = a[ns];
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l);
    build(md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

void update(int qs, int qe, int val, int ns = 1, int ne = n, int id = 0) {
    unlazy(id);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe) {
        lazy[id] += val, upd[id] = 1;
        unlazy(id);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

int query(int qs, int qe, int ns = 1, int ne = n, int id = 0) {
    unlazy(id);
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe) return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}


void print() {
    for (int i = 1; i <= n; i++) cout << query(i, i) << " ";
    cout << endl;
}

/*----------------------------------------*/
vector<int> graph[N], depth(N);
int up[N][30];

void dfs(int parent) {
    for (int i = 1; i < 28; i++) up[parent][i] = up[up[parent][i - 1]][i - 1];

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

/*---------------------------------------EulerTour----------------------------------------------*/
int timer = 0, tin[N], tout[N];

void Euler_Tour(int curr, int parent = -1) {
    tin[curr] = ++timer;
    for (auto child : graph[curr]) if (child != parent) Euler_Tour(child, curr);
    tout[curr] = timer;
}

void init() {
    for (int i = 0; i <= n; i++) {
        graph[i].clear();
        for (int j = 0; j < 30; j++) up[i][j] = 0;
        depth[i] = 0;
    }
    for (int i = 0; i <= timer + 5; i++) {
        tin[i] = tout[i] = 0;
        update(i, i, -query(i, i));
    }
    timer = 0;
}

void Solve() {
    int q;
    cin >> n >> q;
    vector<int> ans(q);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);
    Euler_Tour(1);

    set<int> values;
    map<int, vector<array<int, 4>>> queries;
    map<int, vector<int>> nodes;
    for (int i = 1; i <= n; i++) {
        nodes[a[i]].pb(i);
        values.insert(a[i]);
    }

    for (int i = 0; i < q; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        values.insert(k);

        queries[k].pb({u, v, k, i});
    }
    kar(values);
    for (auto x : values) {
        for (auto Node : nodes[x]) {
            update(tin[Node], tout[Node], 1);
        }
        for (auto [u,v,k,index] : queries[x]) {
            int lc = Lca(u, v);
            ans[index] = depth[u] + depth[v] - 2 * depth[lc] + 1;
            int cnt = query(tin[u], tin[u]) + query(tin[v], tin[v]);

            cnt -= 2 * query(tin[lc], tin[lc]);
            cnt += (a[lc] <= k);
            ans[index] -= cnt;
        }
    }

    for (auto x : ans) cout << x << endl;
    init();
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
