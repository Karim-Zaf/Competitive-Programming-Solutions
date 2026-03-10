#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 
 
const int N = 221 ; 
set<int> a[N][4] ; 
char ans[N] ;
 
void solve(){
    int n , q ;
    cin >> n >> q ;
    
    for(int i = 0 ; i < n ; i++) ans[i] = '?' ; 
    for(int i = 0 ; i <= n;  i++){
        for(int j = 0 ; j < 4 ; j ++) a[i][j].clear() ; 
    }
    for(int i = 1 ; i <= q ; i++){
        char c1 , c2 ; 
        for(int j = 0 ; j < n ; j++){
            cin >> c1 >> c2 ;
            if(c2 == 'T') a[j][c1 - 'A'].insert(1) ; 
            else a[j][c1 - 'A'].insert(0) ;  
        }
    }
    for(int i = 0  ; i < n ; i++){
        set<int> st , s ;
        
        for(int j = 0 ; j < 4 ; j++) st.insert(j) ; 
 
        for(int j = 0 ; j < 4 ; j++){
            if(a[i][j].empty()) continue ; 
            if(*a[i][j].begin() == 1) s.insert(j) ; 
            else if(*a[i][j].begin()==0) st.erase(j) ; 
        }  
        if((int)s.size() > 1) ans[i] = '?' ;
        else if((int)s.size() == 1) ans[i] = *s.begin() + 'A' ; 
        else if((int)st.size() == 1) ans[i] = *st.begin() + 'A';
    }
    for(int i = 0 ; i < n ; i++) {
        cout << ans[i] ;
        if(i < n - 1) cout << " ";
    }
    cout << endl; 
}
 
int main(){
    fast 
    
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
 
    ll t = 1 ; 
    cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  