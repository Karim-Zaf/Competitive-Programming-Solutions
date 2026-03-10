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
 
vector<int> adj[N_Max];
int tour[N_Max], id[N_Max];
int Q, timer = 1;
 
void dfs(int Node, int par){
	tour[timer] = Node;
	id[Node] = timer++;
	for (int child : adj[Node])
		dfs(child, Node);
}
 
void solve(){
	cin >> Q;
	vector<array<int, 2>> qry(Q);
	int curr = 2;
	for (int i = 0; i < Q; i++){
		int t, x;
		cin >> t >> x;
		qry[i] = {t, x};
		if (t == 1) adj[x].pb(curr++);
	}
	dfs(1, 0);
	set<int> s;
	s.insert(1);
	curr = 2;
	for (auto [t, x] : qry){
		if (t == 1) s.insert(id[curr++]);
		else{
			s.erase(id[x]);
			assert(!s.empty());
			cout << tour[*s.begin()] << endl;
		}
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