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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

vector<int> graph[N], ans(N);
vector<pair<int, int>> quer[N];
int n, m, id = 0, depth[N];
map<int, int> mp[N];
int up[N][30];

void dfs1(int parent) {
    for (int i = 1; i < 28; i++)
        up[parent][i] = up[up[parent][i - 1]][i - 1];

    for (auto child: graph[parent]) {
        if (up[parent][0] == child)continue;
        depth[child] = depth[parent] + 1;
        up[child][0] = parent;
        dfs1(child);
    }
}

int Binary_Lifting(int a, int k) {
    for (int i = 28; i >= 0; i--)
        if (k & (1 << i))
            a = up[a][i];
    return a;
}

void merge(map<int, int> &a, map<int, int> &b) {
    if (a.size() < b.size())a.swap(b);
    for (auto [key, val]: b)a[key] += val;
}

void dfs2(int curr, int parent = 0) {

    for (auto child: graph[curr]) {
        if (child == parent)continue;
        dfs2(child, curr);
        merge(mp[curr], mp[child]);
    }


    for (auto [p, id_q]: quer[curr])
        ans[id_q] = mp[curr][depth[curr] + p] - 1;

    mp[curr][depth[curr]]++;
}

void Solve() {
    cin >> n;
    vector<int> roots;
    for (int i = 1, u; i <= n; i++) {
        cin >> u;
        if (!u)roots.pb(i);
        graph[u].pb(i);
        graph[i].pb(u);
    }
    for (auto x: roots) dfs1(x);

    cin >> m;

    for (int i = 1, u, p; i <= m; i++) {
        cin >> u >> p;
        quer[Binary_Lifting(u, p)].pb({p, i});
    }

    for (auto x: roots) dfs2(x);

    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    cout << endl;
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