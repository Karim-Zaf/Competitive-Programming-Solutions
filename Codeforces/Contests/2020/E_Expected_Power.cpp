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

int binpow(int a, int k, int res = 1,int Mod = mod) {
    while (k) {
        if (k % 2) res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a,int Mod = mod) { return binpow(a, Mod - 2); }
int mult(int a, int b,int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b,int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }
int divide(int a, int b,int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}

const int MX = 1024;
int dp[2][MX + 3];

void Solve() {
    int n;
    cin >> n;

    vector<int> v(n + 2), p(n + 2);

    memset(dp, 0, sizeof (dp));

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> p[i];


    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {

        int prob = divide(p[i], 1e4);
        int p_bar = divide(1e4 - p[i], 1e4);

        for (int j = 0; j < MX; j++) dp[1][j] = 0;
        for (int j = 0; j < MX; j++) {
            // don't take it
            dp[1][j] = mult(dp[0][j], p_bar);

        }

        for (int j = 0; j < MX; j++) {
            // take it
            dp[1][j ^ v[i]] = add(dp[1][j ^ v[i]], mult(dp[0][j], prob));
        }

        swap(dp[0], dp[1]);
    }


    int ans = 0;

    for (int i = 0; i < MX; i++) ans = add(ans, mult(i * i, dp[0][i]));

    cout << ans << endl;

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
