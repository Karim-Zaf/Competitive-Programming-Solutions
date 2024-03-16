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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;


template<class T> struct Seg { // comb(ID,b) = b
    T ID ; ll n; vector<T> seg; function <T(T,T)> comb ;
    void build(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }return comb(ra,rb);
    }
};


void Solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    Seg<int> mn, mx;
    mn.ID = INF, mx.ID = -INF;
    mn.comb = [](int x, int y) { return min(x, y); };
    mx.comb = [](int x, int y) { return max(x, y); };
    mn.build(10 * n + 1), mx.build(n + 1);
    vector<int> nxt(n + 5, INF), pref(n + 1);

    pref[0] = n + 3;
    for (int i = 0; i <= n; i++) {
        if (i)pref[i] = pref[i - 1] + (s[i - 1] == '*' ? 1 : -1);
        mx.upd(i, pref[i]);
    }

    for (int i = n; i >= 1; i--) {
        int curr = pref[i];
        mn.upd(curr, min(i, mn.query(curr, curr)));
        nxt[i] = mn.query(0, pref[i - 1] - 1);
    }

    while (q--) {
        int lef, righ;
        cin >> lef >> righ;
        int curr = pref[lef - 1];
        if (nxt[lef] > righ) {
            cout << mx.query(lef, righ) - curr + 1 << endl;
            continue;
        }
        cout << max(0ll, mx.query(lef, nxt[lef]) - curr) + 2 << endl;
    }
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
