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

const int N = 30, mod = 1e9 + 7, INF = 1e18 + 10;

map<string, vector<int>> a, b;
int mx = 0;


set<int> graph2[20];
vector<int> graph[20], vis(20);

int dp[20][1 << 20];

int dfs(int curr, int mask) {
    int &ret = dp[curr][mask];
    if (ret != -1) return ret;
    ret = 1;
    kar (curr) ;
    for (auto child: graph[curr]) {
        if (mask & (1 << child)) continue;
        ret = max(ret, 1 + dfs(child, mask + (1 << child)));
    }

    return ret;
}

void Solve() {
    int n;
    cin >> n;
    a.clear();
    b.clear();
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        graph2[i].clear();
        for (int j = 0; j < (1 << (n + 1)); j++) dp[i][j] = -1;
    }

    for (int i = 1; i <= n; i++) {
        string aa, bb;
        cin >> aa >> bb;
        a[bb].pb(i);
        b[aa].pb(i);
    }

    for (auto st: a) {
        for (auto one: st.S)
            for (auto two: st.S) {
                if (one == two) continue;
                graph2[one].insert(two);
                graph2[two].insert(one);
            }
    }
    for (auto st: b) {
        for (auto one: st.S)
            for (auto two: st.S) {
                if (one == two) continue;
                graph2[one].insert(two);
                graph2[two].insert(one);
            }
    }
    for (int i = 1; i <= n; i++)
        for (auto x: graph2[i])graph[i].pb(x);


    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vis.clear();
        dfs(i, 1 << i);
        ans = max(ans, mx);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << (n + 1)); j++) ans = max(ans, dp[i][j]);
    }
    cout << n - ans << endl;

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}