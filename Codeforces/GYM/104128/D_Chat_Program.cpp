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
ll a[N] ; 
ordered_set s1 , s2 , s3 ; 
ll n , k , m , c ,d ; 
 
ll bs(ll plus){
    ll l = 0 , r = 1e16 , ret = -1 ; 
    while(l<=r){
        ll mid = l + (r-l)/2 ;
        int g1 = s1.order_of_key({mid,inf}) ;
        int g2 = s3.order_of_key({mid,inf}) ; 
        int g3 = s2.order_of_key({mid + plus*d,inf}) ; 
        if(g1 + g2 + g3 >= n-k+1 ) {
            r = mid - 1 ; 
            ret = mid ; 
        }else{
            l = mid + 1 ; 
        }
    }    
    return ret ; 
}
 
void solve(){
    cin >> n >> k >> m >> c >> d ; 
    for(int i=1 ; i<=n ; i++) cin >> a[i] ;
    for(int i=1 ; i<=n ;i++) s3.insert({a[i],i}) ;
    ll ans = bs(0) ; 
 
    s3.clear() ; 
    for(int i=1 ; i<=m ; i++) s2.insert({a[i]+ c + d*(i-1),i}) ; 
    for(int i=m+1 ; i<=n ;i++) s3.insert({a[i],i}) ; 
    
    for(ll i=1 ; i<=n-m+1 ; i++){
        ll k_th = bs((i-1)) ; 
        ans = max(ans , k_th) ;
        // dbg(i) ; 
        // dbg(k_th) ;   
        s3.erase({a[i+m],i+m}) ; 
        s2.insert({a[i+m] + c + (m + i-1)*d,i+m}) ; 
        s2.erase({a[i] + c + (i-1)*d , i}) ; 
        s1.insert({a[i],i}) ; 
    }
    cout << ans << endl ; 
}
 
int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  