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


vector<int> divi[N], indx[N], dp(N);

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x: v)cin >> x;

    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divi[j].pb(i);

    sort(all(v));


    for (int i = 0; i < n; i++)
        for (auto d: divi[v[i]])
            indx[d].pb(i);

    for (int i = N - 1; i >= 1; i--) {
        int sum = accumulate(all(indx[i]), 0ll);

        for (int j = i + i; j < N; j += i) {
            dp[i] -= dp[j];
        }

        int nb = indx[i].size();
        for (auto x: indx[i]) {
            sum -= x;
            nb--;
            dp[i] += sum - nb * (x + 1);
        }

    }
    kar(dp);
    cout << dp[1];
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