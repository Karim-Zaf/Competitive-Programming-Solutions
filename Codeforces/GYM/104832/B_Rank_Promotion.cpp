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
 
const int N = 500100 ;
int seg[4 * N] ;
int pref[N] ;
 
void update(int id , int tl , int tr , int pos , int x){
    if(tl == tr) seg[id] = x ;
    else {
        int mid = (tl + tr) / 2 ;
        if(pos <= mid) {
            update(2 * id , tl , mid , pos , x) ;
        }else {
            update(2 * id + 1 , mid + 1 , tr , pos , x) ;
        }
        seg[id] = min(seg[2 * id] , seg[2 * id + 1]) ; 
    }
}
int get(int id , int tl , int tr , int l , int r){
    if(tl > r || tr < l) return sup ; 
    if(tl >= l && tr <= r) return seg[id] ;
    int mid = (tl + tr) / 2 ;
    return min(get(2 * id , tl , mid , l , r) , get(2 * id + 1 , mid + 1 , tr , l , r)) ;
}
void solve(){
    int n , c, p , q ; 
    cin >> n >> c >> p >> q ;
    for(int i = 0 ; i <= 4 * n ; i++) seg[i] = sup ;
    string s ; 
    cin >> s ;
    s = "#" + s ;
    int l = 0 , rank = 0;
    for(int i = 1 ; i <= n ; i++){
        pref[i] = pref[i - 1] ;
        if(s[i] == 'Y') pref[i]++ ;
        update(1 , 1, n , i , q * pref[i - 1] - p * i + p) ; 
        int lo = l + 1 ;
        int ro = i - c + 1;
        if(lo > ro)
            continue ;
        int mn = get(1 , 1 , n , lo , ro) ;
        if(mn <= q * pref[i] - p * i) {
            rank++ ;
            l = i ;
        }
    }
    cout << rank << endl;
}
 
signed main(){
    FAST
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}