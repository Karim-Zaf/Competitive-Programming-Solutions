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
#define endl '\n'
#define int ll

const int N = 4e5 + 30, mod = 1e18 + 7, INF = 1e18 + 10;

vector<int> graph[N], sz(N);
vector<int> ans, dp(N), suff(N);
int timer = 0, tin[N];
vector<int> at;
vector<pair<int, int>> queries[N];
vector<int> depth(N);
int up[N][30];
int n;

void dfs(int curr, int parent = 0){
    sz[curr] = 1;
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs(child, curr);
        sz[curr] += sz[child];
    }
}

void dfs_LCA(int parent){
    for (int i = 1; i < 28; i++)
        up[parent][i] = up[up[parent][i - 1]][i - 1];

    for (auto child : graph[parent]){
        if (up[parent][0] == child)continue;
        depth[child] = depth[parent] + 1;
        up[child][0] = parent;
        dfs_LCA(child);
    }
}

int Binary_Lifting(int a, int k){
    for (int i = 28; i >= 0; i--)
        if (k & (1 << i))
            a = up[a][i];
    return a;
}

int Lca(int a, int b){
    if (depth[b] > depth[a]) swap(a, b);

    int k = depth[a] - depth[b];
    a = Binary_Lifting(a, k);
    if (a == b) return a;

    for (int i = 28; i >= 0; i--){
        if (up[a][i] == up[b][i]) continue;
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}

int bs(int curr, int value){
    int l = 0, r = depth[curr], ans = -1;

    while (l <= r){
        int md = l + (r - l) / 2;

        int vertex = Binary_Lifting(curr, md);
        if (suff[curr] - suff[vertex] <= value){
            l = md + 1;
            ans = vertex;
        }
        else
            r = md - 1;
    }

    value -= (suff[curr] - suff[ans]);
    int ret = at[tin[ans] + value];

    return ret;
};

void dfs2(int curr, int parent = 0){
    dp[curr] = 1;
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs2(child, curr);
        dp[curr] = dp[curr] + 1 + dp[child];
        dp[curr] = min(dp[curr], (int)2e9);
    }
}

void dfs4(int curr, int parent = 0){
    suff[curr] = dp[curr] + suff[parent];
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs4(child, curr);
    }
}

/*---------------------------------------EulerTour----------------------------------------------*/

void Euler_Tour(int curr, int parent = 0){
    tin[curr] = ++timer;
    at.push_back(curr);
    for (auto child : graph[curr])
        if (child != parent){
            Euler_Tour(child, curr);
            ++timer;
            at.push_back(curr);
        }
}

int q;

void prep(){
    ans.resize(q + 1);
    fill(all(ans), 0);
    timer = 0;
    at.clear();
    at.push_back(0);
    for (int i = 0; i <= n; i++){
        graph[i].clear();
        queries[i].clear();
        suff[i] = 0 ;
    }
    graph[0].push_back(1);
}

void Solve(){
    cin >> n;
    cin >> q;
    prep();

    for (int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        if (l) graph[i].push_back(l);
        if (r) graph[i].push_back(r);
    }

    dfs(1);
    Euler_Tour(1);
    dfs_LCA(1);
    dfs2(1);
    dfs4(1);

    for (int i = 1; i <= q; i++){
        int v, k;
        cin >> v >> k;
        ans[i] = bs(v, k);
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << " ";
    cout << endl;
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
