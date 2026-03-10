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
#define endl '\n'

const int N = 2e7 + 30, mod = 1e9 + 7;

vector<int> vis(N), sv(1e6+2), preprocess(25);

void Solve() {
    int n, m;
    ll ans = 0;
    cin >> n >> m;

    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= m; j++) {
            preprocess[i] += (vis[j * i] == 0);
            vis[j * i] = 1;
        }
        preprocess[i] += preprocess[i - 1];
    }

    for (int i = 2; i <= n; i++) {
        if (sv[i])continue;
        int cnt = 0;
        for (ll j = i; j <= n && j >= i; j *= i, cnt++) sv[j] = 1;
        ans += preprocess[cnt];
    }

    cout << ++ans << endl; // ++ for the one
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