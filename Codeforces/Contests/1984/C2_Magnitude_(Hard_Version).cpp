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

const int N = 3e5 + 30, mod = 998244353, INF = 1e18 + 10;


typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

int binpow(int a, int k, int res = 1, int Mod = mod) {
    if (k < 0)return 0;
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


template<class T>
struct Seg {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = INF; /**/ int n;/**/ vector<T> seg;/**/
    T merge(T a, T b) { return min(a, b); } // Function
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
    int n, ans = 0;
    cin >> n;
    vector<int> v(n + 1), pref(n + 2), suff(n + 4);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];
    for (int i = n; i >= 1; i--) suff[i] = suff[i + 1] + v[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];

    int mx = 0;
    for (int i = 0; i <= n; i++) {
        mx = max(mx, abs(pref[i]) + suff[i + 1]);
    }

    Seg<int> sg;
    sg.build(n + 2);

    indexed_set lef, righ;

    map<int, vector<int>> mp;
    for (int i = 0; i <= n; i++)sg.upd(i, pref[i]);
    for (int i = 1; i <= n; i++)righ.insert({pref[i], i});


    for (int i = 1; i <= n; i++) {// rod belek kaad tebda ml index 1
        lef.insert({pref[i], i});
        righ.erase({pref[i], i});
        if (abs(pref[i]) + suff[i + 1] != mx) continue;

        int one = lef.size() - lef.order_of_key({0, -INF});
        int two = righ.size() - righ.order_of_key({pref[i], -INF});

        ans = add(ans, binpow(2, one + two));
    }

    if (mx == pref[n]) ans = binpow(2, n);

    cout << ans << endl;
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