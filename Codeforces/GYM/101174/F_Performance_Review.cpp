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
const int N_Max = 1e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
vector<array<ll, 3>> st[4 * N_Max];
vector<int> adj[N_Max];
int t[N_Max], rk[N_Max], par[N_Max];
int tour[N_Max], tin[N_Max], sz[N_Max];
int timer = 1;
 
void dfs(int Node){
    tour[timer] = Node;
    tin[Node] = timer++;
    for (int child : adj[Node]){
        if (child != par[Node]){
            dfs(child);
            sz[Node] += sz[child] + 1;
        }
    }
}
 
void merge(int id, int l, int r){
    int i = 0, j = 0;
    while (i < (int)st[l].size() && j < (int)st[r].size()){
        if (st[l][i][0] < st[r][j][0]) st[id].push_back(st[l][i++]);
        else st[id].push_back(st[r][j++]);
    }
    while (i < (int)st[l].size()) st[id].push_back(st[l][i++]);
    while (j < (int)st[r].size()) st[id].push_back(st[r][j++]);
    for (int p = 1; p < (int)st[id].size(); p++)
        st[id][p][2] = st[id][p][1] + st[id][p - 1][2];
}
 
void build(int id, int ns, int ne){
    if (ns == ne){
        st[id].push_back({rk[tour[ns]], t[tour[ns]], t[tour[ns]]});
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id + 1;
    int rc = 2 * id + 2;
    build(lc, ns, mid);
    build(rc, mid + 1, ne);
    merge(id, lc, rc);
}
 
ll query(int id, int ns, int ne, int l, int r, int s){
    if (l > ne || r < ns) return 0;
    if (ns >= l && ne <= r){
        array<ll, 3> p = {s, 0, 0};
        int ind = upper_bound(st[id].begin(), st[id].end(), p) - st[id].begin();
        if (ind > 0){
            ind--;
            return st[id][ind][2];
        }
        return 0;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id + 1;
    int rc = 2 * id + 2;
    return query(lc, ns, mid, l, r, s) + query(rc, mid + 1, ne, l, r, s);
}
 
void solve(){
    int N;
    cin >> N;
    int root = -1;
    for (int i = 1; i <= N; i++){
        cin >> par[i] >> rk[i] >> t[i];
        if (par[i] == -1){
            root = i;
            continue;
        }
        adj[i].pb(par[i]);
        adj[par[i]].pb(i);
    }
    dfs(root);
    build(1, 1, N);
    for (int i = 1; i <= N; i++){
        int l = tin[i], r = l + sz[i];
        cout << query(1, 1, N, l, r, rk[i]) << endl;
    }
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