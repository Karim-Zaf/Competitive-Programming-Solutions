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

vector<int> graph[N], a(N), sz(N, 1), pref(N), bchild(N);

set<int> s[N];
int ans = 0;

void dfs_init(int curr, int parent = 0) {
    pref[curr] = pref[parent] ^ a[curr];
    for (auto child: graph[curr]) {
        if (child == parent) continue;
        dfs_init(child, curr);
        sz[curr] += sz[child];
        if (sz[child] >= sz[bchild[curr]])bchild[curr] = child;
    }
}

void dfs(int curr, int parent = -1) {
    for (auto child: graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
    }

    int big = bchild[curr];
    if (big) swap(s[curr], s[big]);

    bool ok = true;

    for (auto child: graph[curr]) {
        if (child == parent || big == child) continue;

        for (auto &val: s[child]) {
            if (s[curr].find(val ^ a[curr]) != s[curr].end()) ok = false;
        }
        for (auto val: s[child]) {
            s[curr].insert(val);
        }
        s[child].clear();
    }

    if (s[curr].find(pref[curr] ^ a[curr]) != s[curr].end()) ok = false;
    s[curr].insert(pref[curr]);
    if (!ok) {
        ans++;
        s[curr].clear();
    }
}

void Solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs_init(1);
    dfs(1);
    cout << ans << endl;
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