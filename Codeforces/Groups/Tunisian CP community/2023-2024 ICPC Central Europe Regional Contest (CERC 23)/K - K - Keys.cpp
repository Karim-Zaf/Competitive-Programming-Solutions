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

vector<int> cycle, droped, a, b;
vector<pair<string, int>> ans;
map<pair<int, int>, int> mp;
vector<int> adj[N_Max];
int in_cycle[N_Max];
int par[N_Max];
int vis[N_Max];
int N, M, x = -1;

void dfs(int Node){
	vis[Node]++;
	for (int child : adj[Node]){
		if (child == par[Node]) continue;
		if (vis[child] && child == 1) x = Node;
		else if (!vis[child]){
			par[child] = Node;
			dfs(child);
		}
	}
}

pair<int, int> get(int u, int v){
	return make_pair(min(u, v), max(u, v));
}

void work1(){
	int ind = 0;
	while (ind < (int)cycle.size() && cycle[ind] != 0) ind++;
	for (int i = ind - 1; i >= 0; i--){
		ans.push_back({"MOVE", cycle[i]});
		a.pb(mp[get(cycle[i], cycle[i + 1])]);
	}
	ans.push_back({"DONE", -1});
	for (int i = (int)cycle.size() - 1; i >= ind; i--){
		ans.push_back({"MOVE", cycle[i]});
		b.push_back({mp[get(cycle[i], cycle[(i + 1) % (int)cycle.size()])]});
	}
	ans.push_back({"DONE", -1});
}

void work2(){
	vector<int> vec;
	int u = 0;
	while (!in_cycle[u]){
		vec.pb(u);
		ans.push_back({"MOVE", par[u]});
		a.pb(mp[get(u, par[u])]);
		u = par[u];
	}
	reverse(vec.begin(), vec.end());
	if (u != 1){
		ans.push_back({"DROP", -1});
		for (int y : a) droped.pb(y);
		int val = u;
		while (u != -1){
			if (par[u] != -1){
				ans.push_back({"MOVE", par[u]});
				a.pb(mp[get(u, par[u])]);
			}
			u = par[u];
		}
		ans.push_back({"DONE", -1});
		int ind = 0;
		while (cycle[ind] != val) ind++;
		for (int i = (int)cycle.size() - 1; i >= ind; i--){
			ans.push_back({"MOVE", cycle[i]});
			b.pb(mp[get(cycle[i], cycle[(i + 1) % (int)cycle.size()])]);
		}
		ans.push_back({"GRAB", -1});
		for (int z : vec) ans.push_back({"MOVE", z});
		ans.push_back({"DONE", -1});
	}
	else{
		ans.push_back({"MOVE", x});
		ans.push_back({"DROP", -1});
		for (int y : a) droped.pb(y);
		a.pb(mp[get(1, x)]);
		ans.push_back({"MOVE", 1});
		ans.push_back({"DONE", -1});
		for (int i = 1; i < (int)cycle.size(); i++){
			ans.push_back({"MOVE", cycle[i]});
			b.pb(mp[get(cycle[i - 1], cycle[i])]);
		}
		assert(cycle.back() == x);
		ans.push_back({"GRAB", -1});
		for (int i = (int)cycle.size() - 2; i >= 0; i--)
			ans.push_back({"MOVE", cycle[i]});
		for (int z : vec) ans.push_back({"MOVE", z});
		ans.push_back({"DONE", -1});
	}
}

void solve(){
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		mp[get(u, v)] = i;
	}
	par[1] = -1;
	dfs(1);
	if (x == -1){
		cout << "No solution" << endl;
		return;
	}
	int u = x;
	while (u != -1){
		cycle.pb(u);
		in_cycle[u]++;
		u = par[u];
	}
	reverse(cycle.begin(), cycle.end());
	if (in_cycle[0]) work1();
	else work2();
	for (int y : a) cout << y << " ";
	cout << endl;
	for (int y : b) cout << y << " ";
	cout << endl;
	for (auto [s, y] : ans){
		if (s == "DROP"){
			cout << s << " ";
			for (int z : droped) cout << z << " ";
			cout << endl;
		}
		else if (y == -1) cout << s << endl;
		else cout << s << " " << y << endl;
	}
}

int main(){
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