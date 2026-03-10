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
    int n, c, k, mask = 0, ans = INF;
    string s;
    cin >> n >> c >> k >> s;
    map<char,int> mp;
    vector<int> dp((1 << c) + 5), nw_dp((1 << c) + 5);
    s = "#" + s;

    for (int i = 1; i < k; i++) {
        if (!mp[s[i]]) mask |= (1 << (s[i] - 'A'));
        mp[s[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (i + k - 1 <= n) {
            if (!mp[s[i + k - 1]]) mask |= (1 << (s[i + k - 1] - 'A'));
            mp[s[i + k - 1]]++;
        }

        dp[mask]++;
        if (mp[s[i]] == 1) mask ^= (1 << (s[i] - 'A'));
        mp[s[i]]--;
    }


    for (int j = 0; j < c; j++) {
        for (int mask = (1 << c) - 1; mask >= 0; mask--) {
            if (((1 << j) & mask)) dp[mask ^ (1 << j)] += dp[mask];
        }
    }


    for (int mask = 0; mask < (1 << c); mask++) {
        int cnt = 0, curr = INF;
        for (int j = mask; j; j = (j - 1) & mask) {
            if (__builtin_popcount(j) % 2) cnt += dp[j];
            else cnt -= dp[j];
        }
        if (cnt == n) curr = __builtin_popcount(mask);
        ans = min(ans, curr);
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
