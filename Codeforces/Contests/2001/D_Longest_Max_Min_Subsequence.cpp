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

template <class T> struct Seg_MAX { /*CHANGE THE ID YA KARIM !!*/
    const T ID = -INF;
    int n;
    vector<T> seg;
    T merge(T a, T b) { return max(a, b); }
    Seg_MAX(int _n) { n = _n, seg.assign(2 * n, ID); }
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
template <class T> struct Seg_MIN { /*CHANGE THE ID YA KARIM !!*/
    const T ID = INF;
    int n;
    vector<T> seg;
    T merge(T a, T b) { return min(a, b); }
    Seg_MIN(int _n) { n = _n, seg.assign(2 * n, ID); }
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
    int n;
    cin >> n;
    vector<int> v(n), ok(n), mp[n + 1], ans;
    for (auto& x : v) cin >> x;

    Seg_MIN<int> blasa(n + 2);
    Seg_MIN<int> mn(n + 2);
    Seg_MAX<int> mx(n + 2);

    for (int i = 0; i < n; i++) {
        blasa.upd(v[i], i);
        mx.upd(i, v[i]);
        mn.upd(i, v[i]);
        mp[v[i]].pb(i);
    }


    set<int> s(all(v));
    int m = s.size();

    int pos = 0;
    for (int i = 0; i < m; i++) {
        int j = blasa.query(0, n);
        int curr;
        if (i % 2 == 0) curr = mx.query(pos, j);
        else curr = mn.query(pos, j);

        for (auto pos : mp[curr]) {
            mx.upd(pos, -INF);
            mn.upd(pos, INF);
        }

        pos = *lower_bound(all(mp[curr]), pos);

        blasa.upd(curr, INF);
        ans.pb(curr);
    }


    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
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
