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

vector<int> graph[N];
vector<int> depth(N), max_depth(N), sum(N), a(N);
int dp[N][2];
int n;

void dfs1(int curr, int parent = 0){
    depth[curr] = depth[parent] + 1;
    sum[curr] = a[curr];
    max_depth[curr] = depth[curr];
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs1(child, curr);
        max_depth[curr] = max(max_depth[curr], max_depth[child]);

        sum[curr] += sum[child];
    }
}

void dfs2(int curr, int parent = 0){
    int sum_dp_0 = 0;
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs2(child, curr);
        sum_dp_0 += dp[child][0];
    }
    dp[curr][0] = sum_dp_0 + sum[curr];
    dp[curr][1] = dp[curr][0];

    for (auto child : graph[curr]){
        if (child == parent) continue;

        int curr_sum_dp_0 = sum_dp_0;
        curr_sum_dp_0 -= dp[child][0];

        dp[curr][1] = max(dp[curr][1], curr_sum_dp_0 + sum[curr] + dp[child][1]);
    }

    multiset<int> s;
    for (auto child : graph[curr]){
        if (child == parent) continue;
        s.insert(max_depth[child]);
    }

    for (auto child : graph[curr]){
        if (child == parent) continue;

        s.erase(s.find(max_depth[child]));
        if (s.empty()){
            s.insert(max_depth[child]);
            continue;
        }

        int mx_dep = *prev(s.end());
        int curr_sum_dp_0 = sum_dp_0;
        curr_sum_dp_0 += (mx_dep - depth[curr]) * sum[child];

        dp[curr][1] = max(dp[curr][1], curr_sum_dp_0 + sum[curr]);

        s.insert(max_depth[child]);
    }
}

void prep(){
    for (int i = 0; i <= n; i++){
        graph[i].clear();
        depth[i] = max_depth[i] = sum[i] = a[i] = dp[i][0] = dp[i][1] = 0;
    }
}

void Solve(){
    cin >> n;
    prep();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; i++) cout << max(dp[i][1], dp[i][0]) - sum[i] << " ";
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
