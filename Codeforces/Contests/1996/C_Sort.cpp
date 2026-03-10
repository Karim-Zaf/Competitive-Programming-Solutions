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
    int n, q;
    string a, b;
    cin >> n >> q >> a >> b;

    a = "#" + a;
    b = "#" + b;
    vector<int> pref[2][26];

    for (int j = 0; j < 26; j++) {
        pref[0][j].resize(n + 4);
        for (int i = 1; i <= n; i++) {
            pref[0][j][i] = pref[0][j][i - 1] + (a[i] == ('a' + j));
        }
    }

    for (int j = 0; j < 26; j++) {
        pref[1][j].resize(n + 4);
        for (int i = 1; i <= n; i++) {
            pref[1][j][i] = pref[1][j][i - 1] + (b[i] == ('a' + j));
        }
    }

    while (q--) {
        int ans = 0, l, r;
        cin >> l >> r;
        for (int j = 0; j < 26; j++) {
            ans += max(0ll, ((pref[1][j][r] - pref[1][j][l - 1])) - (pref[0][j][r] - pref[0][j][l - 1]));
        }
        cout << ans << endl;
    }

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
