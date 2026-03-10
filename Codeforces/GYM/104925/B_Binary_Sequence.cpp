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

string work(ll x){
    int msb = 63 - __builtin_clzll(x) ;
    string res = "" ;
    for(int i = 0 ; i <= msb ; i++){
        if(x & (1ll << i)) {
            res += '1' ;
        }else 
            res += '0' ;
    }
    return res ;
}
const int N = 100100 ; 
string res = "1" ;
int cur = 1;
bool ans[N] ;

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    vector<array<ll,2>> query[38] ;
    for(int i = 0 ; i < tc ; i++){
        ll n , m;
        cin >> n >> m ;
        if(n <= 37){
            query[n].push_back({m , i}) ;
        }else {
            int g = 36 ;
            if((n - 35) % 2 == 0) g++ ;
            query[g].push_back({m , i}) ;
        }
    }
    for(int x = 1 ; x <= 37 ; x++){
        while(cur < x){
            string ret = "" ;
            for(int j = 0 ; j < res.size() ; j++){
                int k = j ;
                while(k < res.size() && res[k] == res[j]) k++ ;
                int x = k - j ; 
                ret += res[j] ;
                ret += work(x) ;
                j = k - 1 ;
            }
            swap(res , ret) ;
            cur++;
        }
        for(auto [m , idx] : query[x]){
            if(m >= res.size()) ans[idx] = false;
            else ans[idx] = (res[m] == '1' ? true : false) ;
        }
    }
    for(int i = 0 ; i < tc ; i++){
        if(ans[i]) cout << '1' << endl;
        else cout << '0' << endl;
    }
    return 0;
}