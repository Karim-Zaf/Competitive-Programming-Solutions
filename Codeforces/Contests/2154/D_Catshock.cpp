/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)
#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> depth(N), par(N), sz(N);

set<int> leafs[2];
set<int> graph[N];
vector<int> ans, gammer(N), is_child(N);

int n;

void er(int x){
    if (x == n)return;
    if (leafs[depth[x] % 2].find(x) != leafs[depth[x] % 2].end()){ leafs[depth[x] % 2].erase(x); }
    for (auto child : graph[x]){
        graph[child].erase(x);
        if (graph[child].size() <= 1) leafs[depth[child] % 2].insert(child);
    }
}

void dfs(int curr, int parent = 0){
    par[curr] = parent;
    depth[curr] = depth[parent] + 1;
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs(child, curr);
        sz[curr] += sz[child];
        is_child[curr] |= is_child[child];
    }
    if (graph[curr].size() <= 1) leafs[(depth[curr] % 2) ^ 1].insert(curr);

    is_child[curr] |= (curr == n);
    if (is_child[curr])return;
    if (sz[curr] >= sz[gammer[depth[curr]]])
        gammer[depth[curr]] = curr;
}

void prep(){
    for (int i = 0; i <= n; i++) graph[i].clear();
    for (int i = 0; i <= n; i++) gammer[i] = 0;
    for (int i = 0; i <= n; i++)sz[i] = 1;
    for (int i = 0; i <= n; i++)depth[i] = is_child[i] = 0;

    leafs[0].clear();
    leafs[1].clear();
    ans.clear();
}

void Solve(){
    cin >> n;
    prep();

    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) depth[i]--;

    int sz = ans.size() % 2;

    while (graph[n].size() >= 1){
        sz ^= 1;

        if (!leafs[sz].empty()){
            int curr = *leafs[sz].begin();

            er(curr);
            if (curr != n){
                ans.pb(curr);
                ans.pb(-1);
            }
            else
                ans.pb(-1);
        }
        else ans.pb(-1);
    }

    cout << ans.size() << endl;
    for (auto x : ans){
        if (x != -1) cout << "2 " << x << endl;
        else cout << "1 " << endl;
    }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
