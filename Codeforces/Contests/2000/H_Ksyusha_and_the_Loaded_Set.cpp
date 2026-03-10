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

const int N = 3e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

template <class T> struct Seg { /*CHANGE THE ID YA KARIM !!*/
    const T ID = INF;
    int n;
    vector<T> seg;
    T merge(T a, T b) { return min(a, b); }
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

Seg<int> sg(N);

void Solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto& x : v) cin >> x;
    map<int, set<int>> mp;
    set<int> s;


    auto upd = [&](int k) {
        if (mp[k].empty()) sg.upd(k, INF);
        else sg.upd(k, *mp[k].begin());
    };
    auto add = [&](int x) {
        auto it = s.lower_bound(x);
        if (it != s.begin() && it != s.end()) {
            int r = *it, l = *prev(it);
            mp[r - l].erase(l);
            upd(r - l);
        }


        if (it != s.end()) {
            int nxt = *it;
            mp[nxt - x].insert(x);
            upd(nxt - x);
        }


        if (it != s.begin()) {
            int prv = *prev(it);
            mp[x - prv].insert(prv);
            upd(x - prv);
        }
        s.insert(x);
    };


    auto rmv = [&](int x) {
        s.erase(x);
        auto it = s.lower_bound(x);
        if (it != s.begin() && it != s.end()) {
            int r = *it, l = *prev(it);
            mp[r - l].insert(l);
            upd(r - l);
        }


        if (it != s.end()) {
            int nxt = *it;
            mp[nxt - x].erase(x);
            upd(nxt - x);
        }


        if (it != s.begin()) {
            int prv = *prev(it);
            mp[x - prv].erase(prv);
            upd(x - prv);
        }

    };

    for (auto x : v) add(x);
    add(0);
    int q;
    cin >> q;
    while (q--) {
        char c;
        int x;
        cin >> c >> x;


        if (c == '?') {
            int ans = sg.query(x + 1, N - 2) + 1;
            if (ans >= INF) ans = *prev(s.end()) + 1;
            cout << ans << " ";
        }
        if (c == '+') add(x);
        if (c == '-') rmv(x);
    }
    cout << endl;
    for (auto x : mp) {
        sg.upd(x.F, INF);
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
