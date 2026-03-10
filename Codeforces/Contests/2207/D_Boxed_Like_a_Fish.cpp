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

vector<vector<int>> graph;
vector<set<int>>  s;
int n, k, v;

vector<int> dp, depth;

void dfs(int curr,int indx = 0, int parent = 0){
    depth[curr] = depth[parent] + 1;
    indx %= k;

    vector<int> dist {INF,INF};
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs(child, indx + 1, curr);

        int mn = INF;
        if (!s[child].empty()) mn = *s[child].begin();

        dist.push_back(mn);
        sort (all(dist));
        while (dist.size()> 2) dist.pop_back();
        if (s[curr].size() < s[child].size())swap(s[curr], s[child]);
        for (auto x : s[child])s[curr].insert(x);
    }

    if (graph[curr].size()== 1) dp[curr]=1 ;

    int distance = accumulate(all(dist),0ll);
    distance -= 2*depth[curr];
    distance --;

    dp[curr]|= (distance<= k) ;

    if (dp[curr]) s[curr].insert(depth[curr]) ;
}

void Solve(){
    cin >> n >> k >> v;

    graph.assign(n + 1, {});
    dp.assign(n + 1, {});
    depth.assign(n + 1, {});
    s.assign(n + 1, {});

    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(v);
    cout << (dp[v] ? "Yes" : "No") << endl;
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
