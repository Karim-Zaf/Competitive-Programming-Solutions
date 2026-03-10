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
    vector<int> v(n), lg(n);
    for (auto& x : v) cin >> x;

    sort(rall(v));

    int l = 1, r = n, ans = -1;

    while (l <= r) {
        int md = l + (r - l) / 2, cnt = 0;

        vector<int> vv = v;

        for (auto& x : vv) {
            while (x % 2 == 0) {
                x /= 2;
                cnt++;
            }
        }
        sort(rall(vv));
        for (int i = 0; i < md; i++) {
            while (vv[i] < md) {
                cnt--;
                vv[i] *= 2;
            }
        }

        if (cnt >= 0) {
            l = md + 1;
            ans = md;
        } else r = md - 1;
    }

    assert(ans !=-1);
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
