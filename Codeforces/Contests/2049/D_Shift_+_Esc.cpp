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

const int N = 200 + 5, mod = 1e9 + 7, INF = 1e18 + 10;


int dp[N][N][N][2];
int t[N][N];
int n, m, k;
int work(int i, int step, int nxt, int flag) {
    if (i == n && step >= m + 1 && flag == 1) return 0;
    if (i > n) return INF;
    if (step > m) return INF;
    if (flag == 0 && nxt > m) return INF;

    int& ret = dp[i][step][nxt][flag];
    if (ret != -1) return ret;
    ret = INF;

    if (flag == 1) {
        ret = min(ret, t[i][nxt] + work(i + 1, step, 1, 0)); // skip
        ret = min(ret, t[i][nxt] + work(i, step + 1, nxt % m + 1, 1)); // make the move ;
    } else {

        ret = min(ret, work(i, step, nxt + 1, 0)); // do nothing


        int cost = 0;
        if (nxt >= step) cost = nxt - step;
        else cost = nxt + (m - step);

        ret = min(ret, t[i][nxt] + k * cost + work(i, step + 1, nxt % m + 1, 1)); // nxt blasa
        ret = min(ret, t[i][nxt] + k * cost + work(i + 1, step, 1, 0)); // skip

    }

    return ret;
}

void Solve() {
    cin >> n >> m >> k;

    for (int i = 0; i <= n + 4; i++) {
        for (int j = 0; j <= m + 4; j++) {
            for (int k = 0; k <= m + 4; k++) for (int f = 0; f < 2; f++) dp[i][j][k][f] = -1;
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> t[i][j];

    cout << work(1, 1, 1, 0) << endl;
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
