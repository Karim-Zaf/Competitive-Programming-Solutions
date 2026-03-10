/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

template <class T> struct Seg { /*CHANGE THE ID YA KARIM !!*/
    const T ID = 0;
    int n;
    vector<T> seg;
    T merge(T a, T b) { return a + b; }
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
    int n, k, ans = 0;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    indexed_set seti, s[2];
    for (int i = 0; i < n; i++) seti.insert({a[i], i});
    for (int i = 0; i < n; i++) s[b[i]].insert({a[i], i});

    Seg<int> sg(n + 5);
    int pos = 0;
    for (auto& x : s[1]) { sg.upd(pos++, x.F); }


    auto work = [&](int x, int pos) -> bool {
        int nb = s[1].size() - s[1].order_of_key({x, -INF});
        int righ = s[1].size() - nb - 1;
        int l = 0, r = righ, ans_p = righ + 1;
        while (l <= r) {
            int md = l + (r - l) / 2;
            if ((righ - md + 1) * x - sg.query(md, righ) <= k) {
                r = md - 1;
                ans_p = md;
            } else l = md + 1;
        }
        nb += s[0].size() - s[0].order_of_key({x, -INF});
        nb += righ - ans_p + 1;


        return (nb >= (n + 1) / 2);
    };


    for (int i = 0; i < n; i++) {
        seti.erase({a[i], i});
        if (b[i] == 1) {
            ans = max(ans, a[i] + k + seti.find_by_order(n / 2 - 1)->F);
            seti.insert({a[i], i});
            continue ;
        }
        s[b[i]].erase({a[i], i});

        int l = 0, r = 3e9;

        while (l <= r) {
            int md = l + (r - l) / 2;
            if (work(md, i)) {
                l = md + 1;
                ans = max(ans, a[i] + md);
            } else r = md - 1;
        }

        s[b[i]].insert({a[i], i});
        seti.insert({a[i], i});
    }

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
