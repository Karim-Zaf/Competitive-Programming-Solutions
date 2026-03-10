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
 
vector<int> adj[N_Max];
int color[N_Max], par[N_Max];
int sz[N_Max], glob[N_Max], freq[N_Max];
 
void dfs(int Node){
    sz[Node] = 1;
    for (int child : adj[Node]){
        if (child != par[Node]){
            par[child] = Node;
            dfs(child);
            sz[Node] += sz[child];
        }
    }
}
 
void get(int Node){
    freq[color[Node]]++;
    for (int child : adj[Node])
        if (child != par[Node]) get(child);
}
 
void solve(){
    int N;
    cin >> N;
    vector<pair<int, int>> edges;
    for (int i = 1; i <= N; i++){
        adj[i].clear();
        freq[i] = 0;
        glob[i] = 0;
    }
    for (int i = 1; i <= N; i++){
        cin >> color[i];
        glob[color[i]]++;
    }
    for (int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.push_back({u, v});
    }
    dfs(1);
    pair<int, int> edge = {-1, -1};
    for (auto x : edges){
        int u = x.F, v = x.S;
        if (par[v] != u) swap(u, v);
        assert(par[v] == u);
        if (sz[v] == N / 2){
            edge = {u, v};
            break;
        }
    }
    if (edge.F == -1){
        cout << -1 << endl;
        return;
    }
    get(edge.S);
    int diff = 0, sum1 = 0, sum2 = 0;
    for (int i = 1; i <= N; i++){
        int c = i, occ = freq[i];
        int other = glob[c] - occ;
        if (abs(occ - other) % 2){
            cout << -1 << endl;
            return;
        }
        if (occ - other >= 0){
            sum1 += (occ - other) / 2;
            diff += abs(occ - other) / 2;
        }
        else{
            sum2 += (other - occ) / 2;
            diff -= abs(occ - other) / 2;
        }
    }
    if (diff || sum1 != sum2){
        cout << -1 << endl;
        return;
    }
    assert(sum1 == sum2);
    cout << sum1 << endl;
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