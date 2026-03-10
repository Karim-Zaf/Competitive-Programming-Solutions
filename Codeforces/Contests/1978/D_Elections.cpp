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

template<class T>
struct Seg {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = 0; /**/ int n;/**/ vector<T> seg;/**/
    T merge(T a, T b) { return a + b; } // Function
    void build(int _n) { n = _n, seg.assign(2 * n, ID); } /**/
    void pull(int p) { seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }/**/
    void upd(int p, T val) { seg[p += n] = val;/**/for (p /= 2; p; p /= 2)pull(p);/**/}/**/
    T query(int l, int r) {/**/T ra = ID, rb = ID;/**/for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1)ra = merge(ra, seg[l++]);/**/if (r & 1)rb = merge(seg[--r], rb);
        }/**/return merge(ra, rb);
    }/**/void print(int i = -1) {/**/while (++i < n)
            cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " ");/**/}
};

void Solve() {
    int n, c;
    cin >> n >> c;

    vector<int> v(n), id(n), ans(n);
    Seg<int> sum, nb;

    sum.build(n + 2);
    nb.build(n + 2);

    for (auto &x: v) cin >> x;
    vector<int> nw_v = v;
    vector<pair<int, int>> vp(n);

    for (int i = 0; i < n; i++) {
        vp[i].S = i;
        vp[i].F = v[i];
    }
    sort(all(vp));

    for (int i = 0; i < n; i++)
        id[vp[i].S] = i;

    for (int i = 0; i < n; i++) {
        sum.upd(i, vp[i].F);
        nb.upd(i, 1);
    }

    int mx = *max_element(all(v));
    mx = max(mx, v[0] + c);


    for (int i = 0; i < n; i++) vp[i].S = id[i];
    sort(all(vp));

    set<pair<int, int>> s(all(vp));

    for (int i = 0; i < n; i++) {
        sum.upd(id[i], 0);
        nb.upd(id[i], 0);
        s.erase({v[i], id[i]});

        v[i] = nw_v[i] + c;
        int l = id[i] + 1, r = n, res = n + 1;

        while (l <= r) {
            int md = l + (r - l) / 2;
            pair<int, int> p = {vp[md].F, md};
            if (md >= n) p.F = mx;
            auto it = s.lower_bound(p);

            if (it == s.begin()) {
                l = md + 1;
                res = md;
            } else {
                it--;
                if (sum.query(md, n + 1) + v[i] >= it->F) {
                    l = md + 1;
                    res = md;
                } else r = md - 1;
            }
        }
        ans[i] = i + nb.query(res, n + 1);
        c += nw_v[i];
    }


    if (v[0] >= mx) {
        ans[0] = 0;
        mx = INF;
    }

    for (int i = 0; i < n; i++)
        if (nw_v[i] >= mx) {
            ans[i] = 0;
            mx = INF;
        }
    for (auto x: ans) cout << x << " ";
    cout << endl;

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