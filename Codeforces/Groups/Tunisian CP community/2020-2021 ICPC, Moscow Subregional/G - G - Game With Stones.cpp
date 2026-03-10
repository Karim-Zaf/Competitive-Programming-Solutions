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

int t[1005][1005];

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;


    for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++) cin >> t[i][j];
    for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++) t[i][j] += t[i][j - 1];

    vector<int> sum(n + 1), ans(n + 1);


    for (int j = 1; j <= n; j++) {
        vector<int> curr;
        for (int i = 1; i <= k; i++) {
            curr.pb(t[i][j]);
        }
        sort(all(curr));
        int med = curr[(k - 1) / 2];
        sum[j] = med;
    }

    for (int j = n; j >= 1; j--) {
        assert(sum[j]>= sum[j-1]);
        sum[j] = sum[j] - sum[j - 1];
    }

    for (int i = 1; i <= n; i++) cout << sum[i] << " ";
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
