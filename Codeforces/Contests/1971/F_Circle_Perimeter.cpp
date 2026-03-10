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
    int n, ans = 0;
    cin >> n;
    for (int i = - n; i <=  n; i++) {

        int l = -n, r = n, ans1 = -INF, ans2 = -INF;

        while (l <= r) {
            int md = l + (r - l) / 2;
                kar (md) ;

            if (i * i + md * md - n * n >= 0) {
                r = md - 1;
                ans1 = md;
            } else l = md + 1;
        }

        l = -n, r = n;
        while (l <= r) {
            int md = l + (r - l) / 2;

            if (i * i + md * md - n * n < 2 * n + 1) {
                l = md + 1;
                ans2 = md;
            } else r = md - 1;
        }

        if (ans1 <= ans2 && ans1 != -INF && ans2 != -INF) ans += 2 * (ans2 - ans1);
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