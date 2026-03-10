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

const int N = 300100 ; 
vector<int> adj[N] ;
string s ;
ll dp[N][2] ;
ll po[N] ; 
int depth[N] ;
int mx[N] ; 
int sz[N] ;
int n , m ; 

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

void dfs_init(int node , int par){
    mx[node] = depth[node] ; 
    sz[node] = 1 ; 
    for(int child : adj[node]){
        if(child == par) continue ;
        depth[child] = depth[node] + 1 ;  
        dfs_init(child , node) ;
        mx[node] = max(mx[node] , mx[child]) ; 
        sz[node] += sz[child] ; 
    }
}

ll work(int node , int par , bool flag , int dep){
    ll &ret = dp[node][flag] ; 
    if(ret != -1) return ret ;
    if(mx[node] - dep < m - 1) return ret = po[sz[node]] ;  
    
    ret = 0 ;
    int d = depth[node] - dep ;

    if(adj[node].size() == 1 && node != 1){
        if(flag) return ret = 10 ; 
        else return ret = s[d] - '0' + 1 ;
    }

    for(int cur = 0 ; cur < 10 ; cur++){ 
        ll g = 1 ;        
        if(!flag){
            for(int child : adj[node]){
                if(child == par) continue ;
                if(cur < s[d] - '0') {
                    g = mult(g , work(child , node , true , dep)) ; 
                }else if(cur == s[d] - '0') {
                    g = mult(g , work(child , node , false , dep)) ; 
                }else g = 0;
            }
        }else {
            for(int child : adj[node]){
                if(child == par) continue ; 
                g = mult(g , work(child , node , flag , dep)) ; 
            }
        }
        ret = add(ret , g) ; 
    }
    return ret ;
}

ll dfs(int node , int par){
    if(mx[node] - depth[node] < m) 
        return work(node , par , 0 , depth[node]) ; 
    ll ret = 1 ;
    for(int child : adj[node]) {
        if(child == par) continue ;
        ret = ret * dfs(child , node) % mod ; 
    }
    return ret ;
}


void solve(){
    cin >> n ;
    memset(dp , -1 , sizeof(dp)) ; 
    for(int i = 1 ; i < n ; i++){
        int u , v ; 
        cin >> u >> v ; 
        adj[u].push_back(v) ; 
        adj[v].push_back(u) ; 
    }
    cin >> m ;
    cin >> s ;
    if(n == 1){
        if(m > 1) {
            cout << 10 << endl;
        }else {
            cout << s[0] - '0' + 1 << endl;
        }
        return ; 
    }

    dfs_init(1 , 0) ;
    cout << dfs(1 , 0) << endl; ; 
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    po[0] = 1 ;
    for(int i = 1 ; i < N ; i++) po[i] = po[i - 1] * 10 % mod ;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}