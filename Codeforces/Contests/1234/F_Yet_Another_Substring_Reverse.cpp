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

const int N = 3e5 + 30, mod = 1e9 + 7;

const int LG = 20;

void Solve() {
    string s;
    cin >> s;
    int n = s.size();


    vector<int> dp((1 << LG) + 4), vis ((1 << LG) + 4);


    for (int i = 0; i < n; i++) {
        int curr = 0;
        map<char, int> mp;
        for (int j = i; j >= max(0, j - LG); j--) {
            if (mp[s[j]]) break ;
            mp[s[j]]++;
            curr |= (1 << (s[j] - 'a'));
            dp[curr] = __builtin_popcount(curr);
            vis[curr]= 1 ;
        }
    }


    for (int j = LG - 1; j >= 0; j--) {
        for (int i = (1 << LG) - 1; i >= 0; i--) {
            if (!(i & (1 << j))) {
                dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i]);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < (1 << LG); i++) {
        if (vis[i]) ans = max(ans, __builtin_popcount(i) + dp[(1 << LG) - 1 - i]);
    }

    cout << ans << endl;


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
