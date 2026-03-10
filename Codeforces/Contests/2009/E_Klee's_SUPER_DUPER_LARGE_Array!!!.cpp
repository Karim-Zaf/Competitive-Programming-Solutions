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
    int n, k;

    cin >> n >> k;
    int l = k, r = k + n - 1, ans = INF;

    auto cnt = [&](int i) {
        int sum = 0;
        int one = i * (i + 1) / 2 - k * (k - 1) / 2;
        int two = (k + n - 1) * (k + n) / 2 - i * (i + 1) / 2;

        return abs(one - two);
    };

    int res = (k + n - 1) * (k + n) / 2 + k * (k - 1) / 2;

    int sq = sqrt(res);
    for (int i = max(l, sq - 30); i <= min(r, min(r, sq + 30)); i++) {
        ans = min(ans, cnt(i));
    }
    cout << ans << endl;

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