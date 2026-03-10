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
#define int ll
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
const int N = 1000100 ;
ll pref[N];
 
void solve(){
    int n , p ;
    cin >> n >> p ;
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        int l = 0 , r = p - 1 , mxr = -1 ;
        while(l <= r){
            int mid = (l + r) / 2 ;
            int cur = i + (mid + 1) * p ;
            cur -= mid * (mid + 1) / 2;
            if(cur > n) r = mid - 1 ;
            else {
                mxr = mid ; 
                l = mid + 1;
            }
        }
        if(mxr == -1) ans = max(ans , i) ; 
        else {
            int g = (mxr + 2) * i ;
            g += p * (mxr + 2) * (mxr + 1) / 2;
            g -= pref[mxr] ;
            ans = max(ans , g) ;
        }
    } 
    cout << ans << endl;
}
 
signed main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    pref[0] = 0;
    for(int i = 1 ; i < N ; i++)
        pref[i] = pref[i - 1] + i * (i + 1) / 2;
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}