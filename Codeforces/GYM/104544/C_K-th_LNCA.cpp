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
const int N_Max = 1e3 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
vector<int> adj[N_Max], depth[N_Max];
int cnt[N_Max];
 
void dfs_init(int Node, int par, int dep){
    depth[dep].pb(Node);
    for (int child : adj[Node])
        if (child != par) dfs_init(child, Node, dep + 1);
}
 
void dfs(int Node, int par){
    for (int child : adj[Node]){
        if (child != par){
            dfs(child, Node);
            cnt[Node] += cnt[child];
        }
    }
}
 
void solve(){
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i <= N; i++){
        depth[i].clear();
        adj[i].clear();
    }
    for (int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs_init(1, 0, 0);
    for (int q = 1; q <= Q; q++){
        vector<int> v;
        int K, M;
        cin >> K >> M;
        for (int i = 1; i <= N; i++) cnt[i] = 0;
        for (int i = 1; i <= M; i++){
            int x;
            cin >> x;
            cnt[x] = 1;
        }
        dfs(1, 0);
        int l = 0, r = N, dep = 0;
        while (l <= r){
            int mid = l + (r - l) / 2;
            bool good = false;
            for (int u : depth[mid])
                if (cnt[u] >= K) good = true;
            if (good){
                dep = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        int ans = 0;
        for (int u : depth[dep])
            if (cnt[u] >= K) ans++;
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