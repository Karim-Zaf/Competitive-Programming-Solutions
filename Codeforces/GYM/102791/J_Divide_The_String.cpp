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

const int N = 400100 ;
const int M = 26 ; 
int dp[N] ;
vector<int> pos[N] ; 
int nextt[N] ;
int n ;
string s ; 

int work(int i){
    if( i > n ) return 0 ; 
    if(dp[i] != -1) return dp[i] ;
    dp[i] = -2e9 ;  
    for(int j=0 ; j<26 ; j++){
        int h = s[i] + 37 * (j+'a') ;  
        int sz = pos[h].size() ; 
        int k = upper_bound(pos[h].begin() , pos[h].end() , i) - pos[h].begin() ;
        if(k == sz) continue ;
        int g = work(pos[h][k] + 1) ; 
        if(dp[i] < g + 1){
            dp[i] = g + 1 ;
            nextt[i] = pos[h][k]+1 ; 
        }
    } 
    return dp[i] ; 
}

void solve(){
    cin >> n >> s ;
    s = "#" + s ;
    for(int i=0 ; i<=n+1 ; i++) dp[i] = -1 ;

    for(int i=1 ; i<n ; i++){
        int h = s[i] + 37 * s[i+1] ; 
        pos[h].pb(i) ;
    }
    for(int j=0 ; j<26 ; j++){
        int h = s[n] + 37*(j+'a') ; 
        pos[h].pb(n) ; 
    }
    int ans = work(1) ;
    if(ans <= 0) cout << -1 << endl ; 
    else {
        cout << ans << endl ;
        for(int i=1 ; i<=n ; i=nextt[i]) cout << nextt[i] - i << " " ;
        cout << endl ; 
    }
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  