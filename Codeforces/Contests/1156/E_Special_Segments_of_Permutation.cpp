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
    int n, res = 0;
    cin >> n;
    vector<int> v(n + 3), pos(n + 1);
    Seg<int> sg(n + 4);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) pos[v[i]] = i;
    for (int i = 1; i <= n; i++) sg.upd(i, v[i]);

    auto get_l = [&](int pos) {
        int l = 1, r = pos - 1, ans = -1;

        while (l <= r) {
            int md = l + (r - l) / 2;
            if (sg.query(md, pos) <= v[pos]) {
                r = md - 1;
                ans = md;
            } else l = md + 1;
        }
        return ans;
    };

    auto get_r = [&](int pos) {
        int l = pos + 1, r = n, ans = -1;
        while (l <= r) {
            int md = l + (r - l) / 2;
            if (sg.query(pos, md) <= v[pos]) {
                l = md + 1;
                ans = md;
            } else r = md - 1;
        }
        return ans;
    };
    for (int i = 2; i <= n - 1; i++) {
        int l = get_l(i);
        int r = get_r(i);
        if (l == -1 || r == -1) continue ;
        if (r - i < i - l) {
            for (int j = i + 1; j <= r; j++) {
                res += (pos[v[i] - v[j]] >= l && pos[v[i] - v[j]] <= i);
            }
        } else {
            for (int j = l; j <= i - 1; j++) {
                res += (pos[v[i] - v[j]] <= r && pos[v[i] - v[j]] >= i);
            }
        }
    }

    cout << res << endl;
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
