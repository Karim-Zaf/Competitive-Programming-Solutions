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
 
 
void solve(){
    ll n;
    cin >> n ;
 
    vector<ll> divisors ; 
    for(ll i=1 ; i*i<=n ; i++){
        if(n%i==0){
            divisors.pb(i) ;
            if(n/i!=i) divisors.pb(n/i) ; 
        }
    }
    sort(divisors.begin(),divisors.end()) ; 
    vector<ll> ans ;
    for(ll i=2 ; i*i<=n ; i++){
        vector<ll> g ; 
        ll x = n ; 
        while(x>0) {
            g.pb(x%i) ; 
            x/=i ; 
        }
        int sz = (int)g.size() ; 
        bool ok = true ; 
        for(int j=0 ; j<sz/2 ; j++){
            if(g[j]!=g[sz-1-j]) ok = false ;
        }
        if(ok) ans.pb(i) ;
    }
    for(ll j : divisors){
        if(j==1) continue ; 
        if(j-1<=n/(j-1)) continue ; 
        if(j * (n/(j-1))==n) ans.pb(j-1) ; 
    }
    sort(ans.begin(),ans.end()) ; 
    if(ans.empty()){
        cout << "*" << endl ; 
        return ; 
    }
    for(auto x : ans) cout << x << " " ;
    cout << endl ; 
}
 
int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  