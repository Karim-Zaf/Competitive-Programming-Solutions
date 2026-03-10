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

void solve(){
	int n , res = 0 ; 
	cin >> n ; 
	vector<int> v(n);
	vector<int> mp(370) ;
	for(int i= 0 ;i<n ;i++){
		cin >> v[i] ;
		mp[v[i]]=1;
	}
	for (int i= 0 ;i<360; i++){
		DSU dsu ;
		dsu.init(370);
		for (int j= 0; j<n;j++){
			if (mp[(v[j]+i)%360])
			dsu.unite (v[j],(v[j]+i)%360) ;
		}
		set<int> s ;
		for (int j= 0; j<n ;j++){
			s.insert(dsu.get(v[j]));
		}
		int cnt = 0;
		for (auto x: s ) cnt += dsu.size (x)/2;
		res = max (res , cnt );
	}
	cout << res << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    //cin >> tc;
    while (tc--) solve();
}