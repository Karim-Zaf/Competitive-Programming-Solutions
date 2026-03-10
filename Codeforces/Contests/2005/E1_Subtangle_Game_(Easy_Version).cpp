/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

const int M = 305;

int dp[M][M][M];
int mat[M][M];
vector<int> v(M);
int n, m, l;

int work(int pos, int i,int j) {
    if (i > n || j > m || pos > l) return 0;

    int& ret = dp[pos][i][j];
    if (ret != -1) return ret;

    ret = 0;

    ret |= work(pos, i + 1, j);
    ret |= work(pos, i, j + 1);
    ret |= work(pos, i + 1, j + 1);

    if (v[pos] == mat[i][j]) ret |= (work(pos + 1, i + 1, j + 1) == 0);

    return ret;
}

void Solve() {
    cin >> l >> n >> m;

    for (int i = 0; i <= l; i++) for (int a = 0; a <= n; a++) for (int b = 0; b <= m; b++) dp[i][a][b] = -1;

    for (int i = 1; i <= l; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> mat[i][j];

    cout << (work(1, 1, 1) ? "T" : "N") << endl;
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
