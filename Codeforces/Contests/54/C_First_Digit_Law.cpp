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
#define ld long double
#define endl '\n'

const int N = 1e3 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

ld proba[N];
ld dp[N][N];

ld p(int i) { return proba[i]; }

ld pbar(int i) { return (ld) (1) - proba[i]; }

ld calc(int x) {
    string xx = to_string(x);

    int ret = 0, sz = xx.size();
    if (xx[0] == '1') {
        ret += x % (int) (pow(10, sz - 1)) + 1;
        x = pow(10, sz - 1) - 1;
    }

    int curr = 1;

    while (2 * curr <= x) {
        ret += curr;
        curr *= 10;
    }
    return ret;
}

void Solve() {
    int n, k;
    cin >> n;
    vector<pair<int, int>> inter(n + 1);
    for (int i = 1; i <= n; i++) cin >> inter[i].F >> inter[i].S;
    cin >> k;

    ld ratio = k, ans = 0;

    for (int i = 1; i <= n; i++) proba[i] = calc(inter[i].S) - calc(inter[i].F - 1);

    for (int i = 1; i <= n; i++)
        proba[i] /= (ld) (inter[i].S - inter[i].F + 1);

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)dp[0][i] = dp[0][i - 1] * pbar(i);
    if (k <= 0) ans = dp[0][n];

    for (int sz = 1; sz <= n; sz++) {
        for (int i = 1; i <= n; i++) {
            dp[sz][i] += dp[sz - 1][i - 1] * p(i);
            dp[sz][i] += dp[sz][i - 1] * pbar(i);
        }
        if (sz * 100 >= k * n)  ans += dp[sz][n];
    }

    cout << fixed << setprecision(9) << ans << endl;

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