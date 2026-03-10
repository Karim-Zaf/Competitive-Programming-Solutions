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
#define endl '\n'
#define int ll

const int N = 2e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

ll dp[52][N];


void Solve() {
    int m, x, sum = 0, ans = 0;
    cin >> m >> x;

    vector<pair<ll, ll>> vp(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> vp[i].F >> vp[i].S;
        sum += vp[i].S + 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= sum; j++)
            dp[i][j] = INF;
    }

    for (int i = 1; i <= m; i++) {
        auto [c, h] = vp[i];

        for (int s = 0; s <= sum && i != 1; s++) {

            ll fadhel = x * (i - 1) - dp[i-1][s];

            if (fadhel >= c) {
                dp[i][s + h] = min(dp[i][s + h], dp[i-1][s] + c);
            }
        }

        if (x * (i - 1) - c >= 0) {
            dp[i][h] = min(dp[i][h], c);
        }

        for (int s = 0; s <= sum && i != 1; s++) {
            dp[i][s] = min(dp[i][s], dp[i - 1][s]);
            if (dp[i][s] != INF) {
                ans = max(ans, s);
            }
        }
    }

    cout << ans << endl;
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