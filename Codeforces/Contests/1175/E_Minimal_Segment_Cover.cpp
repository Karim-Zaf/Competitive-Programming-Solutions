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

const int N = 5e5 + 30, LOG = 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

int dp[N][30];
vector<int> mp[N];

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp(n);
    for (auto &x: vp) {
        cin >> x.F >> x.S;
        mp[x.F].pb(x.S);
    }
    sort(all(vp));
    multiset<int> s;

    for (int i = 0; i < N; i++) {
        for (auto x: mp[i])s.insert(x);
        if (!s.empty()) dp[i][0] = *s.rbegin();
        else dp[i][0] = -1;
        s.erase(i);
    }


    for (int i = N - 1; i >= 0; i--)
        for (int j = 1; j < LOG; j++)
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];

    while (m--) {
        int x, y, ans = 0;
        cin >> x >> y;

        for (int j = LOG - 1; j >= 0; j--) {
            if (dp[x][j] < y) {
                ans += 1 << j;
                x = dp[x][j];
            }
        }
        if (dp[x][0] >= y) ans++;
        else ans = -1;
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