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

template<class T>
struct Seg1 { // comb(ID,b) = b
    const T ID = 0;
    ll n;
    vector<T> seg;

    T comb(T a, T b) { return a + b; }

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

template<class T>
struct Seg2 { // comb(ID,b) = b
    const T ID = 1e9;
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


void Solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    Seg1<int> sum;
    Seg2<int> mn;
    sum.build(n + 1);
    mn.build(n + 1);
    map<int, set<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mn.upd(i, v[i]);
        mp[v[i]].insert(i);
    }
    int sum_all = accumulate(all(v), 0ll);
    set<array<int, 4>, greater<>> s;
    vector<array<int, 2>> inter;
    s.insert({n, 0, n - 1, 0});

    while (!s.empty()) {
        auto [len, l, r, nahhit] = *s.begin();
        s.erase(*s.begin());
        int mini = mn.query(l, r);
        int lef = l;
        while (lef <= r && v[lef] == mini)lef++;

        auto it = mp[mini].lower_bound(l);
        while (true) {
            if (it == mp[mini].end() || (*it) > r)break;
            int indx = (*it);
            int righ = indx - 1;
            if (righ >= lef) {
                s.insert({righ - lef + 1, lef, righ, mini});
            }
            lef = indx + 1;
            it++;
        }
        if (r >= lef) {
            s.insert({r - lef + 1, lef, r, mini});
        }
        inter.pb({r - l + 1, mini - nahhit});
    }

    int i = 0, acc = 0, op = 0;
    while (q--) {
        int x;
        cin >> x;
        op += x;
        if (i >= inter.size()) {
            cout << 0 << endl;
            continue;
        }
        auto [len, nb] = inter[i];
        while (acc + nb <= op) {
            acc += nb;
            sum_all -= len * nb;
            i++;
            if (i >= n) break;
            len = inter[i][0];
            nb = inter[i][1];
        }
        int curr = sum_all;
        if (i < n && acc < op) {
            curr -= (op - acc) * inter[i][0];
        }
        cout << curr << endl;
    }
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
