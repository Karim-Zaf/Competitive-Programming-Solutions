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
    const T ID = 0;
    int n;
    vector<T> seg;
    T merge(T a, T b) { return (a ^ b); }
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
    int n;
    cin >> n;
    vector<int> v(n + 4), xr(n + 5);
    map<int, vector<pair<int,int>>> mp;
    map<int,int> lst;

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) xr[i] = xr[i - 1] ^ v[i];

    int q;
    cin >> q;
    vector<int> ans(q);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        mp[r].pb({l, i});
    }

    Seg<int> sg(n + 5);
    for (int i = 1; i <= n; i++) {
        sg.upd(lst[v[i]], 0);
        lst[v[i]] = i;
        sg.upd(i, v[i]);
        for (auto [l,pos] : mp[i]) {
            ans[pos] = xr[i] ^ xr[l - 1];
            sg.query(l, i);
            ans[pos] ^= sg.query(l, i);
        }
    }
    for (auto x : ans) cout << x << endl;
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
