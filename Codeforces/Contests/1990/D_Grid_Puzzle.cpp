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
    vector<int> v(n + 1), dp(n + 1, 1e8);
    for (int i = 1; i <= n; i++) cin >> v[i];
    dp[0] = 0;

    vector<int> pref(n + 1, INF);
    for (int i = 1; i <= n; i++) {
        if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + (max(v[i], v[i - 1]) + 1) / 2);
        dp[i] = min(dp[i], dp[i - 1] + 1);
        if (!v[i]) dp[i] = min(dp[i], dp[i - 1]);

        if (v[i] == 3 || v[i] == 4) {
            pref[i] = min(i, pref[i - 1]);
        }

        if (v[i] <= 2) {

            int curr = pref[i - 1];
            if (curr == INF || curr - 1 < 1) continue ;
            if (v[curr - 1] <= 2) {
                int cnt = i - curr + 1;
                if (cnt % 2 == 0) continue ;
                dp[i] = min(dp[i], (curr - 2 >= 0 ? dp[curr - 2] : 0) + (cnt + 1) / 2 * 2 - 1);
            }
        }
    }

    cout << dp[n] << endl;
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
