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

struct DSU {
    vector<int> sz, parent;

    void init(int n) {
        for (int i = 0; i < n; i++) {
            parent.pb(i);
            sz.pb(1);
        }
    }

    int get(int a) { return (parent[a] == a ? a : parent[a] = get(parent[a])); }

    bool unite(int a, int b) {
        if ((a = get(a)) == (b = get(b))) return false;
        if (sz[a] > sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int a) { return sz[get(a)]; }
};

ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};


void Solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    char t[n + 10][m + 10];
    int dp[n + 10][m + 10];
    for (int i = 0; i <= n + 3; i++)
        for (int j = 0; j <= m + 3; j++) {
            t[i][j] = '.';
            dp[i][j] = 0;
        }


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];

    DSU dsu;
    dsu.init(n * m + 10);


    auto get = [&](int x, int y) {
        return m * (x - 1) + y;
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (t[i][j] == '.') continue;
            for (ll pas = 0; pas < 4; pas++) {
                int x = i + dx[pas];
                int y = j + dy[pas];
                if (t[x][y] == '#')
                    dsu.unite(get(i, j), get(x, y));
            }
        }
    }


    vector<int> v[n * m + 2][2];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int id = dsu.get(get(i, j));
            ans = max(ans, dsu.size(id));
            v[id][0].pb(i);
            v[id][1].pb(j);
        }

    for (int i = 1; i <= n * m; i++) {
        sort(all(v[i][0]));
        sort(all(v[i][1]));
    }


    // fixing column
    for (int j = 1; j <= m; j++) {
        set<int> s;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (t[i][j] == '#')s.insert(dsu.get(get(i, j)));
            else sum++;
            if (t[i][j - 1] == '#')s.insert(dsu.get(get(i, j - 1)));
            if (t[i][j + 1] == '#')s.insert(dsu.get(get(i, j + 1)));
        }
        for (auto x: s) {
            sum += dsu.size(x);
        }

        dp[0][j] += sum;
        for (auto x: s) {
            int lef = v[x][0][0];
            int righ = v[x][0].back();
            dp[lef - 1][j] -= dsu.size(x);
            dp[righ + 2][j] += dsu.size(x);
        }


        for (int i = 1; i <= n + 1; i++)
            dp[i][j] += dp[i - 1][j] ;
        for (int i = 1; i <= n + 1; i++)
            dp[i][j] -= (t[i][j]=='.') ;
    }
//    // fixing column
    for (int i = 1; i <= n; i++) {
        set<int> s;
        for (int j = 1; j <= m; j++) {
            s.insert(dsu.get(get(i, j)));
            if (t[i + 1][j] == '#')s.insert(dsu.get(get(i + 1, j)));
            if (t[i - 1][j] == '#')s.insert(dsu.get(get(i - 1, j)));
        }
        int sum = 0;
        for (auto x: s)sum += dsu.size(x);

        for (int j = 1; j <= m; j++) {
            ans = max(ans, sum + dp[i][j]);
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