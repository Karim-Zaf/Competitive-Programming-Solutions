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
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
map<pair<int, int>, int> mp;
vector<int> adj[N_Max];
int vis[2][N_Max];
int pref[N_Max];
int N, M, X;
 
void init(){
    mp.clear();
    for (int i = 1; i <= N; i++){
        adj[i].clear();
        pref[i] = vis[0][i] = vis[1][i] = 0;
    }
}
 
void dfs_init(int Node, int par){
    vis[0][Node]++;
    for (int child : adj[Node]){
        if (child == par) continue;
        if (vis[0][child] && !mp[{min(Node, child), max(Node, child)}]){
            pref[child]--;
            pref[Node]++;
            mp[{min(Node, child), max(Node, child)}]++;
        }
        else if (!vis[0][child]) dfs_init(child, Node);
    }
}
 
int dfs(int Node, int par){
    vis[1][Node]++;
    int ret = 0;
    for (int child : adj[Node]){
        if (vis[1][child]) continue;
        ret += dfs(child, Node);
        pref[Node] += pref[child];
        if (!pref[child]) ret++;
    }
    return ret;
}
 
void solve(){
    cin >> N >> M >> X;
    init();
    for (int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> bridges;
    for (int i = 1; i <= N; i++){
        if (vis[0][i]) continue;
        dfs_init(i, 0);
        int cnt = dfs(i, 0);
        bridges.pb(cnt);
    }
    if ((int)bridges.size() > X){
        cout << -1 << endl;
        return;
    }
    X -= (int)bridges.size();
    int op1 = 0;
    for (int c : bridges){
        if (X >= c){
            op1 += c;
            X -= c;
        }
        else{
            op1 += X;
            X = 0;
        }
    }
    cout << op1 + X << endl;
    cout << op1 << " " << X << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}