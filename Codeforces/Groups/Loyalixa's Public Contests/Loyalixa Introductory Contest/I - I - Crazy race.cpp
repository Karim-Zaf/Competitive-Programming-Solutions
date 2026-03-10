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
const int N = 1005;


int vis[N][N];
char t[N][N];
int n, m;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};

bool can_move(int i, int j) {
    return i >= 0 && i <= n + 1 && j >= 0 && j <= m + 1;
}


void Solve() {
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++) {
            t[i][j] = '#';
            vis[i][j] = 0;
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> t[i][j];
    }

    int pi = -1, pj = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (t[i][j] == 'Z') {
                pi = i, pj = j;
            }
        }

    int ans = 1e9;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++) {
            if (t[i][j] == '#') {
                ans = min(ans, abs(i - pi) + abs(j - pj));
            }
        }
    assert(ans !=1e9);
    cout << ans << endl;
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
