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
const int N_Max = 2e6 + 7;
const int Nax = 2e5 + 5;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
vector<pair<int, int>> vec[N_Max];
vector<ll> pref[N_Max];
vector<int> adj[N_Max];
int depth[N_Max];
bool prime[Nax];
int tour[N_Max];
int tout[N_Max];
int tin[N_Max];
int a[N_Max];
ll dp[N_Max];
int timer;
int N, Q;
 
void init(){
    timer = 0;
    for (int i = 0; i <= N; i++){
        adj[i].clear();
        vec[i].clear();
        pref[i].clear();
    }
}
 
void dfs_init(int Node){
    tour[++timer] = Node;
    tin[Node] = timer;
    dp[Node] = a[Node];
    vec[depth[Node]].push_back({tin[Node], Node});
    for (int child : adj[Node]){
        depth[child] = depth[Node] + 1;
        dfs_init(child);
        dp[Node] += dp[child];
    }
    tout[Node] = timer;
}
 
void solve(){
    cin >> N;
    init();
    for (int i = 1; i <= N; i++){
        cin >> a[i];
        if (!prime[a[i]]) a[i] = 0;
    }
    for (int i = 2; i <= N; i++){
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    dfs_init(1);
    for (int dep = 0; dep < N; dep++){
        if (vec[dep].empty()) continue;
        int sz = (int)vec[dep].size();
        pref[dep].resize(sz);
        pref[dep][0] = dp[vec[dep][0].S];
        for (int i = 1; i < sz; i++)
            pref[dep][i] = pref[dep][i - 1] + dp[vec[dep][i].S];
    }
    cin >> Q;
    for (int q = 1; q <= Q; q++){
        int u, d;
        cin >> u >> d;
        int dep = depth[u] + d;
        if (dep > N){
            cout << 0 << " ";
            continue;
        }
        int l = lower_bound(vec[dep].begin(), vec[dep].end(), make_pair(tin[u], 0)) - vec[dep].begin();
        int r = lower_bound(vec[dep].begin(), vec[dep].end(), make_pair(tout[u] + 1, 0)) - vec[dep].begin() - 1;
        if (l > r){
            cout << 0 << " ";
            continue;
        }
        cout << pref[dep][r] - (l > 0 ? pref[dep][l - 1] : 0) << " ";
    }
    cout << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    for (int i = 2; i < Nax; i++) prime[i] = true;
    for (int i = 2; i < Nax; i++){
        if (!prime[i]) continue;
        for (int j = i + i; j < Nax; j += i) prime[j] = false;
    }
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}