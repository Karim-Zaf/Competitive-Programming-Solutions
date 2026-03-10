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

const int N = 2e6 + 30;
const int M = 5000 + 10;

int dp[M][M];
int mp[2][N];

void Solve() {
    int n, m, cnt = 0, ans = 0;
    cin >> n >> m;


    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] > 0) mp[0][v[i]]++;
        else if (v[i] < 0) mp[1][-v[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] > 0) mp[0][v[i]]--;
        else if (v[i] < 0) mp[1][-v[i]]--;

        if (v[i]) continue;


        for (int j = 0; j <= cnt; j++) {

            dp[j + 1][cnt - j] = max(dp[j + 1][cnt - j], dp[j][cnt - j] + mp[0][j + 1]);
            dp[j][cnt - j + 1] = max(dp[j][cnt - j + 1], dp[j][cnt - j] + mp[1][cnt - j + 1]);

        }
        cnt++;
    }


    for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) ans = max(ans, dp[i][j]);
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
