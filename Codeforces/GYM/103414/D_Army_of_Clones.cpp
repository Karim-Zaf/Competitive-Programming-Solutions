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
 
void solve(){
    int N, M, x;
    cin >> N >> M;
    vector<int> a(N + 1), dist(N + 1, 2e9);
    for (int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> x;
    for (int i = 1; i <= N; i++) cin >> a[i];
    set<pair<int, int>> s;
    dist[1] = (x <= a[1]);
    s.insert({dist[1], 1});
    while (!s.empty()){
        auto [cnt, Node] = *s.begin();
        s.erase(s.begin());
        if (dist[Node] < cnt) continue;
        for (int child : adj[Node]){
            int val = 0;
            if (cnt < 30) val = (x >> cnt);
            int curr = cnt + (val <= a[child]);
            if (curr < dist[child]){
                dist[child] = curr;
                s.insert({dist[child], child});
            }
        }
    }
    if (dist[N] >= 30) cout << 0 << endl;
    else cout << (x >> dist[N]) << endl;
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