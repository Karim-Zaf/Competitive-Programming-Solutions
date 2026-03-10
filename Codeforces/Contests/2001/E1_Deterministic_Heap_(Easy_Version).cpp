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

int mod;

int mult(ll a, ll b, int Mod = mod) { return a * b % Mod; }

int add(ll a, ll b, int Mod = mod) { return (a + b) % Mod; }

int n, k;
int dp[2][505][505];

int work(int depth, int rem, int flag = true) {
    if (rem < 0) return 0;
    if (depth == n) return 1;

    int& ret = dp[flag][depth][rem];
    if (ret != -1) return ret;

    ret = work(depth, rem - 1, flag);
    if (flag) {
        for (int i = (rem + 2) / 2; i <= rem; i++) {
            int curr = mult(work(depth + 1, i, true), work(depth + 1, rem - i, false));
            ret = add(ret, mult(curr, 2));
        }
    } else {
        for (int i = 0; i <= rem; i++) {
            int curr = mult(work(depth + 1, i, false), work(depth + 1, rem - i, false));
            ret = add(ret, curr);
        }
    }

    return ret;

}

void Solve() {
    cin >> n >> k >> mod;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) dp[0][i][j] = dp[1][i][j] = -1;
    cout << work(1, k, true) << endl;
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
