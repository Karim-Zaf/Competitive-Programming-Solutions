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
const int N_Max = 3e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
struct DSU{
    vector<int>  sz, parent, l, r, col;
    void init(int n){
    	col.resize(n + 5);
    	for (int i = 0; i < n; i++)
    		l.pb(i), r.pb(i), parent.pb(i), sz.pb(1);
    }
    int get(int u){return (parent[u] == u ? u : parent[u] = get(parent[u]));}
    bool unite(int u, int v){
        u = get(u);
        v = get(v);
        if (u == v) return false;
        l[u] = min(l[u], l[v]);
        r[u] = max(r[u], r[v]);
        parent[v] = u;
        sz[u] += sz[v]; 
        return true; 
    }
    int nxt(int u){return r[get(u)];}
    bool same_set(int u, int v){return get(u) == get(v);}
    int size(int u){ return sz[get(u)];}
};
 
set<int> pos[N_Max];
int a[N_Max], vis[N_Max];
 
void solve(){
	int N;
	cin >> N;
	DSU dsu; dsu.init(N + 5);
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++){
		pos[a[i]].insert(i);
		dsu.col[i] = a[i];
	}
	int M;
	cin >> M;
	for (int i = 1; i <= M; i++){
		int c;
		cin >> c;
		if ((int)pos[c].size() <= 1) continue;
		int l = *pos[c].begin(), r = *pos[c].rbegin();
		for (int j = l; j <= r; j = dsu.nxt(j) + 1){
			if (!vis[j]) pos[a[j]].erase(j);
			vis[j]++;
			dsu.unite(l, j);
		}
	}
	for (int i = 1; i <= N; i++)
		cout << dsu.col[dsu.get(i)] << " ";
	cout << endl;
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