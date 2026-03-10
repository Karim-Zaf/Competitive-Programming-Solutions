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

vector<pair<int, int>> adj[N_Max];
int up[N_Max][LOG], depth[N_Max], anc[N_Max];
ll pref[N_Max], ans[N_Max];
bool red[N_Max];
int N, M, Q;

void dfs_init(int Node, int par){
	up[Node][0] = par;
	for (int i = 1; i < LOG; i++)
		up[Node][i] = up[up[Node][i - 1]][i - 1];
	if (red[Node]){
		ans[Node] = 0;
		anc[Node] = Node;
	}
	for (auto [child, w] : adj[Node]){
		if (child == par) continue;
		depth[child] = depth[Node] + 1;
		pref[child] = pref[Node] + w;
		ans[child] = ans[Node] + w;
		anc[child] = anc[Node];
		dfs_init(child, Node);
	}
}

int get_lca(int u, int v){
	if (depth[v] < depth[u]) swap(u, v);
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

ll get_dist(int u, int v){
	return pref[v] - pref[u];
}

bool comp(int u, int v){
	return ans[u] > ans[v];
}

ll work(){
	int K;
	cin >> K;
	vector<int> a(K), vec;
	for (int i = 0; i < K; i++) cin >> a[i];
	int u = a[0];
	for (int i = 1; i < K; i++)
		if (ans[a[i]] > ans[u]) u = a[i];
	ll x = 0;
	for (int i = 0; i < K; i++){
		if (anc[a[i]] == anc[u]) vec.pb(a[i]);
		else if (ans[a[i]] == ans[u]) return ans[u];
		else x = max(x, ans[a[i]]);
	}
	sort(vec.begin(), vec.end(), comp);
	K = (int)vec.size();
	ll ret = (K == 1 ? 0 : ans[vec[1]]), sum = ans[u];
	int lca = u, rep = anc[u];
	for (int i = 1; i < K; i++){
		sum += ans[vec[i]];
		lca = get_lca(lca, vec[i]);
		ll curr = ans[u] - get_dist(rep, lca);
		ret = min(ret, max(curr, (i + 1 < K ? ans[vec[i + 1]] : 0)));
	}
	return max(ret, x);
}

void solve(){
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++){
		adj[i].clear();
		red[i] = false;
	}
	for (int i = 1; i <= M; i++){
		int x;
		cin >> x;
		red[x] = true;
	}
	for (int i = 1; i < N; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dfs_init(1, 1);
	for (int q = 1; q <= Q; q++)
		cout << work() << endl;
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