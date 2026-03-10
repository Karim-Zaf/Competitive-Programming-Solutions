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
 
const int N = 200100 ;
int a[N] , modulo[N] , fst[N] ; 
 
void solve(){
    int b , l ; 
    cin >> b >> l ;
    
    for(int i = 0 ; i < l  ;i++) cin >> a[i] ; 
 
    modulo[0] = 1 ;
    for(int i = 1 ; i <= l ; i++) modulo[i] = modulo[i - 1] * 1ll * b % (b + 1) ; 
 
    int init = 0 ; 
    reverse(a , a + l) ;
    for(int i = 0 ; i < l ; i++) init = (init + a[i] % (b + 1) * modulo[i] % (b + 1)) % (b + 1) ; 
 
    if(init == 0){
        cout << 0 << " " << 0 << endl;
        return ; 
    }
    
 
    for(int i = 0 ; i < b + 1 ; i++) fst[i] = -1 ;
    
    for(int i = 0 ; i < (b + 1) ; i++){
        int g = i * 1ll * b % (b + 1) ; 
 
        if(fst[g] == -1) fst[g] = i ;   
    }
    
 
 
    for(int i = l - 1 ; i >= 0 ; i--){
        if(i & 1){
            int g = init % (b + 1) ; 
            if(fst[g] == -1) continue ;
            if(fst[g] <= a[i]){
                cout << l - i  << " " << a[i] - fst[g] << endl;
                return ; 
            }
 
        }else{
            if(a[i] >= init){
                cout << l - i << " " << a[i] - init << endl;
                return ;
            }
        }
    }
    cout << "-1 -1" <<endl;  
}
 
int main(){
    fast 
    
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  