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
 
const int N = 10 ; 
char a[N][N] ;
bool vis[N][N] ;
string s = "YOKOHAMA" ;
int dx[] = {0 , 0 , -1 , 1} ;
int dy[] = {1 , -1 , 0 , 0} ;
int n , m;
 
int dfs(int x , int y , int pos){
    if(pos == 7) return 1;
    int ret = 0;
    for(int i = 0 ; i < 4 ; i++){
        int new_x = x + dx[i] ;
        int new_y = y + dy[i] ; 
        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || a[new_x][new_y] != s[pos + 1]) 
            continue ;
        ret += dfs(new_x , new_y , pos + 1) ;
    }
    return ret ;
}
 
void solve(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> a[i][j] ;
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++) 
            if(a[i][j] == s[0]) 
                ans += dfs(i , j , 0) ;
        
    cout << ans << endl;  
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}