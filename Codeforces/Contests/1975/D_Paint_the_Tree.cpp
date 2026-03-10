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

/*----------------------------------lazy-------------------------------------*/

int Tree[4 * N], a[N];
int lazy[4 * N], n;
int upd[4 * N];

int merge(int a, int b) { return max(a, b); }

void unlazy(int id) {
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id] += lazy[id];
    lazy[l] += lazy[id], lazy[r] += lazy[id];
    upd[l] = upd[r] = 1, upd[id] = lazy[id] = 0;
}

void build(int ns = 1, int ne = n, int id = 0) {
    lazy[id] = upd[id] = 0;
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
    if (qs <= ns && ne <= qe)return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}

/*----------------------------------LCa-------------------------------------*/

vector<int> graph[N], depth(N);
int up[N][30];

void dfs(int parent) {
    for (int i = 1; i < 28; i++)
        up[parent][i] = up[up[parent][i - 1]][i - 1];

    for (auto child: graph[parent]) {
        if (up[parent][0] == child)continue;
        depth[child] = depth[parent] + 1;
        up[child][0] = parent;
        dfs(child);
    }
}

int Binary_Lifting(int a, int k) {
    for (int i = 28; i >= 0; i--)
        if (k & (1 << i))
            a = up[a][i];
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

int dist(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[Lca(a, b)];
}

/*----------------------------------euler-------------------------------------*/
int timer = 0, start[N], endd[N];

void Euler_Tour(int curr, int parent) {
    kar (start[curr]);
    start[curr] = ++timer;
    for (auto child: graph[curr])
        if (child != parent)
            Euler_Tour(child, curr);
    endd[curr] = timer;
}


/*----------------------------------solution-------------------------------------*/

int aa, bb, ans;

void dfs_rasmi(int curr, int parent = -1) {

    if (curr != 1) {

        update(start[curr], endd[curr], -1);
        update(0, start[curr] - 1, 1);
        update(endd[curr] + 1, n, 1);
    }


    for (auto child: graph[curr]) {
        if (child == parent)continue;
        dfs_rasmi(child, curr);
    }

    int dist_a = dist(curr, aa), dist_b = dist(curr, bb);

    int res = max(dist_a, dist_b);
    if (dist_b < dist_a && dist_a % 2 != dist_b % 2)res++;
    res += 2 * (n - 1);

    res -= query(0, n);
    ans = min(ans, res);


    if (curr != 1) {
        update(start[curr], endd[curr], 1);
        update(0, start[curr] - 1, -1);
        update(endd[curr] + 1, n, -1);
    }
}


void init() {
    ans = INF;
    timer = 0;
    for (int i = 0; i < n + 3; i++) {
        graph[i].clear();
        start[i] = endd[i] = depth[i] = 0;
        for (int j = 0; j < 30; j++) up[i][j] = 0;

        int q = query(i, i);
        update(i, i, -q);
    }

}

void Solve() {
    // if b reaches one visited node by a it will reproduce the same process
    // we fix node u
    // we calculate the required for b to reach and a to reach and we take the maximum
    // we calculate the answer to dfs all the tree it's 2*(n-1) - longest paht from this node to any other
    // let's implement


    cin >> n >> aa >> bb;
    init();

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    Euler_Tour(1, -1);
    dfs(1);

    for (int i = 1; i <= n; i++) {
        a[start[i]] = dist(1, i) ;
    }
    build();
    dfs_rasmi(1);

    cout << ans << endl;
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