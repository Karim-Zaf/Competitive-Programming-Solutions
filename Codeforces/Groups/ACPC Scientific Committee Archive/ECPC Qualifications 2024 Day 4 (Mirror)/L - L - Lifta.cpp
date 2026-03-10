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

const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;

template <class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;
    ll n;
    vector<T> seg;
    T comb(T a, T b) { return (a ^ b); }

    void init(ll _n) {
        n = _n;
        seg.assign(2 * n, ID);
    }

    void pull(ll p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }

    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(ll l, ll r) { // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};

vector<pair<int, int>> paths[N_Max], qry[N_Max];
vector<int> adj[N_Max];
int up[N_Max][LOG];
int bchild[N_Max];
int depth[N_Max];
int tour[N_Max];
int tout[N_Max];
int tin[N_Max];
int ans[N_Max];
int sz[N_Max];
Seg<int> st;
int N, M, Q;
int timer;

void init() {
    timer = 0;
    st.init(N + 5);
    for (int i = 1; i <= N; i++) {
        adj[i].clear();
        qry[i].clear();
        paths[i].clear();
    }
}

void dfs_init(int Node, int par) {
    up[Node][0] = par;
    for (int i = 1; i < LOG; i++) up[Node][i] = up[up[Node][i - 1]][i - 1];
    tour[++timer] = Node;
    tin[Node] = timer;
    bchild[Node] = -1;
    sz[Node] = 1;
    for (int child : adj[Node]) {
        if (child == par) continue;
        depth[child] = depth[Node] + 1;
        dfs_init(child, Node);
        sz[Node] += sz[child];
        if (bchild[Node] == -1 || sz[child] > sz[bchild[Node]]) bchild[Node] = child;
    }
    tout[Node] = timer;
}

int get_kth(int u, int K) {
    for (int i = LOG - 1; i >= 0; i--) if (K & (1 << i)) u = up[u][i];
    return u;
}

int get_lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    v = get_kth(v, depth[v] - depth[u]);
    assert(depth[u] == depth[v]);
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return (u == v ? u : up[u][0]);
}

void dfs(int Node, int par, bool keep) {
    for (int child : adj[Node]) {
        if (child == par || child == bchild[Node]) continue;
        dfs(child, Node, false);
    }
    if (bchild[Node] != -1) dfs(bchild[Node], Node, true);
    for (int child : adj[Node]) {
        if (child == par || child == bchild[Node]) continue;
        for (int i = tin[child]; i <= tout[child]; i++) {
            int u = tour[i];
            for (auto [v, p] : paths[u]) st.upd(tin[v], (st.query(tin[v], tin[v]) ^ p));
        }
    }
    for (auto [v, p] : paths[Node]) st.upd(tin[v], (st.query(tin[v], tin[v]) ^ p));


    int prep = 0;
    for (int child : adj[Node]) {
        if (child == par) continue;
        prep ^= st.query(tin[child], tout[child]);
    }

    for (auto [u, id] : qry[Node]) {
        int lca = get_lca(Node, u);
        if (lca == u) {
            int tot = st.query(1, N);
            int dist = depth[Node] - depth[lca];
            int new_node = get_kth(Node, dist - 1);
            if (u == Node) {
                ans[id] = tot;
                ans[id] ^= prep;
            } else ans[id] = (tot ^ st.query(tin[new_node], tout[new_node]));
        } else ans[id] = st.query(tin[u], tout[u]);
    }
    if (keep) return;
    for (int i = tin[Node]; i <= tout[Node]; i++) {
        int u = tour[i];
        for (auto [v, p] : paths[u]) st.upd(tin[v], (st.query(tin[v], tin[v]) ^ p));
    }
}

void Solve() {
    cin >> N >> M >> Q;
    init();
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs_init(1, 0);
    for (int i = 1; i <= M; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        int lc = get_lca(u, v);
        if (tin[u] > tin[v]) swap(u, v);
        if (lc != u) paths[lc].push_back({lc, p});
        paths[u].push_back({v, p});
        paths[v].push_back({u, p});
    }
    for (int q = 1; q <= Q; q++) {
        int u, v;
        cin >> u >> v;
        if (tin[u] > tin[v]) swap(u, v);
        int p = get_lca(u, v);
        if (p != u && p != v) qry[u].push_back({v, q});
        else if (p != u) qry[u].push_back({v, q});
        else qry[v].push_back({u, q});
    }
    dfs(1, 0, false);
    for (int i = 1; i <= Q; i++) cout << ans[i] << " ";
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
