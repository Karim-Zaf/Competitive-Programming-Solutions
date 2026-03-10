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

void Solve() {
    int n, q;
    cin >> n >> q;
    vector<int> pref[31];

    for (auto &j: pref) j.resize(n + 5);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        for (int j = 0; j < 31; j++) {
            if ((1 << j) & x) pref[j][i] = 1;
            pref[j][i] += pref[j][i - 1];
        }
    }
    while (q--) {
        int l, r, ans = 0;
        cin >> l >> r;

        for (int j = 0; j < 31; j++) {
            int ones = pref[j][r] - pref[j][l - 1];
            int zeros = (r - l + 1) - ones;
            ans += (1 << j) % mod * ones % mod * zeros % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
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