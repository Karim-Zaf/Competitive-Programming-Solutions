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
int prefix[26][N] ; 
 
void solve(){
    string s ;
    cin >> s ; 
    ll k ;
    cin >> k ; 
    int n = (int)s.length() ; 
    s = "#" + s ; 
    for(int i=1 ; i<=n ; i++){
        prefix[s[i]-'a'][i]++ ; 
    }
 
    for(int i=0 ; i<26 ; i++){
        for(int j=1 ; j<=n; j++) prefix[i][j] += prefix[i][j-1] ; 
    }
    ll ans = 0 ; 
    k%=mod ; 
    for(int i=1 ; i<=n ; i++){
        int x = 0 , y = 0 ; 
        for(int j=0 ; j<s[i]-'a' ; j++){
            x += prefix[j][n] - prefix[j][i] ;
            y += prefix[j][n] ;  
        }   
        ll g = x*1ll*(k%mod)%mod ; 
        ll p = k%mod*k%mod*y%mod ; 
        ll r = y*k%mod*(k+1)%mod*inv(2)%mod ; 
        ll cur = (g+p-r+mod)%mod ; 
        ans = (ans + cur)%mod ;
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