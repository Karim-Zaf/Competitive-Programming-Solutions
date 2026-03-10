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

int dp[N][15];

void Solve() {


    int n, k;
    cin >> n >> k;


    for (int i = 0; i <= n + 10; i++) {
        for (int j = 0; j <= 11; j++) {
            if (i == 0) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }

    vector<int> v(n + 1), pref(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = pref[i - 1] + v[i];
    }

    for (int i = 1; i <= n; i++) {


        for (int j = 0; j <= 10; j++) {
            int mn = v[i];

            for (int jj = i; jj >= max(1ll, i - j); jj--) mn = min(mn, v[jj]);


            for (int op = 0; op <= 10; op++) {
                if (j + op <= k) {
                    if (i - j - 1 >= 0) {
                        int curr = dp[i - j - 1][op] + (j + 1) * mn;
                        dp[i][j + op] = min(dp[i][j + op], curr);
                        if (i == n && j == k) {
                            kar (mn);
                        }
                    }
                }
            }
        }

        for (int j = 1; j <= 10; j++) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }
    kar (dp[n][1]);
    cout << dp[n][k] << endl;
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