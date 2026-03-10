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

const int N = 5e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> vis(N), graph[N];

void dfs(int curr, int parent = -1) {
    if (vis[curr])return;
    vis[curr] = 1;
    for (auto child: graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
    }
}

void Solve() {
    int n, cnt = 0;

    cin >> n;
    vector<array<int, 3>> vp(n);

    vector<array<int, 3>> l(2 * n + 5, {-1, -1, -1}), r(2 * n + 5, {-1, -1, -1});

    for (int i = 0; i < n; i++) {
        vp[i][2] = i;
        cin >> vp[i][0] >> vp[i][1];
        l[vp[i][0]] = vp[i];
        r[vp[i][1]] = vp[i];
    }

    if (n == 1) return void(cout << "YES\n");

    sort(all(vp), [](array<int, 3> a, array<int, 3> b) {
        if (a[1] < b[1]) return true;
        return false;
    });

    set<array<int, 3>> s;

    for (int i = 1; i <= 2 * n; i++) {
        if (l[i][0] != -1) {
            auto it = s.lower_bound({l[i][1], INF, INF});
            auto p = s.begin();
            while (p != it) {
                int u = (*p)[2];
                int v = l[i][2];
                graph[u].pb(v);
                graph[v].pb(u);
                cnt++;
                if (cnt >= n) return void(cout << "NO\n");
                p++;
            }
        }
        if (l[i][0] != -1)s.insert({l[i][1], l[i][0], l[i][2]});
        if (r[i][0] != -1)s.erase({r[i][1], r[i][0], r[i][2]});
    }
    dfs(0);
    int sum = accumulate(all(vis), 0ll);
    cout << (sum == n && cnt == n - 1 ? "YES\n" : "NO\n");
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