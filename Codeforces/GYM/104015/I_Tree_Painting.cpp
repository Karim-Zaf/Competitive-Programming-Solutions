#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
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
const int N_Max = 2e5 + 5;
const int Nax = 1e9 + 7;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
vector<int> adj[N_Max];
int sz[N_Max], parent[N_Max];
int ans[N_Max];
int N;
 
void dfs(int Node, int par){
    parent[Node] = par;
    sz[Node] = 1;
    for (int child : adj[Node]){
        if (child != par){
            dfs(child, Node);
            sz[Node] += sz[child];
        }
    }
}
 
void dfs1(int Node){
    ans[Node] = 1;
    for (int child : adj[Node])
        if (child != parent[Node]) dfs1(child);
}
 
void solve(){
    cin >> N;
    vector<pair<int, int>> edges(N - 1);
    for (int i = 0; i < N - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges[i] = {u, v};
    }
    dfs(1, 0);
    bool flag = false;
    int s;
    for (auto [u, v] : edges){
        if (parent[v] != u) swap(u, v);
        if (sz[v] == N - sz[v] && sz[v] == N / 2){
            flag = true;
            s = v;
            break;
        }
    }
    if (!flag){
        no
        return;
    }
    dfs1(s);
    yes
    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}