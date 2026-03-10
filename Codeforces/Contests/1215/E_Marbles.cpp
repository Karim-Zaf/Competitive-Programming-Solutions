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

const ll N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

// we want to calculate the numbers of moves to make x after the elements of the mask

/*
 * for the preprocess
 * we need to substract for every i the number of x's that is before them in every mask containing i
 *
 * dp[x][mask] -= nb of x's that are after i  ( mask containing i )
 */

const int LG = 20;
ll one[LG][LG];
vector<ll> dp(1 << LG, -1);

ll work(int mask) {
    if (mask == (1 << 20) - 1) return 0;
    ll& ret = dp[mask];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i < 20; i++) {
        if (mask & (1 << i)) continue;
        ll cnt = 0;
        for (int j = 0; j < 20; j++) cnt += ((mask & (1 << j)) != 0) * one[i][j];
        ret = min(ret, work(mask | (1 << i)) + cnt);
    }
    return ret;
}

void Solve() {
    int n;
    cin >> n;
    vector<ll> v(n + 3), sum(LG), freq(LG);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) v[i]--;

    for (int i = n; i >= 1; i--) {
        freq[v[i]]++;
        for (int x = 0; x < 20; x++) {
            one[x][v[i]] += freq[x];
        }
    }


    cout << work(0) << endl;;
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
