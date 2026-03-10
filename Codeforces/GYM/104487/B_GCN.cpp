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

vector<int> adj[N_Max];
int sz[N_Max], parent[N_Max];

void dfs(int Node, int par){
    sz[Node] = 1;
    for (int child : adj[Node]){
        dfs(child, Node);
        sz[Node] += sz[child];
    }
}

void solve(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) adj[i].clear();
    for (int i = 2; i <= N; i++){
        cin >> parent[i];
        adj[parent[i]].pb(i);
    }
    dfs(1, 0);
    ll res = 0;
    for (int Node = 1; Node <= N; Node++){
        ll val = (ll)(sz[Node] - 1) * 1LL * (N - sz[Node] + 1) % mod;
        ll s = sz[Node] - 1;
        for (int child : adj[Node]){
            s -= sz[child];
            ll y = s * (ll)sz[child] % mod;
            val = (val + y) % mod;
        }
        val = (val + (N - sz[Node])) % mod;
        ll nb = val * (val - 1) % mod;
        nb = nb * inv(2) % mod;
        res = (res + nb) % mod;
    }
    cout << res << endl;
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