#pragma GCC optimize("Ofast")
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


const int N = 100100 ; 
int w[N] ; 
vector<int> d[N] ; 
vector<int> prime[N] ;
double f[N] ;
bool spf[N] ; 
double sum ;
int n ;

double work(int x){
    double &ret = f[x] ; 
    if(ret != -1) return ret ; 
    ret = 0 ;
    double s = 0 ; 
    for(int i = 2 * x ; i <= n ; i += x){
        int g = gcd(x , i / x) ;
        int cur = x ;
        for(auto pr : prime[g]) 
            while(cur % pr == 0) cur /= pr ; 
        int r = i / cur ; 
        for(int y : d[cur]){
            int m = r * y ;
            double prob = w[m] / sum ; 
            ret = ret + prob * (1 + work(i)) ; 
        }
    } 
    for(auto y : d[x]) s += w[y] ; 
    s /= sum ; 
    ret += s ; 
    ret /= (1 - s) ; 
    return ret ;  
}

void solve(){
    cin >> n ; 
    for(int i = 0 ; i <= n ; i++) f[i] = -1 ; 
    for(int i = 1 ; i <= n ; i++) cin >> w[i] ; 
    sum = 0 ;
    for(int i = 1 ; i <= n ; i++) sum += w[i] ; 
    double ans = work(1) ; 
    cout << ans << endl;
}

int main(){
    FAST
    cout << fixed << setprecision(9) ;
    for(int i = 1 ; i < N ; i++)
        for(int j = i ; j < N ; j += i)
            d[j].push_back(i) ; 
    for(int i = 2 ; i < N ; i++){
        if(spf[i]) continue ; 
        for(int j = i ; j < N ; j += i)
            prime[j].push_back(i) , spf[j] = 1 ; 
    }
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}