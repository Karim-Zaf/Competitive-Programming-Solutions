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
 
vector<pair<int, int>> adj[N_Max], rev[N_Max];
vector<int> order, cyc;
bool vis[N_Max];
int N, M, K, S;
 
void dfs_init(int Node){
	vis[Node] = true;
	for (auto [child, e] : adj[Node])
		if (!vis[child]) dfs_init(child);
	order.pb(Node);
}
 
void dfs(int Node){
	cyc.pb(Node);
	vis[Node] = true;
	for (auto [child, e] : rev[Node])
		if (!vis[child]) dfs(child);
}
 
void solve(){
	cin >> N >> M >> K >> S;
	vector<ll> val(N + 1);
	vector<int> cycle(N + 1), root(N + 1), in_deg(N + 1);
	order.clear();
	for (int i = 1; i <= N; i++){
		adj[i].clear();
		rev[i].clear();
		vis[i] = false;
	}
	vector<array<int, 3>> edges;
	for (int i = 1; i <= M; i++){
		int u, v, e;
		cin >> u >> v >> e;
		edges.push_back({u, v, e});
		adj[u].push_back({v, e});
		rev[v].push_back({u, e});
	}
	for (int i = 1; i <= N; i++)
		if (!vis[i]) dfs_init(i);
	for (int i = 1; i <= N; i++) vis[i] = false;
	reverse(order.begin(), order.end());
	int curr = 1;
	for (int x : order){
		if (vis[x]) continue;
		cyc.clear();
		dfs(x);
		for (int u : cyc) root[u] = curr;
		if ((int)cyc.size() > 1) cycle[curr]++;
		curr++;
	}
	for (int i = 1; i <= N; i++) adj[i].clear();
	for (auto [u, v, e] : edges){
		if (root[u] == root[v]) continue;
		adj[root[u]].push_back({root[v], e});
		in_deg[root[v]]++;
	}
	for (int i = 1; i <= N; i++) vis[i] = false;
	queue<int> q;
	for (int i = 1; i < curr; i++){
		if (!in_deg[i]){
			q.push(i);
			val[i] = (cycle[i] ? 1e9 : 0);
			vis[i] = true;
		}
	}
	while (!q.empty()){
		int Node = q.front();
		q.pop();
		for (auto [child, e] : adj[Node]){
			val[child] = max(val[child], val[Node] + e);
			in_deg[child]--;
			if (!in_deg[child]){
				val[child] += (cycle[child] ? 1e9 : 0);
				vis[child] = true;
				q.push(child);
			}
		}
	}
	cout << (val[root[S]] >= K ? "YES" : "NO") << endl;
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