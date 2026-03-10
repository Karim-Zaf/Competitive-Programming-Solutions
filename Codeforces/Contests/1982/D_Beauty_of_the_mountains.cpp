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
    int n, m, k;
    cin >> n >> m >> k;

    int t[n + 1][m + 1], pref[n + 4][m + 4];
    char v[n + 1][m + 1];

    for (int i = 0; i <= n + 2; i++)
        for (int j = 0; j <= m + 2; j++)
            pref[i][j] = 0;


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            pref[i][j] = (v[i][j] - '0') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];

    vector<int> val;

    for (int i = k; i <= n; i++)
        for (int j = k; j <= m; j++) {
            int p = pref[i][j] - pref[i][j - k] - pref[i - k][j] + pref[i - k][j - k];
            int oth = k * k - p;
            val.pb(abs(-p + oth));
        }

    int diff = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (v[i][j] == '1') diff += t[i][j];
            else diff -= t[i][j];

    diff = abs(diff);

    if (diff == 0) return void(cout << "YES\n");
    int g = 0;
    for (auto x: val)
        g = __gcd(g, x);

    cout << (g && diff % g == 0 ? "YES" : "NO") << endl;

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