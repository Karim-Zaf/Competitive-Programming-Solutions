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

vector<int> v, dp(20);
int vis[20];
vector<pair<int, int>> dp_vec[20], dp_opp[20];

vector<pair<int, int>> go(int righ) {
    if (righ < 1) return {};

    vector<pair<int, int>> &ret = dp_opp[righ], oth;

    if (vis[righ])return ret;
    vis[righ] = 1;

    oth = go(righ - 1);
    for (auto x: oth) ret.pb(x);

    ret.pb({1, righ});

    for (auto x: oth) ret.pb(x);
    return ret;
}


void Solve() {
    int n, sum = 0;
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) {
        int sum_suff = 0;
        sum += v[i];
        dp[i] = 0;
        for (int j = i; j >= 0; j--) {
            if ((i - j) * (i - j) > sum_suff) {
                if ((i - j) * (i - j) + dp[j] > dp[i]) {
                    dp[i] = dp[j] + (i - j) * (i - j);
                    dp_vec[i] = dp_vec[j];

                    for (int k = j + 1; k <= i; k++) {
                        if (v[k]) dp_vec[i].pb({k, k});
                    } // making it 0 0 0 0 0 0

                    dp_vec[i].pb({j + 1, j + 1});// making it 1 0 0 0 0 0
                    for (auto x: go(i - j)) dp_vec[i].pb({j + 1, x.S + j});

                    // making it 0 1 2 3 4 5

                    dp_vec[i].pb({j + 1, i}); // making it 6 6 6 6 6 6
                }
            } else {
                if (sum_suff + dp[j] > dp[i]) {// tekhou suffix lkol
                    dp[i] = dp[j] + sum_suff;
                    dp_vec[i] = dp_vec[j];
                }
            }
            sum_suff += v[j];
        }
    }

    cout << dp[n] << " " << dp_vec[n].size() << endl;
    for (auto x: dp_vec[n]) cout << x.F << " " << x.S << endl;
    // nice problem ;)
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