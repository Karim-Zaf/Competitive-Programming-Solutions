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
 
const int N = 100010 ;
const int M = 300 ;
vector<tuple<string,int,int>> a ;   
bool vis[N][M] ; 
int n ;
 
void solve(){
    cin >> n ; 
    a.clear() ; 
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<256 ; j++) vis[i][j] = false ; 
    }
    a.pb(make_tuple("0",0,0)) ;
    for(int i=1 ; i<=n ; i++){
        string s ;
        cin >> s ; 
        int v ;
        cin >> v ; 
        if(s == "add") a.pb(make_tuple(s,v,0)) ; 
        else {
            int k ; 
            cin >> k ;
            a.pb({s,v,k}) ; 
        }
    }
    int i = 1 , r = 0 ;
    bool ok = false ;  
    while(true){
        assert(r < 256) ; 
        if(i > n) {
            ok = true ;
            break ; 
        }
        if(vis[i][r]) {
            ok = false ; 
            break ; 
        }
        vis[i][r] = true ; 
        auto [s,v,k] = a[i] ; 
        if(s == "add") {
            r = (r + v)%256 ;     
            i++ ; 
        }else {
            if(s == "beq"){
                if(r == v) i = k ; 
                else ++i ; 
            }else if(s == "bne"){
                if(r != v) i = k;
                else ++i ; 
            }else if(s == "blt"){
                if(r < v) i = k ;  
                else ++i ; 
            }else {
                if(r > v) i = k ; 
                else ++i ; 
            }
        }
    }
    if(ok)cout << "Yes" << endl ;
    else cout << "No" << endl ; 
}
 
int main(){
    fast 
    ll t = 1 ; 
    cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  