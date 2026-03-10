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

const int N = 1e6 + 4;


template<class T>
struct Seg {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = 1e9; /**/ int n;/**/ vector<T> seg;/**/
    T merge(T a, T b) { return min(a, b); } // Function
    void build(int _n) { n = _n, seg.assign(2 * n, 1e9); } /**/
    void pull(int p) { seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }/**/
    void upd(int p, T val) { seg[p += n] = val;/**/for (p /= 2; p; p /= 2)pull(p);/**/}/**/
    T query(int l, int r) {/**/T ra = ID, rb = ID;/**/for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1)ra = merge(ra, seg[l++]);/**/if (r & 1)rb = merge(seg[--r], rb);
        }/**/return merge(ra, rb);
    }/**/void print(int i = -1) {/**/while (++i < n)
            cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " ");/**/}
};

vector<int> values[N];
vector<array<int, 3>> queries[N];

void Solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n + 3), ans(q, -1);

    Seg<int> sg;
    sg.build(N);

    for (int i = 0; i < N; i++) sg.upd(i, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        queries[r].pb({l, x, i});
    }

    for (int i = 1; i <= n; i++) {
        sg.upd(v[i], i);

        for (auto &[l, x, p]: queries[i]) {
            ans[p] = x;
            int lef = 0, righ = x;
            while (lef <= righ) {
                int md = lef + (righ - lef) / 2;
                if (sg.query(md, x) >= l) {
                    righ = md - 1;
                    ans[p] = md - 1;
                } else
                    lef = md + 1;
            }
        }
    }
    for (auto &x: ans) cout << x << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    //cin >> Test_case;
    while (Test_case--) Solve();
}