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
const int N_Max = 1005;
const int Nax = 15;
const int LOG = 15;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
vector<int> adj[N_Max];
int a[N_Max], pref[N_Max], depth[N_Max];
int belong[N_Max], up[N_Max][LOG];
 
void dfs(int Node, int par, int c){
    up[Node][0] = par;
    for (int i = 1; i < LOG; i++)
        up[Node][i] = up[up[Node][i - 1]][i - 1];
    belong[Node] = c;
    for (int child : adj[Node]){
        depth[child] = depth[Node] + 1;
        pref[child] = pref[Node] + a[child];
        dfs(child, Node, c);
    }
}
 
int get_lca(int u, int v){
    if (depth[u] > depth[v]) swap(u, v);
    int l = depth[v] - depth[u];
    for (int i = LOG - 1; i >= 0; i--)
        if (l & (1 << i)) v = up[v][i];
    assert(depth[u] == depth[v]);
    for (int i = LOG - 1; i >= 0; i--){
        if (up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return (u == v ? u : up[u][0]);
}
 
void solve(){
    int N, M;
    cin >> N >> M;
    vector<int> in_deg(N + 1), par(N + 1), b, leaf;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        in_deg[v]++;
        par[v] = u;
    }
    for (int i = 1; i <= N; i++){
        if (!in_deg[i]) b.pb(i);
        if ((int)adj[i].size() == 0) leaf.pb(i);
    }
    for (int i = 0; i < (int)b.size(); i++){
        pref[b[i]] = a[b[i]];
        dfs(b[i], 0, i + 1);
    }
    int ans = 2e9;
    for (int i = 0; i < (int)leaf.size(); i++){
        for (int j = i + 1; j < (int)leaf.size(); j++){
            int u = leaf[i], v = leaf[j];
            if (belong[u] != belong[v]){
                ans = min(ans, pref[u] + pref[v]);
                continue;
            }
            int p = get_lca(u, v);
            int res = pref[u] + pref[v] - pref[p];
            ans = min(ans, res);
        }
    }
    cout << ans << endl;
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