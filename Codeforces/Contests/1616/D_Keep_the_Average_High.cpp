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

template <class T> struct Seg { /*CHANGE THE ID YA KARIM !!*/
    const T ID = -INF;
    int n;
    vector<T> seg;
    T merge(T a, T b) { return max(a, b); }
    Seg(int _n) { n = _n, seg.assign(2 * n, ID); }
    void pull(int p) { seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }
    void print(int i = -1) { while (++i < n) cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " "); }

    void upd(int p, T val) {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = merge(ra, seg[l++]);
            if (r & 1) rb = merge(seg[--r], rb);
        }
        return merge(ra, rb);
    }
};

void Solve() {
    int n, x;
    cin >> n;
    vector<int> v(n + 1), lef(n + 1), pref(n + 1), dp(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i];
    cin >> x;

    Seg<int> bs(n + 2), mx(n + 3);

    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];
    for (int l = 1; l <= n; l++) bs.upd(l, pref[l - 1] - x * l + x);

    for (int i = 1; i <= n; i++) {

        int l = 1, r = i - 1, ans = i;

        while (l <= r) {
            int md = l + (r - l) / 2;
            if (pref[i] - x * i >= bs.query(md, i - 1)) {
                ans = md;
                r = md - 1;
            } else l = md + 1;
        }

        lef[i] = max(lef[i - 1], ans);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = mx.query(lef[i], i) + i;
        dp[i] = max({dp[i], dp[i - 1], (i - 2 >= 0 ? dp[i - 2] : 0) + 1});
        mx.upd(i, (i - 2 >= 0 ? dp[i - 2] : 0) - i + 1);
    }
    cout << *max_element(all(dp)) << endl;
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
