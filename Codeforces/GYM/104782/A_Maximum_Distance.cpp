#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 
 
const int N = 10001 ;
int a[N] , b[N] , dp[2][N] ; 
 
void solve(){
    int n ;
    cin >> n ; 
 
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j <= n ;j++) dp[i][j] = 0 ;
 
    for(int i = 1 ; i <= n ;i++) cin >> a[i] ; 
    for(int i = 1 ; i <= n ;i++) cin >> b[i] ; 
    
    int ans = 0 ; 
    
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; j <= n ; j++) dp[1][j] = 0 ;
        for(int j = 1 ; j <= n ; j++){
            if(a[i] != b[j]) dp[1][j] = max(dp[1][j] , dp[0][j - 1] + 1) ;
            dp[1][j] = max(dp[1][j] , dp[0][j - 1]) ;             
            ans = max(ans , dp[1][j]) ; 
        }
        swap(dp[0] , dp[1]) ;
    }   
    cout << ans << endl;
}
 
int main(){
    fast 
 
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    
    ll t = 1 ; 
    cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  