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
 
const int N = 100100 ; 
ll  dp[N] , p[10] ;
vector<int> divisors[N] ; 
 
 
void solve(){
    int n ;
    cin >> n ; 
    for(int i=1 ; i<=n ; i++) dp[i] = inf ; 
    dp[1] = 1 ; 
    for(int i=1 ; i<=n ; i++){
        int x1=i , x2 = 0 ; 
        int cnt = 0 ;
        while(x1>9){
            int gg = x1%10 ; 
            x2+=p[cnt]*gg ; 
            cnt++ ; 
            x1/=10;
            if(gg==0) continue ;
            dp[i] = min(dp[i],dp[x1]+dp[x2]) ; 
        }
        for(int j=1 ; j<=n/2 ; j++){
            dp[i] = min(dp[i],dp[j]+dp[i-j]) ; 
        }
        int sz = (int)(divisors[i].size()) ; 
        for(int j=0 ; j<sz ; j++){
            dp[i] = min(dp[i],dp[divisors[i][j]]+dp[i/divisors[i][j]]) ; 
        }
    }
    cout << dp[n] << endl ; 
}   
 
int main(){
    fast 
    p[0] = 1 ; 
    for(int i=1 ; i<10 ; i++) p[i] = p[i-1]*10 ; 
    for(int i=1 ; i<N ; i++){
        for(int j=i ; j<N; j+=i){
            divisors[j].pb(i) ;
        }
    }
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  