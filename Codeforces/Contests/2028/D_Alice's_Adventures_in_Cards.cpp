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
    set<pair<int,int>> s[3];

    int t[3][n + 4];
    for (int i = 0; i < 3; i++) for (int j = 1; j <= n; j++) cin >> t[i][j];

    for (int i = 0; i < 3; i++) for (int j = 1; j <= n; j++) s[i].insert({t[i][j], j});

    vector<pair<int,int>> dp(n + 5, {-1, -1});

    dp[1].F = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i].F == -1) continue ;
        for (int j = 0; j < 3; j++) {
            auto it = s[j].upper_bound({t[j][i], INF});
            set<pair<int,int>> er;
            while (it != s[j].begin()) {
                it = prev(it);
                er.insert(*it);
                if (it->S != i) dp[it->S] = {j, i};
            }
            for (auto x : er) s[j].erase(x);
        }
    }

    if (dp[n].F == -1) return void(cout << "NO\n");

    array<char, 3> v{'q', 'k', 'j'};
    int curr = n;

    cout << "YES\n";
    vector<pair<char, int>> ans;
    while (curr != 1) {
        ans.pb({v[dp[curr].F], curr});
        curr = dp[curr].S;
    }
    cout << ans.size() << "\n";
    reverse(all(ans));
    for (auto x : ans) cout << x.F << ' ' << x.S << '\n';
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
