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
 
const int M = 5005;
 
int mask[M][M];
vector<pair<int,int>> adj[M], adj_rev[M];
int dp[M][M];
 
void work(int u, int v){
    if (dp[u][v] != -1) return;
 
    dp[u][v] = 1;
    
    for (auto [uprime, masku] : adj_rev[u]){
        for (auto [vprime, maskv] : adj[v]){
            if ((masku & maskv)) work(uprime, vprime);
        }
    }
}
 
void Solve(){
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
 
    for (int i = 1, u, v; i <= m; i++){
        char c;
        cin >> u >> v >> c;
        mask[u][v] |= (1 << (c - 'a'));
    }
 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (mask[i][j]){
                adj[i].pb({j, mask[i][j]});
                adj_rev[j].pb({i, mask[i][j]});
            }
        }
    }
 
    
    for (int i = 1; i <= n; i++){
        work(i, i);
        for (int j = 1; j <= n; j++)
        if (mask[i][j]) work(i, j);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) ans += (dp[i][j] == 1);
    cout << ans << endl;
}
 
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}