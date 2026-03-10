#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

struct DSU{
    vector<int>  sz, parent;
    void init(int n){for (int i = 0; i < n; i++){ parent.pb(i); sz.pb(1);}}
    int get(int u){return (parent[u] == u ? u : parent[u] = get(parent[u]));}
    bool unite(int u, int v){
        u = get(u);
        v = get(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v]; 
        return true; 
    }
    bool same_set(int u, int v){return get(u) == get(v);}
    int size(int u){ return sz[get(u)];}
};

vector<pair<int, int>> adj[N_Max];
int up[N_Max][LOG], val[N_Max][LOG];
int depth[N_Max], vis[N_Max];
int root[N_Max];
int N, Q;

void dfs_init(int Node, int par, int cnt){
	up[Node][0] = par;
	for (int i = 1; i < LOG; i++)
		up[Node][i] = up[up[Node][i - 1]][i - 1];
	root[Node] = cnt;
	vis[Node]++;
	for (auto [child, id] : adj[Node]){
		if (child == par) continue;
		val[child][0] = id;
		depth[child] = depth[Node] + 1;
		dfs_init(child, Node, cnt);
	}
}

void prepare(){
	for (int l = 1; l < LOG; l++)
		for (int i = 1; i <= N; i++)
			val[i][l] = max(val[i][l - 1], val[up[i][l - 1]][l - 1]);
}

int get_ans(int u, int v){
	if (depth[u] > depth[v]) swap(u, v);
	int l = depth[v] - depth[u];
	int ret = 0;
	for (int i = LOG - 1; i >= 0; i--){
		if (l & (1 << i)){
			ret = max(ret, val[v][i]);
			v = up[v][i];
		}
	}
	assert(depth[u] == depth[v]);
	for (int i = LOG - 1; i >= 0; i--){
		if (up[u][i] != up[v][i]){
			ret = max({ret, val[u][i], val[v][i]});
			u = up[u][i];
			v = up[v][i];
		}
	}
	if (u != v) ret = max({ret, val[u][0], val[v][0]});
	return ret;
}

void solve(){
	cin >> N >> Q;
	for (int i = 1; i <= N; i++){
		adj[i].clear();
		vis[i] = root[i] = 0;
		for (int j = 0; j < LOG; j++) val[i][j] = up[i][j] = 0;
	}
	DSU dsu; dsu.init(N + 5);
	vector<array<int, 3>> qry;
	for (int i = 1; i <= Q; i++){
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 2){
			qry.push_back({u, v, i});
			continue;
		}
		if (dsu.unite(u, v)){
			adj[u].push_back({v, i});
			adj[v].push_back({u, i});
		}
	}
	int curr = 1;
	for (int i = 1; i <= N; i++)
		if (!vis[i]) dfs_init(i, 0, curr++);
	prepare();
	for (auto [u, v, id] : qry){
		assert(u != v);
		if (root[u] != root[v]){
			cout << -1 << endl;
			continue;
		}
		int ans = get_ans(u, v);
		if (ans <= id) cout << ans << endl;
		else cout << -1 << endl;
	}
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}