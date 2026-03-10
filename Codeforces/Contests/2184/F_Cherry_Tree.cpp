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

vector<array<int, 3>> dp(N);
vector<int> leafs(N);
vector<int> graph[N];

void dfs(int curr, int parent = -1){
    int cnt = 0;
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs(child, curr);
        cnt++;
        for (int j : {1, 2, 0}) dp[curr][j] += (dp[child][j] != 0);
        leafs[curr] += leafs[child];
    }

    if (dp[curr][2] >= 2) dp[curr][1]=max(dp[curr][1],1ll);
    if (dp[curr][1] >= 2) dp[curr][2]++;

    if (!cnt) leafs[curr] = 1;
    dp[curr][((leafs[curr] % 3 - 1) % 3 + 3) % 3]=1;
}

void prep(int n){
    for (int i = 1; i <= n; i++){
        graph[i].clear();
        for (int j : {1, 2, 0})
            dp[i][j] = 0;
        leafs[i] = 0;
    }
}

void Solve(){
    int n;
    cin >> n;
    prep(n);
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1);

    if (dp[1][leafs[1] % 3]) cout << "YES\n";
    else cout << "NO\n";
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
