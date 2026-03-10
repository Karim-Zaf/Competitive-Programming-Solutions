//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 3e5 + 7;
const int Nax = 1e6 + 5;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
const int N = 1010 ;
int a[N][N] ;
int mx[N] ;
int mn[N];
 
void solve(){
    int n , m , k ; 
    cin >> n >> m >> k ;
    for(int i = 1 ; i <= m ; i++) {
        mx[i] = 0;
        mn[i] = 2e9 ;    
    }
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> a[i][j] ;
    if(k == 1){
        cout << 0 << endl;
        return ;
    } 
    ordered_set stmx , stmn ;
    for(int i = 1 ; i <= m ; i++) {
        for(int j = 1 ; j <= n ;j++)  { 
            mx[i] = max(mx[i] , a[j][i]) ;
            mn[i] = min(mn[i] , a[j][i]) ; 
        } 
        stmx.insert({mx[i] , i}) ; 
        stmn.insert({mn[i] , i}) ; 
    }
    int ans = 0 ; 
    for(int i = 1 ; i <= m ; i++){
        stmx.erase({mx[i] ,i}) ; 
        stmn.erase({mn[i] ,i}) ; 
        
        int x = (int)stmx.size() - stmx.order_of_key({mn[i] , -2e9}) ;
        if(x >= k - 1 && !stmx.empty()) 
            ans = max(ans ,(*stmx.rbegin()).F - mn[i]) ;
        
        x = (int)stmx.order_of_key({mx[i] , 2e9}) ; 
        if(x >= k - 1 && !stmn.empty())
            ans = max(ans , mx[i] - (*stmn.begin()).F) ;
        
        stmx.insert({mx[i] , i}) ; 
        stmn.insert({mn[i] , i}) ;
    }
    cout << ans << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}