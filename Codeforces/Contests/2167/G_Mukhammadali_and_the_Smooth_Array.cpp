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

const int M = 8005;
int dp[2][M];
int pref[2][M];

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> c[i];

    vector<int> nw = a;
    sort(all(nw));

    for (auto& x : a) x = lower_bound(all(nw), x) - nw.begin();

    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= n + 2; j++)
            dp[i][j] = pref[i][j] = INF;

    for (int i = 0; i <= n + 2; i++) pref[0][i] = dp[0][i] = 0;
    for (int i = 1; i <= n; i++){
        for (int x = 0; x <= n + 1; x++){
            if (x == a[i]) dp[1][x] = pref[0][x];
            else dp[1][x] = pref[0][x] + c[i];
        }

        pref[1][0] = dp[1][0];
        for (int x = 1; x <= n + 1; x++)
            pref[1][x] = min(dp[1][x], pref[1][x - 1]);
        swap(dp[0], dp[1]);
        swap(pref[0], pref[1]);
    }
    int ans = INF;
    for (int i = 0; i <= n + 1; i++) ans = min(ans, dp[0][i]);
    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
