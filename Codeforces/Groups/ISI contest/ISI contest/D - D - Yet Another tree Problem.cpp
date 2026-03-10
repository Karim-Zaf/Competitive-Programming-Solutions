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

const ll N = 1e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<pair<int, int>> graph[N];
int n, k, x;
ll dp[N][205];


void dfs(int curr, int parent = 0) {

    vector<ll> sum(k + 5);

    for (auto [child, val]: graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);

        sum[0] += dp[child][k] + val;
        for (int i = 1; i <= k; i++)
            sum[i] += min(val + dp[child][k], max(0ll, (ll)val - x) + dp[child][i - 1]);

    }

    for (auto [child, val]: graph[curr]) {
        if (child == parent) continue;

        for (int i = 1; i <= k; i++) {
            ll mabe = dp[child][i - 1];
            mabe += max(0ll, (ll)val - x);
            int opp = max(0ll, min(i, k - i));
            mabe += sum[opp] - min(val + dp[child][k], max(0ll, (ll)val - x) + dp[child][opp-1]);
            dp[curr][i] = min(dp[curr][i], mabe);
        }
    }

    dp[curr][0] = sum[0] ;
    for (int i = 1; i <= k; i++)
        dp[curr][i] = min(dp[curr][i], dp[curr][i - 1]);
}

void Solve() {
    cin >> n >> k >> x;
    for (int i = 1, u, v, val; i < n; i++) {
        cin >> u >> v >> val;
        graph[u].pb({v, val});
        graph[v].pb({u, val});
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 205; j++)
            dp[i][j] = INF;

    dfs(1);
    ll ans = INF;
    for (int i = 0; i <= k; i++) ans = min(ans, dp[1][i]);
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}