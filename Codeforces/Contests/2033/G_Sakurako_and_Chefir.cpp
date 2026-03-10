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


/*----------------------------------------Lazy--------------------------------------------*/

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
    if (qs > ne || qe < ns) return -INF;
    if (qs <= ns && ne <= qe) return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}


void print() {
    for (int i = 1; i <= n; i++) cout << query(i, i) << " ";
    cout << endl;
}

/*---------------------------------------EulerTour----------------------------------------------*/
int timer = 0, tin[N], tout[N];

void Euler_Tour(int curr, int parent = -1) {
    tin[curr] = ++timer;
    for (auto child : graph[curr]) if (child != parent) Euler_Tour(child, curr);
    tout[curr] = timer;
    update(tin[curr], tin[curr], -query(tin[curr], tin[curr]));
    update(tin[curr], tin[curr], depth[curr]);
}

/*-------------------------------------------------------------------------------------*/
vector<array<int, 2>> queries[N];
vector<int> ans(N);

void prep() {
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        queries[i].clear();

    }
    timer = 0;
}


void work(int curr, int parent = -1) {


    for (auto child : graph[curr]) {
        if (child == parent) continue;
        update(tin[child], tout[child], -1);
        update(0, tin[child] - 1, 1);
        update(tout[child] + 1, timer + 2, 1);

        work(child, curr);

        update(tin[child], tout[child], 1);
        update(0, tin[child] - 1, -1);
        update(tout[child] + 1, timer + 2, -1);

    }

    int mx = query(tin[curr], tout[curr]);

    for (auto [k , indx] : queries[curr]) {
        int par = Binary_Lifting(curr, k);
        if (par == 0) par = 1;
        ans[indx] = mx;

        update(tin[curr], tout[curr], -1e7);
        ans[indx] = max(ans[indx], query(tin[par], tout[par]));
        update(tin[curr], tout[curr], 1e7);

    }


}

void Solve() {
    cin >> n;

    prep();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    dfs(1);

    Euler_Tour(1);
    int q;
    cin >> q;

    for (int i = 1; i <= q; i++) {
        int u, k;
        cin >> u >> k;
        queries[u].pb({k, i});
    }


    work(1);

    for (int i = 1; i <= q; i++) cout << ans[i] << " ";
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
