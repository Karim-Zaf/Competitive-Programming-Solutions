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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

vector<int> graph[N], a(N), b(N), c(N), expected(N), have(N), dp(N);

int dfs(int curr, int parent = 0, int mn = INF) {

    int &ret = dp[curr];
    mn = min(mn, a[curr]);

    for (auto child: graph[curr]) {
        if (child == parent) continue;
        ret += dfs(child, curr, mn);

        expected[curr] += expected[child];
        have[curr] += have[child];
    }
    if (b[curr] != c[curr]) {
        have[curr] += b[curr];
        expected[curr] += c[curr];
    }
    int nb = min(expected[curr], have[curr]);
    expected[curr] -= nb;
    have[curr] -= nb;
    ret += nb * 2 * mn;

    return ret;
}

void Solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int ans = dfs(1);
    cout << (expected[1] == have[1] ? ans : -1) << endl;
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