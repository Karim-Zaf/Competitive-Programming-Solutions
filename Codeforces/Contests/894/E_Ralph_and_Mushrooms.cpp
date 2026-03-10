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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> pref(N), dp(N, -1), val(N);

void prep(){
    for (int i = 1; i < N; i++)
        pref[i] = pref[i - 1] + i * (i + 1) / 2;
}

int get(int x){
    int l = 0, r = N, ret = -1;

    while (l <= r){
        int md = (l + r) / 2;
        if (md * (md + 1) / 2 <= x){
            ret = md;
            l = md + 1;
        }
        else{ r = md - 1; }
    }

    return (ret + 1) * x - pref[ret];
}

/* Strongly Connected Component - SCC -  Kosaraju*/

int n, m, nw_n = 0;
vector<pair<int,int>> graph[N], graph_rev[N], nw_graph[N];
vector<array<int, 3>> edges;
vector<int> order, cycle, vis(N), id(N);

void dfs(int curr){
    vis[curr] = true;
    for (auto [child,val] : graph[curr]){
        if (vis[child]) continue;
        dfs(child);
    }
    order.push_back(curr);
}

void dfs_rev(int curr){
    vis[curr] = true;
    for (auto [child,val] : graph_rev[curr]){
        if (vis[child]) continue;
        dfs_rev(child);
    }
    cycle.push_back(curr);
}

void strongly_connected_components(){
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;
        dfs(i);
    }

    reverse(all(order));
    for (int i = 1; i <= n; i++)vis[i] = 0;

    nw_n = 0;
    for (auto Node_st : order){
        if (vis[Node_st]) continue;
        cycle.clear();
        dfs_rev(Node_st);

        nw_n++;
        for (auto Node : cycle)id[Node] = nw_n;
    }
    for (auto [u,v,x] : edges){
        if (id[u] != id[v]){
            nw_graph[id[u]].push_back({id[v], x});
            continue;
        }

        // for this problem
        val[id[u]] += get(x);
    }
    for (int i = 1; i <= nw_n; i++) vis[i] = 0;
}

void dfs_res(int curr){
    if (dp[curr] != -1) return;
    dp[curr] = 0;
    for (auto [child,x] : nw_graph[curr]){
        dfs_res(child);
        dp[curr] = max(dp[curr], dp[child] + x);
    }
    dp[curr] += val[curr];
}

void Solve(){
    prep();
    cin >> n >> m;
    for (int i = 1, u, v, x; i <= m; i++){
        cin >> u >> v >> x;
        edges.push_back({u, v, x});
        graph[u].pb({v, x});
        graph_rev[v].pb({u, x});
    }
    strongly_connected_components();
    int s;
    cin >> s;
    dfs_res(id[s]);

    cout << *max_element(all(dp)) << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}