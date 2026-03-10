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

const int N = 5e3 + 30, mod = 1e9 + 7, INF = 1e18 + 10;


int dp[N][N][2];
vector<int> v(N);
int n;

int work(int l, int r, int index = 0) {
    if (l >= r) return 0;

    int &ret = dp[l][r][index];
    if (ret != -1) return ret;


    if (index == 1) {
        ret = work(l + 1, r, 0) + (v[l] != v[r]);
        ret = min(ret, work(l + 1, r, 1) + (v[l] != v[l + 1]));
    } else {
        ret = work(l, r - 1, 0) + (v[r] != v[r - 1]);
        ret = min(ret, work(l, r - 1, 1) + (v[r] != v[l]));
    }
    return ret;
}

void Solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> v[i];
    memset(dp, -1, sizeof(dp));


    cout << min(work(1, n, 1), work(1, n, 0)) << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--)
        Solve();
}