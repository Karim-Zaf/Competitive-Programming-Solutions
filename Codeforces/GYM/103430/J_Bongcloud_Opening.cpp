#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define ld double
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define affichea(a,n) for(ll i=0 ; i<n ; i++) cout << a[i] <<" " ;
#define yes cout << "Yes" << endl;
#define no cout<<"No"<<endl;
#define F first
#define S second
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define double long double
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 
 
const int N = 2010 ; 
ll a[N] , b[N] , c[N] , d[N] ; 
ll dp[N][5][2] ; 
ll n , k , x ;
ll ans ; 
 
ll work(int i , ll cur){
    if(i>n) {
        ans = max(ans , cur) ;
        return 0 ; 
    }
    if(cur<=x+k && cur>=x-k){
        ll g = cur - x + k ;
        ll res = -inf ; 
        if(dp[i][g][0] != -inf) res = max(res , dp[i][g][0]) ;
        else{
            dp[i][g][0] = -inf ; 
            if(c[i]) dp[i][g][0] = max(dp[i][g][0],cur+a[i]+work(i+1,cur+a[i])) ;
            else dp[i][g][0] = max(dp[i][g][0] , cur-b[i]+work(i+1,cur-b[i])) ;
            res = max(res,dp[i][g][0]) ; 
        }
 
        if(dp[i][g][1]!=-inf) res = max(res , dp[i][g][1]) ;  
        else{
            dp[i][g][1] = -inf ; 
            if(d[i]) dp[i][g][1] = max(dp[i][g][1],cur + a[i] + work(i+1,cur+a[i])) ; 
            else dp[i][g][1] = max(dp[i][g][1] , cur - b[i] + work(i+1,cur-b[i])) ;
            res = max(res,dp[i][g][1]) ; 
        }
        return res ; 
    }else if(cur>x+k) {
        if(d[i]) return cur + a[i] + work(i+1,cur+a[i]) ; 
        else return cur - b[i] + work(i+1,cur-b[i]) ; 
    }else {
        if(c[i]) return cur + a[i]+ work(i+1,cur+a[i]) ; 
        else return cur- b[i] + work(i+1,cur-b[i]) ; 
    }
}
void solve(){
    cin >> n >> k >> x ; 
    for(int i=0 ; i<=n+1 ; i++){
        for(int j=0 ; j<5 ; j++){
            for(int k=0 ; k<2 ; k++) dp[i][j][k] = -inf ; 
        }
    }
    for(int i=1 ; i<=n ; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i] ; 
    }
    ans = -inf ;
    ll p = work(1,x)  ;
    cout << ans << endl ; 
}   
 
int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  