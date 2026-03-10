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
string s;
vector<int> graph[N];
map<char,int> mp;

void dfs(int curr, int parent = -1) {
    int cnt = 0;
    for (auto child : graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
        cnt++;
    }
    if (!cnt) mp[s[curr]]++;
}

void Solve() {
    mp.clear();
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) graph[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    cin >> s;
    s = "#" + s;
    dfs(1);
    int ans = 0;
    if (s[1] == '?') {
        ans = max(mp['1'], mp['0']);
        if (mp['1'] == mp['0'] && (count(all(s), '?') - mp['?'] + 1) % 2) ans += (mp['?'] + 1) / 2;
        else ans += (mp['?']) / 2;
    } else {
        ans = mp[s[1] == '1' ? '0' : '1'];
        ans += (mp['?'] + 1) / 2;
    }
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
