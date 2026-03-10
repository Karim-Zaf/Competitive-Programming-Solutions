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

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void ans(int x) {
    cout << "! " << x << endl;
    cout.flush();
}

int n;

pair<int, int> get(int lef, int righ, int sz) {
    lef -= sz;
    if (lef < 1) {
        int beki = 1 - lef;
        lef = 1;
        righ += beki;
    }
    return make_pair(lef, righ);
}

int bs_akber(int lef_int, int righ_int) {
    int sz = righ_int - lef_int + 1;
    int l = sz, r = n, ans = sz;

    while (l <= r) {
        int md = l + (r - l) / 2;
        auto [lef , righ] = get(lef_int, righ_int, md - sz);
        if (ask(lef, righ) == 0) {
            r = md - 1;
            ans = md;
        } else l = md + 1;
    }
    return ans;
}

int bs_asgher(int lef_int, int righ_int) {
    int sz = righ_int - lef_int + 1;
    int l = lef_int, r = righ_int, ans = sz;

    while (l <= r) {
        int md = l + (r - l) / 2;
        if (ask(lef_int, md) == 1) {
            r = md - 1;
            ans = md - lef_int + 1;
        } else l = md + 1;
    }
    return ans;
}

void Solve() {
    cin >> n;


    kar(n);
    int sz = n / 3;
    array<int, 3> a;
    a[0] = ask(1, sz);
    a[1] = ask(sz + 1, 2 * sz);
    a[2] = ask(2 * sz + 1, 3 * sz);


    if (a == array<int, 3>{1, 1, 1} || a == array<int, 3>{0, 0, 0}) {
        ans(bs_akber(3 * sz + 1, n));
    } else if (a[0] != a[1] && a[0] != a[2]) {
        if (a[0] == 1) ans(bs_akber(1, sz));
        else ans(bs_asgher(sz + 1, 2 * sz));
    } else if (a[1] != a[0] && a[1] != a[2]) {
        if (a[1] == 1) ans(bs_akber(sz + 1, 2 * sz));
        else ans(bs_asgher(1, sz));
    } else {
        if (a[2] == 1) ans(bs_akber(2 * sz + 1, 3 * sz));
        else ans(bs_asgher(1, sz));
    }
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
