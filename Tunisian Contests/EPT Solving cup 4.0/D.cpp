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

const int N = 1050 ; 
int occ[N] , id[26] , dp[N][N];
bool vis[26] ; 
int idx;

int work(int x , int mask){
	int g = (1 << idx) - 1 ; 
	if(x > g){
		if(mask == g) {
			if(occ[x] & 1) return occ[x] - 1 ;
			else return occ[x] ; 
		}
		else return -2e9 ; 
	} 
	int &ret = dp[x][mask] ; 
	if(ret != -1) return ret ;
	ret = -2e9 ;
	if(occ[x] & 1) ret = occ[x] - 1 +  work(x + 1 , mask) ;
	else ret = occ[x] + work(x + 1 , mask) ; 
	if(occ[x] & 1) ret = max(ret , occ[x] + work(x + 1 , (mask ^ x))) ; 
	else {
		if(occ[x] > 0) ret = max(ret , max(0 , occ[x] - 1) + work(x + 1 , (mask ^ x))) ;
	}
	return ret ;  
}

void solve(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i < 26 ; i++) {
		vis[i] = false ;
		id[i] = 0 ;
	}
	for(int i = 0 ; i < N ; i++) 
		occ[i] = 0 ;
	memset(dp , -1 , sizeof(dp)) ; 

	string s ; 
	cin >> s ; 
	for(int i = 0 ; i < (int)s.size() ; i++) vis[s[i] - 'a'] = true ;
	idx = 0;
	for(int i = 0 ; i < 26 ; i++) if(vis[i]) id[i] = idx++ ;
	for(int i = 1 ; i <= n ; i++){
		cin >> s ; 
		int mask = 0 ;
		for(auto c : s)
			if(vis[c - 'a']) mask ^= (1 << id[c - 'a']) ; 
		occ[mask]++ ;
	}
	int ans = work(0 , 0) ;
	if(ans <= 0) cout << -1 << endl ;
	else cout << ans << endl ;
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
