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
int dp[N][65], suff[N][65];
int pref[N][65];

void dfs(int curr, int parent = -1) {
    for (auto child : graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
    }

    for (int i = 1; i <= 60; i++) dp[curr][i] = INF;

    for (int i = 1; i <= 60; i++) {
        dp[curr][i] = i * a[curr];

        for (auto child : graph[curr]) {
            if (child == parent) continue;
            dp[curr][i] += min(pref[child][i - 1], suff[child][i + 1]);
        }
    }
    for (int i = 1; i <= 60; i++) {
        pref[curr][i] = min(dp[curr][i], pref[curr][i - 1]);
    }
    for (int i = 60; i >= 1; i--) {
        suff[curr][i] = min(dp[curr][i], suff[curr][i + 1]);
    }
}

void Solve() {
    int n;


    cin >> n;
    for (int i = 1; i <= n; i++) graph[i].clear();
    for (int i = 0; i <= n; i++) for (int j = 0; j < 65; j++) dp[i][j] = suff[i][j] = pref[i][j] = INF;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1);

    int ans = INF;
    for (int i = 1; i <= 60; i++) ans = min(ans, dp[1][i]);
    cout << ans << endl;
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
