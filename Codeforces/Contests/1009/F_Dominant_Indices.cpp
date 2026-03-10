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

const int N = 1e6 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

vector<int> graph[N], depth(N), ans(N);
map<int, int> mp[N];

void merge(map<int, int> &a, map<int, int> &b, int curr, int child) {
    if (a.size() < b.size()) a.swap(b);

    for (auto [key, val]: b) {
        a[key] += val;
        if (a[key] == mp[curr][ans[curr]])
            ans[curr] = min(key, ans[curr]);
        if (a[key] > mp[curr][ans[curr]])
            ans[curr] = key;
    }
    if (a[ans[child]] == mp[curr][ans[curr]])
        ans[curr] = min(ans[child], ans[curr]);
    if (a[ans[child]] > mp[curr][ans[curr]])
        ans[curr] = ans[child];
}

void dfs(int curr, int parent = 0) {
    ans[curr] = depth[curr] = depth[parent] + 1;
    mp[curr][depth[curr]] = 1;
    for (auto child: graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
        merge(mp[curr], mp[child], curr, child);
    }
}

void Solve() {
    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) cout << ans[i] - depth[i] << endl;
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