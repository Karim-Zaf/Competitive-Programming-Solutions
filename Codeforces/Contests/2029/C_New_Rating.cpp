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

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n + 5);
    int dp[2][n + 5];

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) dp[1][i] = dp[0][i] = -INF;

    dp[0][0] = dp[1][0] = -INF;
    int ans = 0, x = 0;
    for (int i = 1; i <= n; i++) {
        int add = 0;
        if (x < v[i]) add = 1;
        else if (x > v[i]) add = -1;
        x += add;

        if (i < n) ans = max(ans, x);

        dp[0][i] = max(x, dp[0][i - 1]);

        if (i >= 2) {
            int prev = dp[0][i - 2];
            add = 0;
            if (prev < v[i]) add = 1;
            else if (prev > v[i]) add = -1;
            prev += add;
            dp[1][i] = max(prev, dp[1][i]);


            add = 0;
            if (dp[1][i - 1] < v[i]) add++;
            else if (dp[1][i - 1] > v[i]) add--;

            dp[1][i] = max(dp[1][i], dp[1][i - 1] + add);
        }


        // kar(i, dp[0][i], dp[1][i]);
    }
    cout << max(dp[1][n], ans) << endl;
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
