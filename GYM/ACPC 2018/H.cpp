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

vector<pair<int, int>> adj[N_Max];
vector<array<int, 3>> edges;
int dist[N_Max];
int N, M, u, L, K;

bool work(int x){
    for (int i = 1; i <= N; i++) dist[i] = 1e9;
    set<pair<int, int>> st;
    dist[u] = 0;
    st.insert({0, u});
    while (!st.empty()){
        auto [d, Node] = *st.begin();
        st.erase(st.begin());
        if (dist[Node] < d) continue;
        for (auto [child, w] : adj[Node]){
            if (w >= x) continue;
            if (d + 1 < dist[child]){
                dist[child] = d + 1;
                st.insert({dist[child], child});
            }
        }
    }
    for (auto [a, b, w] : edges){
        if (w < x) continue;
        int mn = min(dist[a], dist[b]);
        if (mn < K) return true;
    }
    return false;
}

void solve(){
    cin >> N >> M >> u >> L >> K;
    edges.clear();
    for (int i = 1; i <= N; i++) adj[i].clear();
    for (int i = 1; i <= M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    int l = 1, r = 1e9, ans = 0;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (work(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
}

int main(){
    FAST
    freopen("path.in","r",stdin);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}
