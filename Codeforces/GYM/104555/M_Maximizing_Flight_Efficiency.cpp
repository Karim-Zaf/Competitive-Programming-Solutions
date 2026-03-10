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
const int N_Max = 105;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

vector<pair<int, int>> adj[N_Max];
int dist[N_Max][N_Max];
int N;

int dijkstra(int src, int target){
    vector<int> dp(N + 1, 2e9);
    dp[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty()){
        auto [d, Node] = *s.begin();
        s.erase(s.begin());
        if (d > dp[Node]) continue;
        for (auto [child, w] : adj[Node]){
            if (Node == src && child == target) continue;
            if (d + w < dp[child]){
                dp[child] = d + w;
                s.insert({dp[child], child});
            }
        }
    }
    return dp[target];
}

void solve(){
    cin >> N;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            int w;
            cin >> w;
            mp[{i, j}] = w;
            if (i != j)
                adj[i].push_back({j, w});
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++){
        for (int j = i + 1; j <= N; j++){
            dist[i][j] = dist[j][i] = dijkstra(i, j);
            if (dist[i][j] < mp[{i, j}]){
                cout << -1 << endl;
                return;
            }
            if (dist[i][j] == mp[{i, j}]) ans++;
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