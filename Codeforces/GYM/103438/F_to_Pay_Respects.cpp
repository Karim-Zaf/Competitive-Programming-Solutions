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
 
const int N = 1000100 ;
ll pref0[N] , pref1[N] ;
int ones[N] , zero[N] ; 
string s ; 
 
void solve(){
    ll n , x , r , p , k ; 
    cin >> n >> x >> r >> p >> k ; 
    cin >> s ; 
    s = "#" + s ; 
 
    ll minus = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        ones[i] = ones[i - 1] + (s[i] == '1') ;
        if(s[i] == '1') minus += (n - i + 1) * r; 
    }
    for(int i = 1 ; i <= n ; i++) zero[i] = zero[i - 1] + (s[i] == '0') ; 
    for(int i = 1 ; i <= n ; i++) {
        pref0[i] = pref0[i - 1] ; 
        pref1[i] = pref1[i - 1] ; 
        if(s[i] == '0') pref0[i] += (n - i + 1) * p ; 
        else pref1[i] += (n - i + 1) * (p + r) ; 
    }
    ll ans = -inf ;
    for(int z = 0 ; z <= k ; z++){
        int o = k - z ; 
        int idx0 = lower_bound(zero , zero + n + 1 , z) - zero ; 
        int idx1 = lower_bound(ones , ones + n + 1 , o) - ones ; 
        if(idx0 == n + 1 || idx1 == n + 1) continue ;
        ll cur = x * n - minus;
        cur += pref0[idx0] ; 
        cur += pref1[idx1] ; 
        ans = max(ans , cur) ; 
    }   
    cout << ans << "\n" ; 
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