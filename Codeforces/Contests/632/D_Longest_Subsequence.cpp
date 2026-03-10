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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;


void Solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), ans, sv(m+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] > m) continue;
        sv[v[i]]++;
    }
    for (int i = m; i >= 1; i--)
        for (int j = i + i; j <= m; j += i)
            sv[j] += sv[i];

    int mx = 1;
    for (int i = 1; i <= m; i++) {
        if (sv[i] > sv[mx])mx = i;
    }

    for (int i = 1; i <= n; i++) {
        if (mx % v[i] == 0)ans.pb(i);
    }
    cout << mx << " " << ans.size() << endl;
    for (auto x: ans) cout << x << " ";
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