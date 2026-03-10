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


int dp[55][105];
int lst[55][105];

void Solve() {
    memset(lst, -1, sizeof(lst));
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> v(n + 1), pref(n + 5);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) pref[i] = (pref[i - 1] + v[i]) % p;

    lst[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        memset(dp, -1, sizeof(dp));

        for (int block = 1; block <= k; block++) {
            for (int modulo = 0; modulo < p; modulo++) {
                int complement = (pref[i] - modulo + p) % p;
                if (lst[block - 1][complement] == -1)continue;
                dp[block][pref[i]] = max(dp[block][pref[i]], lst[block - 1][complement] + modulo);
            }
        }

        for (int block = 1; block <= k; block++) {
            for (int modulo = 0; modulo < p; modulo++) {
                if (dp[block][modulo] == -1)continue;
                lst[block][modulo] = max(lst[block][modulo], dp[block][modulo]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < p; i++) ans = max(ans, dp[k][i]);

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