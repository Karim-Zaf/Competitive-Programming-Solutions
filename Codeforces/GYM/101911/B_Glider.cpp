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
vector<pair<int,int>> a(N) ; 
ll prefix[N] ; 
 
void solve(){
    int n , h  ;
    cin >> n >> h  ;
 
    for(int i=1 ; i<=n ; i++) cin >> a[i].F >> a[i].S ; 
 
    for(int i=1 ; i<=n ; i++) prefix[i] = prefix[i-1] + a[i].S - a[i].F ;
 
    ll ans = 0 ;
    for(int i=1 ; i<=n ; i++){
        int l = i , r = n ; 
        int mx = i ; 
        while(l<=r){
            int mid = (l + r)/2 ; 
            if(a[mid].S - a[i].F - (prefix[mid] - prefix[i-1]) < h ) {
                mx = mid ; 
                l = mid + 1 ;
            } else{
                r = mid - 1 ;
            }
        }
        ll cur = a[mx].S - a[i].F ;
        ll g = cur - (prefix[mx] - prefix[i-1]) ; 
        ll lst = h - g ; 
        ans = max(ans , cur + lst) ;  
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