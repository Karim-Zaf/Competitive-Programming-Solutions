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
 
const int N = 110 ;
const int M = 110 ;
const int K = 2000;
int dp[N][M][K] ; 
array<int,2> a[N][M] ; 
 
void solve(){
    int n , m ; 
    cin >> n >> m; 
    int mxK = (n + m) * 8 ; 
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= m ; j++)
            for(int k = 0 ; k < mxK ; k++)
                dp[i][j][k] = -2e9 ;
 
    for(int i = 1 ; i <= n ; i++) 
        for(int j = 1 ; j <= m ; j++){
            int g ;
            cin >> g ; 
            int x = 0 , y = 0 ;
            while(g % 2 == 0) {
                x++ ; 
                g /= 2 ; 
            }
            while(g % 3 == 0) {
                y++ ; 
                g /= 3 ; 
            }
            a[i][j] = {x , y} ; 
        }
 
    dp[0][1][0] = dp[1][0][0] = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++){
            for(int k = 0 ; k < mxK ; k++){
                if( k - a[i][j][1] >= 0){
                    dp[i][j][k] = max(dp[i][j][k] , dp[i - 1][j][k - a[i][j][1]] + a[i][j][0]) ; 
                    dp[i][j][k] = max(dp[i][j][k] , dp[i][j - 1][k - a[i][j][1]] + a[i][j][0]) ; 
                }
            }
        }
    }   
 
    int ans = 0 ;  
    for(int i = 0 ; i < mxK ; i++)
        ans = max(ans , min(i , dp[n][m][i])) ; 
    cout << ans << endl ;
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