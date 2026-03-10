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
const int N_Max = 5e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
vector<int> adj[N_Max], pos[N_Max];
int c[N_Max], in_deg[N_Max];
int ans[N_Max];
int N, M, K;
 
void solve(){
    cin >> N >> K >> M;
    for (int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for (int i = 1; i <= N * K; i++){
        cin >> c[i];
        pos[c[i]].pb(i);
    }
    for (int i = 1; i <= N; i++) reverse(pos[i].begin(), pos[i].end());
    for (int id = 1; id <= K; id++){
        set<pair<int, int>> s;
        for (int i = 1; i <= N; i++)
            for (int u : adj[i]) in_deg[u]++;
        for (int i = 1; i <= N; i++){
            if (!in_deg[i]){
                assert(!pos[i].empty());
                s.insert({pos[i].back(), i});
                pos[i].pop_back();
            }
        }
        while (!s.empty()){
            auto [ind, Node] = *s.begin();
            s.erase(s.begin());
            ans[ind] = id;
            for (int child : adj[Node]){
                in_deg[child]--;
                if (!in_deg[child]){
                    assert(!pos[child].empty());
                    s.insert({pos[child].back(), child});
                    pos[child].pop_back();
                }
            }
        }
    }
    for (int i = 1; i <= N * K; i++) cout << ans[i] << " ";
    cout << endl;
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