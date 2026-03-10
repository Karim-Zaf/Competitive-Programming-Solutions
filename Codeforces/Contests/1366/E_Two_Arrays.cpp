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

const int N = 3e5 + 30, mod = 998244353, INF = 1e18 + 10;

template<class T>
struct Seg { // comb(ID,b) = b
    const T ID = INF;
    ll n;
    vector<T> seg;

    T comb(T a, T b) { return min(a, b); }

    void build(ll _n) {
        n = _n;
        seg.assign(2 * n, ID);
    }

    void pull(ll p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }

    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }

    void print() {
        for (int i = 0; i < n; i++)cout << query(i, i) << " ";
        cout << '\n';
    }
};

int binpow(int a, int k, int res = 1, int Mod = mod) {
    while (k) {
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a, int Mod = mod) { return binpow(a, Mod - 2); }

int mult(int a, int b, int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }

int divide(int a, int b, int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}


void Solve() {
    int n, m, ans = 1;
    cin >> n >> m;

    vector<int> a(n + 1), b(m);
    map<int, int> mp;
    Seg<int> sg;
    vector<pair<int, int>> vp;
    sg.build(n + 5);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
        sg.upd(i, a[i]);
    }

    for (auto &x: b) cin >> x;

    for (auto mn: b) {

        int pos = mp[mn];
        if (!mn) {
            cout << 0 << endl;
            return;
        }
        int l = 1, r = pos, ansl = -1, ansr = -1;
        while (l <= r) {
            int md = l + (r - l) / 2;
            if (sg.query(md, pos) >= mn) {
                ansl = md;
                r = md - 1;
            } else l = md + 1;
        }

        l = pos, r = n;

        while (l <= r) {
            int md = l + (r - l) / 2;
            if (sg.query(pos, md) >= mn) {
                ansr = md;
                l = md + 1;
            } else r = md - 1;
        }
        if (ansr != n) {
            cout << 0 << endl;
            return;
        }
        vp.pb({ansl, pos});
    }

    if (sg.query(1, n) != b.front()) {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i < vp.size(); i++) {
        ans = mult(ans, vp[i].S - vp[i].F + 1);
    }
    cout << ans << endl;

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}