#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define ld double
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define affichea(a,n) for(ll i=0 ; i<n ; i++) cout << a[i] <<" " ;
#define yes cout << "Yes" << endl;
#define no cout<<"No"<<endl;
#define F first
#define S second
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define double long double
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 100100 ;
vector<int> a[N] ;
bool ok[N] ; 
bool vis[N] ;
int depth[N],sz[N] ; 
int mn , gg;
int n, k ;

void dfs(int node){
    vis[node] = true ; 
    sz[node] = 1 ;
    for(int j : a[node]){
        if(!vis[j]) {
            depth[j] = depth[node] + 1 ;
            dfs(j) ;
            sz[node] += sz[j] ; 
        }
    }
    if(sz[node]>=k && depth[node]>mn){
        mn = depth[node] ; 
        gg = node ; 
    }
}

void DFS(int node,int par){
    if(node==gg) ok[node] = true ; 
    for(int j : a[node]){
        if(ok[node] && j!=par) ok[j] = true ; 
        if(j!=par) DFS(j,node) ; 
    }
}

void solve(){
    cin >> n >> k ;
    for(int i=2 ; i<=n ; i++){
        int x ; 
        cin >> x ; 
        a[x].pb(i) ; 
        a[i].pb(x) ; 
    }   
    mn = -1 , gg = 1 ; 
    dfs(1) ; 
    if(mn==-1){
        cout << -1 << endl;
        return ; 
    }
    DFS(1,0) ; 
    int cnt = 0 ;
    for(int i=1 ; i<=n ; i++){
        if(cnt>=k) break ; 
        if(ok[i]) {
            cout << i << " " ;
            cnt++ ; 
        }
    }
    cout << endl ; 
}   

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  