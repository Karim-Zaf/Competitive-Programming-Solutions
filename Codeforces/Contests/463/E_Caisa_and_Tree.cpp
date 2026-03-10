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

const int N = 2e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10, NN = 1e5 + 10;

vector<int> fact[N], a(NN);
vector<pair<int, int>> mp[N], ans(NN, {-1, -1});
vector<int> graph[NN];

void dfs(int curr = 1, int parent = -1, int depth = 0) {


    for (auto x: fact[a[curr]]) {
        if (mp[x].empty())continue;
        if (ans[curr].F == -1) {
            ans[curr] = mp[x].back();
            continue;
        }
        if (mp[x].back().S > ans[curr].S) ans[curr] = mp[x].back();
    }
    for (auto x: fact[a[curr]])mp[x].push_back({curr, depth});

    for (auto child: graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr, depth + 1);
    }

    for (auto x: fact[a[curr]])mp[x].pop_back();

}

void Solve() {
    for (int j = 2; j < N; j++) {
        if (!fact[j].empty())continue;
        for (int i = j; i < N; i += j)
            fact[i].pb(j);
    }

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }


    dfs();

    while (q--) {
        int x, u, aa;
        cin >> x >> u;
        if (x == 1) cout << ans[u].F << endl;
        else {
            cin >> aa;
            a[u] = aa;
            for (int i = 0; i <= n + 3; i++) ans[i] = {-1, -1};
            dfs();
        }
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