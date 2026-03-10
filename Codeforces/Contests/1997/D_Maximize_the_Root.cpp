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

vector<int> graph[N], value(N);


int dfs(int curr, int parent = -1) {

    int val = value[curr];
    int mn = INF;

    for (auto child : graph[curr]) {
        if (child == parent) continue;
        mn = min(mn, dfs(child, curr));
    }

    if (curr == 1) return value[1] + mn;
    int addi = (mn - val) / 2;
    
    if (mn <= val || mn == INF) return min(mn, val);

    return min(value[curr] + addi, mn - addi);
}


void Solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
    }

    for (int i = 1; i <= n; i++) cin >> value[i];
    for (int i = 2, u; i <= n; i++) {
        cin >> u;
        graph[i].pb(u);
        graph[u].pb(i);
    }


    dfs(1);
    cout << dfs(1) << endl;
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
