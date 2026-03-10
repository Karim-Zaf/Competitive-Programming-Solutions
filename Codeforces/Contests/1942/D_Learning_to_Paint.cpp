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

const int N = 1e3 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int a[N][N];
vector<int> dp[N];

void Solve() {
    int n, k;
    cin >> n >> k;


    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++)
            cin >> a[i][j];
    }

    dp[0].pb(0);
    for (int r = 1; r <= n; r++) {
        vector<int> pointeur(n); // position of pointer in each dp

        // taking biggest dp from each previous interval
        priority_queue<array<int, 2>> pq;
        for (int l = 2; l <= r; l++)
            pq.push({dp[l - 2][0] + a[l][r], l});

        pq.push({a[1][r], 0});


        while (!pq.empty() && dp[r].size() < k) {
            auto [sum, pos] = pq.top();

            pq.pop();

            dp[r].pb(sum);

            if (pos == 0 || ++pointeur[pos - 2] >= dp[pos - 2].size())continue;

            // advancing the pointer and inserting new potential value
            pq.push({dp[pos - 2][pointeur[pos - 2]] + a[pos][r], pos});
        }

        //merging my dp and the previous one

        for (auto x: dp[r - 1]) dp[r].pb(x);
        sort(rall(dp[r]));

        while (dp[r].size() > k)dp[r].pop_back();
    }

    for (int i = 0; i < k; i++) cout << dp[n][i] << " "; cout << endl;

    for (int i = 0; i <= n; i++)dp[i].clear();
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}