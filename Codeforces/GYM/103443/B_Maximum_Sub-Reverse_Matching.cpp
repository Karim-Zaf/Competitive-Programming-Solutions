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
int n ;
string s , t ;
int pref[N] ; 
int a , b , ans  ; 
 
void work(int l , int r){
    int c = 0 ;
    while(l >= 1 && r <= n){
        if(s[l] == t[r]) c++ ; 
        if(l != r && s[r] == t[l]) c++ ; 
        int cur = pref[n] - pref[r] + pref[l - 1] + c ; 
        if(cur > ans) {
            ans = cur ; 
            a = l , b = r ;
        }else if(cur == ans){
            if(r - l < b - a){
                a = l , b = r ; 
            }else if(r - l == b - a){
                if(l < a){
                    a = l , r = b ; 
                } 
            }
        }
        l-- , r++ ; 
    }
}
void solve(){
    cin >> n ;
    cin >> s >> t ;
    s = "#" + s ;
    t = "#" + t ;
    a = 1 , b = 1 , ans = 0;
    for(int i = 1 ; i <= n ; i++) 
        pref[i] = pref[i - 1] + (s[i] == t[i]) ; 
    for(int i = 1 ; i <= n ; i++){
        work(i , i) ; 
        if(i < n) 
            work(i , i + 1) ; 
    }   
    cout << pref[n] << " " << ans << " " << a << " " << b << endl;
}
 
int main(){
    FAST
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}