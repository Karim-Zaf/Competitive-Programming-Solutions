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
const int N_Max = 5e4 + 5;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
vector<int> adj[N_Max];
int dp[N_Max][64][2];
int a[N_Max];
int N, K;
 
void dfs(int Node, int par){
    vector<pair<int, int>> tmp(64);
    dp[Node][a[Node]][0] = 0;
    dp[Node][a[Node]][1] = 1;
    for (int child : adj[Node]){
        if (child == par) continue;
        dfs(child, Node);
        for (int i = 0; i <= 63; i++) tmp[i] = {-1, -1};
        for (int i = 0; i <= 63; i++){
            if (dp[Node][i][0] != -1) continue;
            for (int j = 0; j <= 63; j++){
                if (dp[child][j][0] == -1) continue;
                if (dp[Node][(i ^ j)][0] != -1){
                    tmp[i] = {child, j};
                    break;
                }
            }
        }
        for (int i = 0; i <= 63; i++){
            if (tmp[i].F != -1){
                dp[Node][i][0] = tmp[i].F;
                dp[Node][i][1] = tmp[i].S;
            }
        }
    }
}
 
void solve(){
    cin >> N >> K;
    for (int i = 1; i <= N; i++){
        adj[i].clear();
        for (int j = 0; j <= 63; j++) dp[i][j][0] = dp[i][j][1] = -1;
    }
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    int root = -1;
    for (int i = 1; i <= N; i++){
        if (dp[i][K][0] != -1){
            root = i;
            break;
        }
    }
    if (root == -1){
        cout << "No" << endl;
        return;
    }
    vector<int> ans;
    queue<pair<int, int>> q;
    q.push({root, K});
    while (!q.empty()){
        auto [Node, x] = q.front();
        q.pop();
        ans.pb(Node);
        assert(dp[Node][x][0] != -1);
        while (dp[Node][x][0] > 0){
            q.push({dp[Node][x][0], dp[Node][x][1]});
            x ^= dp[Node][x][1];
            assert(dp[Node][x][0] != -1);
        }
        assert(a[Node] == x);
    }
    int x = 0;
    for (int u : ans) x ^= a[u];
    cout << "Yes" << endl;
    cout << (int)ans.size() << endl;
    for (int u : ans) cout << u << " ";
    cout << endl;
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