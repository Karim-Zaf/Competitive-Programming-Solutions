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

const int N = 3e5 + 30, mod = 998244353, INF = 1e18 + 10;


int binpow(int a, int k, int res = 1, int Mod = mod) {
    while (k) {
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a, int Mod = mod) { return binpow(a, Mod - 2); }

int mult(int a, int b, int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }

int divide(int a, int b, int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}

void Solve() {
    int n, m, d, ans = 0;
    cin >> n >> m >> d;
    char t[n + 1][m + 1];
    int dp[2][n + 1][m + 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];

    memset(dp, 0, sizeof(dp));

    for (int j = 1; j <= m; j++) dp[0][0][j] = 1;

    for (int i = 1; i <= n; i++) {

        vector<int> prev(m + 3);
        for (int j = 1; j <= m; j++) prev[j] = add(prev[j - 1], add(dp[0][i - 1][j], dp[1][i - 1][j]));

        for (int j = 1; j <= m; j++) {
            if (t[i][j] != 'X') continue;
            if (i == 1) {
                dp[0][i][j] = 1;
                continue;
            }
            int lef = j - (int)sqrt(d * d - 1), righ = j + (int)sqrt(d * d - 1);

            lef = max(lef, 1ll);
            righ = min(righ, m);

            dp[0][i][j] = add(prev[righ], -prev[lef - 1]);
        }

        vector<int> pref(m + 3);
        for (int j = 1; j <= m; j++) pref[j] = add(pref[j - 1], dp[0][i][j]);


        for (int j = 1; j <= m; j++) {
            if (t[i][j] != 'X') continue;
            int lef = j - d, righ = j + d;
            lef = max(lef, 1ll);
            righ = min(righ, m);

            dp[1][i][j] = add(pref[righ], -pref[lef - 1]);
            dp[1][i][j] = add(dp[1][i][j], -dp[0][i][j]);
        }

    }


    for (int j = 1; j <= m; j++)
        for (int f = 0; f < 2; f++) {
            ans = add(ans, dp[f][n][j]);
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