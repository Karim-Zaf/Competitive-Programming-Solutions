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
#define endl '\n'

const int N = 3005 + 30, mod = 1e9 + 7, INF = 1e9 + 10;

int vis[N][N], dist[N][N], distfin[N][N];
pair<int, int> corr[N][N];
pair<int, int> mp[30];
char t[N][N];
int n, m;

ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};

bool can_move(int i, int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

void bfs_monster() {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (t[i][j] == 'M') {
                dist[i][j] = 0;
                q.push({i, j});
            } else dist[i][j] = INF;
            for (int k= 0 ; k< 30 ; k++) mp[k].F = mp[k].S = -1 ;
        }
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        for (ll pas = 0; pas < 4; pas++) {
            int x = i + dx[pas];
            int y = j + dy[pas];
            if (can_move(x, y) && dist[x][y] == INF && t[x][y] != '#') {
                dist[x][y] = dist[i][j] + 1;
                q.push({x, y});
            }
        }
    }
}

bool bfs_answer() {
    memset(distfin, -1, sizeof(distfin));
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (t[i][j] == 'S') {
                distfin[i][j] = 0;
                q.push({i, j});
            }
            int haref = t[i][j] - '0';
            if ('0' <= t[i][j] && t[i][j] <= '9') {
                if (mp[haref].F == -1)mp[haref] = {i, j};
                else {
                    corr[mp[haref].F][mp[haref].S] = {i, j};
                    corr[i][j] = mp[haref];
                }
            }
        }
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        for (int pas = 0; pas < 4; pas++) {
            int x = i + dx[pas];
            int y = j + dy[pas];
            if (can_move(x, y) && distfin[x][y] == -1 && t[x][y] != '#'&&distfin[i][j]+1 < dist[x][y]) {
                q.push({x, y});
                distfin[x][y] = distfin[i][j] + 1;
            }
            x = corr[i][j].F, y = corr[i][j].S;
            if (can_move(x, y) && distfin[x][y] == -1 && t[x][y] != '#'&&distfin[i][j]+1 < dist[x][y]) {
                q.push({x, y});
                distfin[x][y] = distfin[i][j] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (t[i][j] == 'E') {
                return distfin[i][j] != -1 && distfin[i][j] < dist[i][j];
            }
        }
    return true;
}

void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];

    bfs_monster();
    cout << (bfs_answer() ? "YES" : "NO") << endl;
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