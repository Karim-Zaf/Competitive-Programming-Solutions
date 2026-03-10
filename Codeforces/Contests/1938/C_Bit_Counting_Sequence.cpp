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


const int N = 500100 ;
int b[N] , a[N] ; 

void solve(){ 
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++) cin >> b[i] ; 

    int x = b[1] ; 
    for(int i = 2 ; i <= n ; i++) {
        a[i] = b[i] - b[i - 1] ;
        if(a[i] > 1) {
            cout << -1 << endl;
            return ; 
        }
    }


    long long ans = 0 , res = 0 ; 
    int i = 2 ;

    // 011
    int lst = 0 ;
    while(i <= n){
        int g = 0 ; 
        while(g < 63 && ((1ll << g) & ans)) g++ ; 
        int diff = -g + 1 ;
        
        if(diff < a[i]){
            cout << -1 << endl;
            return ; 
        }

        while(diff > a[i] && x >= 0){
            res |= (1ll << g) ; 
            ans |= (1ll << g) ;
            x-- ; 
            diff-- ; 
            g++ ; 
        }
        if(x < 0) {            
            cout << -1 << endl;
            return ;
        }
        ans++ ; 
        while(i + 1 <= n && ans < (1ll << (g + 1)) - 1) {
            i++ ;
            int old = __builtin_popcount(ans) ;  
            ans++ ;
            int ne = __builtin_popcount(ans) ; 
            if(ne - old != a[i]){
                cout << -1 << endl;
                return ; 
            }
        }
        lst = g + 1;
        i++ ; 
    }
    
    while(x > 0){
        res |= (1ll << lst) ;
        assert(lst < 63) ; 
        x-- ; 
        lst++ ; 
    }
    cout << res << endl;
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