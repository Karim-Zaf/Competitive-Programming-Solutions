//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
using namespace std ;
using namespace __gnu_pbds;
using ll = long long ;
using ld = long double ;
using uint = unsigned int ;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif

#define ll long long
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define F first
#define S second
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const int mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 200100 ; 
ll fact[N] , p[N]; 

ll C(ll n , ll k){
    return fact[n] * inv(fact[k] * fact[n - k] % mod) % mod ;
}

long long binpow(long long a, long long b, long long m = mod) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve(){ 
    ll n , m , a , b , k ;
    cin >> n >> m >> a >> b >> k ;
    
    ll ans = 0 ; 
    for(int x = 0 ; x <= k ; x++){
        ll y = k - x ; 
        ll g = C(k , x) ;
        g = g * p[k] % mod ; 
        ll li = 1 , ri = x / a ;
        ri = min(ri , n) ; 
        ll lj = 1 , rj = y / b ; 
        rj = min(rj , m) ; 
        ll len1 = max(0ll , ri - li + 1) % mod , len2 = max(0ll , rj - lj + 1) % mod ; 
        ll gg = len1 * len2 % mod ; 
        
        gg = (n * m % mod - gg + mod) % mod ;

        ans += gg * g % mod ;
        ans %= mod ;
    }
    cout << ans << endl;
}

int main(){
    fast 

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    
    fact[0] = 1 ;
    for(int i = 1 ; i < N ; i++) fact[i] = fact[i - 1] *1ll * i % mod ; 
    
    p[N - 1] = inv(binpow(2 , N - 1)) ; 
    for(int i = N - 2 ; i >= 0 ; i--) p[i] = p[i + 1] * 2 % mod ; 

    ll t = 1 ; 
    cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  