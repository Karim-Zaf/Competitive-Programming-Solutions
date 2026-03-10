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

const int N = 5e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int dp[N][3][3];

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) pref[i] = (pref[i - 1] + v[i]) % 3;

    for (int i = 1; i <= n; i++) {
        for (int toufa = 0; toufa < 3; toufa++) {
            for (int prd = 0; prd < 3; prd++) {
                int nv_prd = (pref[i - 1] - toufa) * v[i] + prd;
                ((nv_prd %= 3) += 3) %= 3;
                nv_prd %= 3;
                dp[i][toufa][nv_prd] += dp[i - 1][toufa][prd];
            }
        }
        if (i >= 2) dp[i][pref[i - 2]][v[i] * v[i - 1] % 3]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++) ans += dp[i][j][0];
    cout << ans + n << endl;
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