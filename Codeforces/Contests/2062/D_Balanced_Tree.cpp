/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> graph[N], dp(N), val(N);
vector<pair<int,int>> vp;
int n;

void dfs(int curr, int parent = 0){
    val[curr] = vp[curr].F;
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs(child, curr);
        val[curr] = max(val[curr], val[child]);
    }
    val[curr] = min(val[curr], vp[curr].S);

    for (auto child : graph[curr]){
        if (child == parent) continue;
        dp[curr] += max(0ll, val[child] - val[curr]);
        dp[curr] += dp[child];
    }
}

void init(){
    for (int i = 0; i <= n + 4; ++i){
        val[i] = dp[i] = 0;
        graph[i].clear();
    }
    vp.resize(n + 5);
}

void Solve(){
    cin >> n;
    init();

    for (int i = 1; i <= n; ++i){ cin >> vp[i].F >> vp[i].S; }
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1);
    cout << val[1] + dp[1] << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
