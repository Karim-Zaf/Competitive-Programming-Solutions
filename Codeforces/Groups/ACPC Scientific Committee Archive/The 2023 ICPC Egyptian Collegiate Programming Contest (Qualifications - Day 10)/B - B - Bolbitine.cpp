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
 
int add(int a , int b){
    return ( a + 0ll + b ) % mod ; 
}
int mult(int a , int b){
    return a * 1ll * b % mod ;
}
int sub(int a , int b){
    return (a - 0ll - b + mod ) % mod ;
}
int divide(int a , int b){
    return a * 1ll * inv(b) % mod ; 
}
const int N = 200100 ; 
int f[N];
 
int C(int n , int k){
    return mult(f[n] , inv(mult(f[k] , f[n - k]))) ;
}
void solve(){
    int m , n ;
    cin >> m >> n ;
    int ans = 1 ;
    for(int i = 0 ; i < m ; i++) {
        int x ; 
        cin >> x ;
        ans = mult(ans , C(x + n - 1 , n - 1)) ; 
    }
    cout << ans << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    f[0] = 1;
    for(int i = 1 ; i < N ; i++) f[i] = mult(f[i - 1] , i) ;
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}