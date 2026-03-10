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
 
const int N = 200100 ;
vector<ll> a[2] ; 
 
void solve(){
    ll n , k , x , y ;
    cin >> n >> k >> x >> y ; 
 
    for(int i=0 ; i<2 ; i++) {
        a[i].clear() ; 
        a[i].pb(0) ; 
    }
 
    int sz =0 , szz= 0  ; 
    for(int i=1 ; i<=n ; i++){
        char c ;
        int val ; 
        cin >> c >> val ; 
        a[c-'A'].pb(val) ;
        if(c=='A')sz++ ; 
        else szz++ ;  
    }
    for(int i=0 ; i<2 ; i++ ) sort(a[i].begin()+1,a[i].end(),greater<ll>()) ;
    
    for(int i=0 ; i<2 ; i++){
        for(int j=1 ; j<(int)a[i].size() ; j++) a[i][j] += a[i][j-1] ; 
    }
 
    ll ans = -inf ; 
    for(ll g=0 ; g<=sz ; g++){
        ll rest = 2*k-g ; 
        if(rest>szz || rest<0) continue ;
        ll match = min(g,rest) ; 
        ll p = (g-match)/2 , r = (rest-match)/2 ;
        ans = max(ans , a[0][g] + a[1][rest] - p*1ll*x-r*1ll*y) ; 
    }   
    cout << ans << endl ;
}
 
int main(){
    fast 
    ll t = 1 ; 
    cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  