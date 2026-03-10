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

const int N = 3e5 + 30, lg = 30, mod = 1e9 + 7, INF = 1e18 + 10;

int bf[2][lg], af[2][lg];

void Solve() {
    memset(bf, 0, sizeof(bf));
    memset(af, 0, sizeof(af));


    int n, ans = 0;
    cin >> n;
    vector<int> v(n + 1), pref(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = pref[i - 1] ^ v[i];
        for (int j = 0; j < lg; j++) {
            if (pref[i] >> j & 1) af[1][j]++;
            else af[0][j]++;
        }
    }

    for (int j = 0; j < lg; j++) bf[0][j]++;

    for (int i = 1; i <= n; i++) {
        
        for (int j = lg - 1; j >= 0; j--) {
            if (v[i] >> j & 1) {
                ans += af[0][j] * bf[0][j];
                ans += af[1][j] * bf[1][j];
                break;
            }
        }

        for (int j = 0; j < lg; j++) {
            if (pref[i] >> j & 1) bf[1][j]++, af[1][j]--;
            else bf[0][j]++, af[0][j]--;
        }
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