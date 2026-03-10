/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> t(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> t[i][j];
    int dp[2][n + 2][m + 2];
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            dp[0][i][j] = dp[1][i][j] = -INF;;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i > 1) dp[0][i][j] = max(dp[0][i][j], dp[0][i - 1][j]);
            if (j > 1) dp[0][i][j] = max(dp[0][i][j], dp[0][i][j - 1]);
            if (i == 1 && j == 1) dp[0][i][j] = 0;
            dp[0][i][j] += t[i][j];
        }
    }

    // for (int i= 1 ;i<=n ; i++){
    //     for (int j=1 ;j<= m ; j++)
    //         cout << dp[1][i][j] << " ";
    //     cout <<endl;
    // }
    for (int i = n; i >= 1; i--){
        for (int j = m; j >= 1; j--){
            if (i < n) dp[1][i][j] = max(dp[1][i][j], dp[1][i + 1][j]);
            if (j < m) dp[1][i][j] = max(dp[1][i][j], dp[1][i][j + 1]);
            if (i == n && j == m) dp[1][i][j] = 0;
            dp[1][i][j] += t[i][j];
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; i++){
        vector<int> pref(m + 2, -INF), suff(m + 2, -INF);

        for (int j = 1; j <= m; j++){ pref[j] = dp[0][i][j] + dp[1][i + 1][j]; }
        for (int j = 1; j <= m; j++){ suff[j] = dp[0][i - 1][j] + dp[1][i][j]; }
        for (int j = 1; j <= m; j++) pref[j] = max(pref[j], pref[j - 1]);
        for (int j = m; j >= 1; j--) suff[j] = max(suff[j], suff[j + 1]);
        for (int j = 1; j <= m; j++){
            int curr = max(pref[j - 1], suff[j + 1]);
            curr = max(curr, dp[0][i][j] + dp[1][i][j] - 3 * t[i][j]);

            ans = min(ans, curr);
        }
    }
    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
