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
const ll mod = 998244353;
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

const int N = 100100 ; 
vector<ll> a[N] ; 
ll ans[N] , dp1[N] , dp2[N] , id[N] ;

int dfs_init(int node , int par){
	int mn = 2e9 ;
	bool leaf = true ; 
	for(int j : a[node]){
		if(j == par) continue ; 
		mn = min(mn , dfs_init(j , node)) ; 
		leaf = false ; 
	}
	if(leaf) mn = 0 ; 
	return dp1[node] = mn + 1 ; 
}
void dfs(int node , int par){
	ans[node] = min(dp1[node] , dp2[node]) ;  
	int c = 1 ;
	int sz = (int)a[node].size()  ; 
	vector<ll> pref(sz+1) , suf(sz + 2) ;  
	pref[0] = suf[sz+1] = 2e9 ; 
	for(int j : a[node]){
		if(j == par) continue ;
		pref[c] = min(pref[c-1] , dp1[j]) ;  
		id[j] = c++ ;
	}
	for(int j = a[node].size() -1 ; j>=0 ; j--){
		int x = a[node][j] ; 
		if(x == par) continue ; 
		suf[id[x]] = min(suf[id[x]+1] , dp1[x]) ; 
	}
	for(int j : a[node]){
		dp2[j] = min(dp2[j] , dp2[node] + 1) ;
		dp2[j] = min(dp2[j] , pref[id[j] - 1] + 2) ; 
		dp2[j] = min(dp2[j] , suf[id[j] + 1] + 2)  ;
		dfs(j,node) ;
	}
}

void solve(){
	int n ;
	cin >> n ; 
	
	for(int i = 0 ; i <= n ;i++) dp1[i] = dp2[i] = 2e9 ;

	for(int i = 2 ; i <= n ; i++){
		int m ;
		cin >> m ; 
		a[m].pb(i) ; 
	}	
	int x = dfs_init(1 , 0) ;
	dfs(1 , 0) ;
	ll res = 0 ;
	// for(int i = 1 ; i <= n ; i++){
	// 	dbg(i) ; 
	// 	dbg(dp1[i]) ; 
	// 	dbg(dp2[i]) ; 
	// 	dbg(ans[i]) ; 
	// }
	for(int i = 1 ; i <= n ; i++){
		res = (res + ans[i] * inv(n) % mod) % mod ; 
	}
	cout << res << endl ;
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