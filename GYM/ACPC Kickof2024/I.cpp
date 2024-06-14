/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "debug.cpp"
// #else
// #define kar(...)
// #endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

template<class T>
struct Seg {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = {0, 0}; /**/ int n;/**/ vector<T> seg;/**/
    T merge(T a, T b) {
        if (a.F > b.F || a.F == b.F && a.S < b.S) return a;
        return b;

    } // Function
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


    int n;
    cin >> n;

    vector<array<int, 3>> v(n);
    for (auto &[a, b, c]: v)cin >> a >> b >> c;


    sort(all(v), [](array<int, 3> a, array<int, 3> b) {
        if (a[1] < b[1])return true;
        return false;
    });


    map<int, int> comp;

    for (auto [a, b, c]: v) comp[a] = comp[b] = 1;

    int cnt = 1;
    for (auto x: comp) comp[x.F] = ++cnt;


    for (auto &[a, b, c]: v) a = comp[a], b = comp[b];


    Seg<pair<int, int>> dp;
    dp.build(cnt + 5);

    for (auto [a, b, c]: v) {
        auto [ret, focus] = dp.query(0, a-1);

        ret++;
        focus = max(focus, c);

        auto p = dp.query(b, b);
        if (ret > p.F || ret == p.F && focus < p.S) dp.upd(b, {ret, focus});
    }

    auto [ret, focus] = dp.query(0, cnt + 4);
    cout << ret << " " << focus << endl;
}

int32_t main() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
//    #endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
