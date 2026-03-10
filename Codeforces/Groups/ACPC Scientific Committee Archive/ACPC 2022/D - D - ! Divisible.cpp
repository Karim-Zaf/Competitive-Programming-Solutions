#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

const int N_Max = 2e5 + 5;
const int Nax = 1e6 + 7;
const int LOG = 19;

vector<int> adj[N_Max], primes;
int l_chld[22 * N_Max];
int r_chld[22 * N_Max];
int st[22 * N_Max];
bool is_prime[Nax];
int up[N_Max][LOG];
int depth[N_Max];
int root[N_Max];
int a[N_Max];
int nd_cnt;
int N, Q;

void sieve(){
    for (int i = 2; i < Nax; i++) is_prime[i] = true;
    for (int i = 2; i < Nax; i++){
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < Nax; j += i) is_prime[j] = false;
    }
}

void init(){
    nd_cnt = 0;
    for (int i = 1; i <= N; i++) adj[i].clear();
}

int add_node(){
    st[nd_cnt] = 0;
    l_chld[nd_cnt] = r_chld[nd_cnt] = -1;
    return nd_cnt++;
}

int get_left(int id){
    return id == -1 ? -1 : l_chld[id];
}

int get_right(int id){
    return id == -1 ? -1 : r_chld[id];
}

int get_val(int id){
    return id == -1 ? 0 : st[id];
}

int update(int id, int ns, int ne, int p){
    int new_id = add_node();
    if (ns == ne){
        st[new_id] = 1;
        return new_id;
    }
    int mid = ns + (ne - ns) / 2;
    if (p <= mid){
        l_chld[new_id] = update(get_left(id), ns, mid, p);
        r_chld[new_id] = get_right(id);
    }
    else{
        l_chld[new_id] = get_left(id);
        r_chld[new_id] = update(get_right(id), mid + 1, ne, p);
    }
    st[new_id] = get_val(l_chld[new_id]) + get_val(r_chld[new_id]);
    return new_id;
}

int query(int idu, int idv, int idlc, int ns, int ne, int l, int r){
    if (ns > r || ne < l) return 0;
    if (ns >= l && ne <= r) return get_val(idu) + get_val(idv) - 2 * get_val(idlc);
    int mid = ns + (ne - ns) / 2;
    return query(get_left(idu), get_left(idv), get_left(idlc), ns, mid, l, r)
        + query(get_right(idu), get_right(idv), get_right(idlc), mid + 1, ne, l, r);
}

void dfs_init(int Node, int par){
    up[Node][0] = par;
    for (int i = 1; i < LOG; i++) up[Node][i] = up[up[Node][i - 1]][i - 1];
    for (int child : adj[Node]){
        if (child == par) continue;
        depth[child] = depth[Node] + 1;
        dfs_init(child, Node);
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
    return u == v ? u : up[u][0];
}

void dfs(int Node){
    root[Node] = update(root[up[Node][0]], 1, 1e6 + 5, a[Node]);
    for (int child : adj[Node])
        if (child != up[Node][0]) dfs(child);
}

bool work(int mid, int u, int v, int lc){
    int p = primes[mid];
    int cnt = query(root[u], root[v], root[lc], 1, 1e6 + 5, 2, p);
    if (is_prime[a[lc]] && a[lc] <= p) cnt++;
    return cnt <= mid;
}

void solve(){
    cin >> N;
    init();
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_init(1, 0);
    for (int i = 1; i <= N; i++)
        if (!is_prime[a[i]]) a[i] = 1;
    root[0] = add_node();
    dfs(1);
    cin >> Q;
    for (int q = 1; q <= Q; q++){
        int u, v;
        cin >> u >> v;
        int lc = get_lca(u, v);
        int l = 0, r = (int)primes.size() - 1, ans = -1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (work(mid, u, v, lc)){
                ans = primes[mid];
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << endl;
    }
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    sieve();
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}