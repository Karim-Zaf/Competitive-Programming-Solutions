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

void Solve() {
    int n;
    cin >> n;

    vector<int> v(n), dp(n);
    for (auto& x : v) cin >> x;

    for (int i = 1; i < n; i++) {
        if (v[i] >= v[i - 1]) {
            if (v[i - 1] == 1) continue ;
            int cnt = dp[i - 1], x = v[i - 1];
            while (x * x <= v[i]) x *= x, cnt--;
            dp[i] += max(0ll, cnt);
        } else {
            if (v[i] == 1) return void(cout << "-1\n");
            int cnt = dp[i - 1], x = v[i];
            while (v[i - 1] > x) x *= x, cnt++;
            dp[i] = cnt;
        }
    }
    cout << accumulate(all(dp), 0ll) << endl;
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
