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

const int N = 1000100 ; 
ll a[N] ;
vector<ll> v ;

void solve(){
    ll n ;
    cin >> n ;
    for(int i=1 ; i<=n ; i++) cin >> a[i] ; 
    ll x , y ; 
    cin >> x >> y ; 

    for(int i=1 ; i<=n ;i++) {
        if(a[i]&1) v.pb(i) ; 
    }
    int sz = (int)v.size() ; 
    if(sz&1){
        cout << "-1" << endl ;
        return ;
    }
    if(v.empty()){
        cout << 0 << endl ; 
        return ; 
    }
    ll ans = 0 ; 
    for(int i=0 ; i<sz ; i+=2){
        if(x<y){
            ans += abs(v[i+1]-v[i])*1ll*x ; 
        }else{
            ans += abs(v[i+1]-v[i])*1ll*y ;
        }
    }
    ll cur = 0 ; 
    for(int i=1 ; i<sz ; i+=2){
        if(i+1<sz) cur += abs(v[i+1] - v[i]) *1ll * min(x,y) ; 

    }
    cur += abs(n-v.back() + v[0])*min(x,y) ; 
    ans = min(ans , cur) ; 
    cout << ans << endl ; 
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  