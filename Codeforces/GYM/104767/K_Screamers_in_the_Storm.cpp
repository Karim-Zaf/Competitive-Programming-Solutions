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

const int N = 2600 + 30, mod = 1e9 + 7, INF = 0 + 10;


pair<int, int> dp[51][N];

int mult(int a, int b, int Mod = mod) {
    b %= Mod;
    return a % Mod *b % Mod;
}

int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) + Mod )% Mod; }


void Solve() {
    int d, r;
    cin >> d >> r;
    int ans = 0;

    dp[0][0].F = 1;
    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < N; j++) {
            for (int c = 0; c <= r; c++) {
                int curr = abs(c) * abs(c);
                if (j - curr < 0) continue;
                dp[i][j].F = add(dp[i][j].F, dp[i - 1][j - curr].F);
                dp[i][j].S = add(dp[i][j].S, dp[i - 1][j - curr].S);
                dp[i][j].S = add(dp[i][j].S, mult(abs(c), dp[i - 1][j - curr].F));
                if (c) {
                    dp[i][j].F = add(dp[i][j].F, dp[i - 1][j - curr].F);
                    dp[i][j].S = add(dp[i][j].S, dp[i - 1][j - curr].S);
                    dp[i][j].S = add(dp[i][j].S, mult(abs(c), dp[i - 1][j - curr].F));
                }
            }
        }
    }
    for (int i = 0; i <= r * r; i++) {
        ans = add(ans, dp[d][i].S);
    }

    cout << ans << endl;
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

