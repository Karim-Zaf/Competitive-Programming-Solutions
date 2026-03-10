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
    const T ID = {INF, INF};
    int n;
    vector<T> seg;

    T merge(T a, T b) {
        if (a.F < b.F) return a;
        return b;
    }

    void init(int _n) { n = _n, seg.assign(2 * n, ID); }
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
const int DIG = 15;

void Solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n + 1);
    Seg<pair<int,int>> sg[DIG];
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int d = 0; d < DIG; d++) {
        sg[d].init(n + 5);
    }

    for (int i = 1; i <= n; i++) {
        string s = to_string(v[i]);
        reverse(all(s));
        for (int j = 0; j < s.size(); j++) if (s[j] != '0') sg[j].upd(i, {v[i], i});
    }

    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int pos, val;
            cin >> pos >> val;

            string s = to_string(v[pos]);
            reverse(all(s));
            for (int j = 0; j < s.size(); j++) sg[j].upd(pos, {INF, INF});


            v[pos] = val;
            s = to_string(v[pos]);
            reverse(all(s));
            for (int j = 0; j < s.size(); j++) if (s[j] != '0') sg[j].upd(pos, {v[pos], pos});


        } else {
            int l, r;
            cin >> l >> r;

            int ans = INF;


            for (int d = 0; d < DIG; d++) {
                auto [one,pos] = sg[d].query(l, r);
                if (pos == INF) continue ;
                auto [two , pos2] = min(sg[d].query(l, pos - 1), sg[d].query(pos + 1, r));
                ans = min(ans, one + two);
            }

            cout << (ans >= INF ? -1 : ans) << endl;

        }

    }

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
