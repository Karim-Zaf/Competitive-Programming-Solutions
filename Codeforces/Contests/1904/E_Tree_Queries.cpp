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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e9 + 10;

vector<int> graph[N];
vector<pair<int, vector<int>>> queries[N];
vector<int> ans(N);

int n, q;

/*----------------------------------------Lazy--------------------------------------------*/
// check mbaad l size mtaa l N
int Tree[4 * N], a[N];
int lazy[4 * N];
int upd[4 * N];

int merge(int a, int b){ return max(a, b); }

void unlazy(int id,int ns,int ne){
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id] +=  lazy[id];
    lazy[l] += lazy[id], lazy[r] += lazy[id];
    upd[l] = upd[r] = 1, upd[id] = lazy[id] = 0;
}

void update(int qs, int qe, int val, int ns = 1, int ne = n, int id = 0){
    unlazy(id, ns, ne);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe){
        lazy[id] += val, upd[id] = 1;
        unlazy(id, ns, ne);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

int query(int qs, int qe, int ns = 1, int ne = n, int id = 0){
    unlazy(id, ns, ne);
    if (qs > ne || qe < ns) return -1e18;
    if (qs <= ns && ne <= qe)return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}

/*-------------------LCA------------*/
vector<int> depth(N);
int up[N][30];

void dfs(int parent){
    for (int i = 1; i < 28; i++)
        up[parent][i] = up[up[parent][i - 1]][i - 1];

    for (auto child : graph[parent]){
        if (up[parent][0] == child)continue;
        depth[child] = depth[parent] + 1;
        up[child][0] = parent;
        dfs(child);
    }
}

int Binary_Lifting(int a, int k){
    for (int i = 28; i >= 0; i--)
        if (k & (1 << i))
            a = up[a][i];
    return a;
}

int Lca(int a, int b){
    if (depth[b] > depth[a]) swap(a, b);

    int k = depth[a] - depth[b];
    a = Binary_Lifting(a, k);
    if (a == b) return a;

    for (int i = 28; i >= 0; i--){
        if (up[a][i] == up[b][i]) continue;
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}

/*---------------------------------------EulerTour----------------------------------------------*/
int timer = 0, tin[N], tout[N];

void Euler_Tour(int curr, int parent = -1){
    tin[curr] = ++timer;
    for (auto child : graph[curr])
        if (child != parent)
            Euler_Tour(child, curr);
    tout[curr] = timer;
}

/*--------------*/
void dfs_ans(int curr, int parent = -1){
    for (auto child : graph[curr]){
        if (child == parent) continue;
        update(0, n + 1, 1);
        update(tin[child], tout[child], -2);
        dfs_ans(child, curr);
        update(0, n + 1, -1);
        update(tin[child], tout[child], 2);
    }

    for (auto [i,nodes] : queries[curr]){
        // add
        for (auto node : nodes){
            if (Lca(curr, node) == curr){ update(tin[node], tout[node], -INF); }
            else if (Lca(curr, node) == node){
                int dist = depth[curr] - depth[node];
                int intermediaire = Binary_Lifting(curr, dist - 1);

                update(0, n + 1, -INF);
                update(tin[intermediaire], tout[intermediaire], INF);
            }
            else{ update(tin[node], tout[node], -INF); }
        }

        // ehseb
        ans[i] = query(1, n );

        // fasekh
        for (auto node : nodes){
            if (Lca(curr, node) == curr){ update(tin[node],  tout[node], INF); }
            else if (Lca(curr, node) == node){
                int dist = depth[curr] - depth[node];
                int intermediaire = Binary_Lifting(curr, dist - 1);

                update(0, n + 1, INF);
                update(tin[intermediaire], tout[intermediaire], -INF);
            }
            else{ update(tin[node], tout[node], INF); }
        }
    }
}

void Solve(){
    cin >> n >> q;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for (int i = 1; i <= q; i++){
        int x, k;
        cin >> x >> k;
        vector<int> nodes(k);
        for (auto& x : nodes) cin >> x;
        queries[x].push_back({i, nodes});
    }

    Euler_Tour(1);
    dfs(1);
    for (int i = 1; i <= n; i++) update(tin[i], tin[i], depth[i]);
    dfs_ans(1);

    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
