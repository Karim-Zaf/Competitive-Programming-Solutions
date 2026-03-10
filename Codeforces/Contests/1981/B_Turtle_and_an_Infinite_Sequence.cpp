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
    int n, m, ans = 0;
    cin >> n >> m;

    int l = n - m;
    int r = n + m;
    l = max(0ll, l);
    for (int i = 0; i <= 32; i++) {
        int nw = l;
        if ((1ll << i) & l) n |= (1ll << i);
        if ((1ll << i) & r) n |= (1ll << i);

        nw |= (1ll << i);
        int oth = nw;
        for (int j = i - 1; j >= 0; j--) {
            if (l <= nw && nw <= r) {
                n |= (1ll << i);
            }
            if ((1ll << j) & nw) nw -= (1 << j);
            if (l <= nw && nw <= r) {
                n |= (1ll << i);
            }
        }
        nw = oth;
        for (int j = 0; j <= i - 1; j++) {
            if (l <= nw && nw <= r) {
                n |= (1ll << i);
            }
            if ((1ll << j) & nw) nw -= (1 << j);
            if (l <= nw && nw <= r) {
                n |= (1ll << i);
            }
        }
        if (l <= nw && nw <= r) {
            n |= (1ll << i);
        }
    }
    cout << n << endl;

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