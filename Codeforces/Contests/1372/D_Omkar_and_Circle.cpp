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
    int n, ans = 0;
    cin >> n;

    vector<int> suff[2], pref[2], v(n + 2);

    for (int i = 0; i < 2; i++) pref[i].resize(n + 4), suff[i].resize(n + 4);


    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i % 2][i] += v[i];
        suff[i % 2][i] += v[i];
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) pref[i][j] += pref[i][j - 1];
        for (int j = n; j >= 1; j--) suff[i][j] += suff[i][j + 1];
    }

    for (int i = 1; i <= n; i++) {
        int parity = i % 2;
        ans = max(ans, pref[parity ^ 1][i - 1] + suff[parity][i]);
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