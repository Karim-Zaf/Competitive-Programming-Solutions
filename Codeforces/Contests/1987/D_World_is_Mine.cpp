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

const int N = 5e3 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int dp[N][N];
vector<int> v;
map<int, int> mp;

int work(int pos, int turns) {
    if (turns < 0) return -1;
    if (pos >= v.size()) return 0;
    int &ret = dp[pos][turns];
    if (ret != -1)return ret;
    ret = 1 + work(pos + 1, -mp[v[pos]] + turns);
    ret = max(ret, work(pos + 1, turns + 1));
    return ret;
}


void Solve() {
    int n;
    cin >> n;
    mp.clear();
    v.resize(n);

    for (auto &x: v) cin >> x;
    for (auto &x: v) mp[x]++;

    set<int> s(all(v));
    v = vector<int>(all(s));

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            dp[i][j] = -1;
    int ans = s.size();

    ans -= work(0, 0);

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