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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

int t[600][600];

void Solve() {
    int n, k, sum = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            cin >> t[i][j];

    for (int i = n - 1; i > 1; i--) {
        for (int j = k - 1; j > 1; j--) {
            if (!t[i][j]) t[i][j] = min(t[i][j + 1], t[i + 1][j]) - 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            if (t[i][j] <= t[i][j - 1]) { cout << -1 << endl; return ; }
        }
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 2; i <= n; i++) {
            if (t[i][j] <= t[i - 1][j]) { cout << -1 << endl; return ; }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            sum += t[i][j];
    cout << sum << endl;
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