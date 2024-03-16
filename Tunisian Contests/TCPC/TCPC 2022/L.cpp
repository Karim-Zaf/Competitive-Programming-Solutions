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

int value[N], pref[N], n, q, ans[N], x;
vector<int> graph[N];
map<int, int> mp[N];

void merge(map<int, int> &a, map<int, int> &b) {
    if (a.size() < b.size())a.swap(b);
    for (auto [val, occ]: b)a[val] += occ;
}

void dfs(int curr = 1, int parent = 0) {
    pref[curr] = pref[parent] + value[curr];
    for (auto child: graph[curr]) {
        if (child == parent)continue;
        dfs(child, curr);
        merge(mp[curr], mp[child]);
    }
    ans[curr] += mp[curr][pref[parent]];
    mp[curr][pref[curr]]++;
}

void Solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
        if (!value[i])value[i] = -1;
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs();
    while (q--) {
        cin >> x;
        cout << ans[x] << endl;
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
