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

vector<int> graph[N], a(N);

int n, c;
int dp[N][2];

void dfs(int curr, int parent = -1) {
    for (auto child : graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
    }
    dp[curr][1] = dp[curr][0] = 0;


    dp[curr][1] = max(0ll, a[curr]);
    for (auto child : graph[curr]) {
        if (child == parent) continue;
        dp[curr][1] += max({0ll, dp[child][0], dp[child][1] - 2 * c});
        dp[curr][0] += max({0ll, dp[child][0], dp[child][1] });
    }

}

void Solve() {
    cin >> n >> c;

    for (int i = 1; i <= n; i++) graph[i].clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1);
    cout << max(dp[1][1], dp[1][0]) << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
