#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define int ll
#define pb(n) push_back(n)
#define F first
#define S second

const int mod = 1e9 + 7;
const int N_Max = 2e5 + 5, LOG = 20;
vector<pair<int, int>> adj[N_Max];
int lazy[4 * N_Max];
int up[N_Max][LOG];
int st[4 * N_Max];
int depth[N_Max];
int tour[N_Max];
int top[N_Max];
int id[N_Max];
int sz[N_Max];
int a[N_Max];
int timer = 1;
int N, Q;

int add(ll a, ll b){return (a + b) % mod;}

int mult(ll a, ll b){return a * b % mod;}

int merge(int l, int r){
    return add(l, r);
}

void build(int id, int ns, int ne){
    if (ns == ne){
        st[id] = tour[ns];
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    build(lc, ns, mid);
    build(rc, mid + 1, ne);
    st[id] = merge(st[lc], st[rc]);
}

void push_down(int id, int ns, int ne){
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;

    st[lc] = mult(st[lc], lazy[id]);
    st[rc] = mult(st[rc], lazy[id]);

    lazy[lc] = mult(lazy[lc], lazy[id]);
    lazy[rc] = mult(lazy[rc], lazy[id]);
    
    lazy[id] = 1;
}

int update(int id, int ns, int ne, int l, int r, int x){
    if (ns > r || ne < l) return 0;
    if (ns >= l && ne <= r){
        st[id] = mult(st[id], x);
        lazy[id] = mult(lazy[id], x);
        return st[id];
    }
    push_down(id, ns, ne);
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    int valL = update(lc, ns, mid, l, r, x);
    int valR = update(rc, mid + 1, ne, l, r, x);
    st[id] = merge(st[lc], st[rc]);
    return add(valL, valR);
}

void dfs_init(int Node, int par){
    up[Node][0] = par;
    for (int i = 1; i < LOG; i++)
        up[Node][i] = up[up[Node][i - 1]][i - 1];
    sz[Node] = 1;
    for (auto [child, w] : adj[Node]){
        if (child == par) continue;
        depth[child] = depth[Node] + 1;
        a[child] = w;
        dfs_init(child, Node);
        sz[Node] += sz[child];
    }
}

void HLD(int Node, int tp){
    int big = -1;
    tour[timer] = a[Node];
    id[Node] = timer++;
    top[Node] = tp;
    for (auto [child, w] : adj[Node]){
        if (child == up[Node][0]) continue;
        if (big == -1 || sz[child] > sz[big]) big = child;
    }
    if (big == -1) return;
    HLD(big, tp);
    for (auto [child, w] : adj[Node]){
        if (child != up[Node][0] && child != big)
            HLD(child, child);
    }
}

int get_lca(int u, int v){
    if (depth[u] > depth[v]) swap(u, v);
    int l = depth[v] - depth[u];
    for (int i = LOG - 1; i >= 0; i--)
        if (l & (1 << i)) v = up[v][i];
    assert(depth[u] == depth[v]);
    for (int i = LOG - 1; i >= 0; i--){
        if (up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return (u == v ? u : up[u][0]);
}

int query_path(int u, int p, int x){
    int ret = 0;
    while (u != p){
        if (top[u] == u){
            ret = add(ret, update(1, 1, N, id[u], id[u], x));
            u = up[u][0];
        }
        else if (depth[top[u]] > depth[p]){
            ret = add(ret, update(1, 1, N, id[top[u]], id[u], x));
            u = up[top[u]][0];
        }
        else{
            ret = add(ret, update(1, 1, N, id[p] + 1, id[u], x));
            break;
        }
    }
    return ret;
}

void solve(){
    cin >> N >> Q;
    for (int i = 1; i <= 4 * N; i++) lazy[i] = 1;
    for (int i = 1; i < N; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    dfs_init(1, 1);
    HLD(1, 1);
    build(1, 1, N);
    for (int q = 1; q <= Q; q++){
        int u, v, x;
        cin >> u >> v >> x;
        int lc = get_lca(u, v);
        int ans = add(query_path(u, lc, x), query_path(v, lc, x));
        cout << ans << endl;
    }
}

int32_t main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}