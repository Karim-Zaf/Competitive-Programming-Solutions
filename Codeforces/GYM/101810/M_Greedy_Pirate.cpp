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

vector<array<int, 3>> adj[N_Max];
int up[N_Max][LOG], depth[N_Max];
ll pref_frst[N_Max], pref_sec[N_Max];

void dfs(int Node, int par){
    up[Node][0] = par;
    for (int i = 1; i < LOG; i++)
        up[Node][i] = up[up[Node][i - 1]][i - 1];
    for (auto [child, c1, c2] : adj[Node]){
        if (child == par) continue;
        depth[child] = depth[Node] + 1;
        pref_frst[child] = pref_frst[Node] + c1;
        pref_sec[child] = pref_sec[Node] + c2;
        dfs(child, Node);
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
    int N, Q;
    cin >> N;
    for (int i = 1; i <= N; i++)
        adj[i].clear();
    ll s = 0;
    for (int i = 1; i < N; i++){
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        adj[u].push_back({v, c1, c2});
        adj[v].push_back({u, c2, c1});
        s += c1 + c2;
    }
    dfs(1, 1);
    cin >> Q;
    for (int i = 1; i <= Q; i++){
        int x, y;
        ll ans = s;
        cin >> x >> y;
        int p = get_lca(x, y);
        ll m1 = pref_frst[x] - pref_frst[p];
        ll m2 = pref_sec[y] - pref_sec[p];
        ans -= m1 + m2;
        cout << ans << endl;
    }
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