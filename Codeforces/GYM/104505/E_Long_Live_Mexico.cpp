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
ll x[N] , y[N] , z[N] , w[N] ; 

void solve(){
    int n ; 
    cin >> n ; 
    for(int i=1 ; i<=n ; i++){
        cin >> x[i] >> y[i] >> z[i] >> w[i] ; 
    }
    ll s1 = 0 , s2 = 0 ; 
    for(int i=1 ; i<=n ; i++) {
        s1+=x[i] * w[i] ;
        s2+=w[i] ; 
    }
    ll x0 = (s1 + s2 - 1) / s2 ;
    ll x1 = s1/s2 ; 
    ll cur1 = s2 * x0*x0 - 2*s1*x0 , cur2 = s2*x1*x1 - 2*s1*x1 ; 
    ll ans1 = x0 ; 
    if(cur2<=cur1) ans1 = x1 ; 
    
    s1 = 0 , s2 = 0 ; 
    for(int i=1 ; i<=n ; i++) {
        s1+=y[i] * w[i] ;
        s2+=w[i] ; 
    }
    ll y0 = (s1 + s2 - 1) / s2 ; 
    ll y1 = (s1)/s2 ; 
    cur1 = s2 * y0*y0 - 2*s1*y0 , cur2 = s2*y1*y1 - 2*s1*y1 ; 
    ll ans2 = y0 ; 
    if(cur2<=cur1) ans2 = y1 ; 
    
    s1 = 0 , s2 = 0 ; 
    for(int i=1 ; i<=n ; i++) {
        s1+=z[i] * w[i] ;
        s2+=w[i] ; 
    }
    ll z0 = (s1 + s2 - 1) / s2 ; 
    ll z1 = s1/s2 ; 
    cur1 = s2 * z0*z0 - 2*s1*z0 , cur2 = s2*z1*z1 - 2*s1*z1 ; 
    ll ans3 = z0 ; 
    if(cur2<=cur1) ans3 = z1 ; 

    cout << ans1 << " " << ans2 << " " << ans3 << endl ; 
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  