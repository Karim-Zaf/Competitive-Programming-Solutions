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

const int N = 1e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> divi[N];

map<int, int> dp[N];

void sieve() {
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divi[j].pb(i);
}

void Solve() {
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) dp[i].clear();


    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        int g = __gcd(v[i], i);
        int x = v[i] / g, j = i / g;

        for (auto d: divi[x])
            ans += dp[d][j];

        for (auto d: divi[x])
            dp[j][d]++;
    }

    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    sieve();
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}