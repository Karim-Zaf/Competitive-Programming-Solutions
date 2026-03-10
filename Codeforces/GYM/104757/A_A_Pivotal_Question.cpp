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
int a[N] ; 
 
void solve(){
    int n ;
    cin >> n ;
    for(int i=1 ; i<=n ; i++) cin >> a[i] ; 
    
    multiset<int> s1 , s2 ; 
    vector<int> ans ; 
 
    for(int i=1 ; i<=n ; i++) s2.insert(a[i]) ;
    
    for(int i=1 ; i<=n ; i++){
        bool ok = true ;
        auto it = s2.find(a[i]) ; 
        s2.erase(it) ; 
        s1.insert(a[i]) ; 
        if(!s1.empty()) ok &= (*s1.rbegin() <= a[i]) ; 
        if(!s2.empty()) ok &= (*s2.begin() > a[i]) ; 
        if(ok ) ans.pb(a[i]) ; 
    }
    cout << ans.size() << " " ;
    for(int i=0 ; i<100 && i<ans.size() ; i++) cout << ans[i] << " " ;
    cout << endl ; 
}
 
int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  