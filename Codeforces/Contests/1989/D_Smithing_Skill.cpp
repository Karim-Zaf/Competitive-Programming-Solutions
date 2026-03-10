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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

template<class T>
struct Seg { // comb(ID,b) = b
    T ID;
    ll n;
    vector<T> seg;
    function<T(T, T)> comb;

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
};

//template<class T>
//struct Seg {  /*CHANGE THE ID YA KARIM !!*/
//    const T ID = {-INF, -INF}; /**/ int n;/**/ vector<T> seg;/**/
//    T merge(T a, T b) {
//        if (a.S > b.S) return a;
//        return b;
//    } // Function
//    void build(int _n) { n = _n, seg.assign(2 * n, ID); } /**/
//    void pull(int p) { seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }/**/
//    void upd(int p, T val) { seg[p += n] = val;/**/for (p /= 2; p; p /= 2)pull(p);/**/}/**/
//    T query(int l, int r) {/**/T ra = ID, rb = ID;/**/for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
//            if (l & 1)ra = merge(ra, seg[l++]);/**/if (r & 1)rb = merge(seg[--r], rb);
//        }/**/return merge(ra, rb);
//    }/**/void print(int i = -1) {/**/while (++i < n)
//            cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " ");/**/}
//};

int dp[N];
vector<pair<int, int>> vp{{0, 0}};

Seg<pair<int, int>> sg;

int work(int x) {
    if (x == 0)return 0;
    if (x >= N) {
        pair<int, int> p = {x, INF};
        int pos = lower_bound(all(vp), p) - vp.begin() - 1;
        auto [ai, cost] = sg.query(0, pos);
        cost *= -1;

        if (pos == 0) return 0;

        int diff = x - ai;
        int nakkes = (diff / cost + 1) * cost;

        return 2 * (diff / cost + 1) + work(x - nakkes);
    }
    int &ret = dp[x];
    if (ret != -1)return ret;


    ret = 0;
    pair<int, int> p = {x, INF};
    int pos = lower_bound(all(vp), p) - vp.begin() - 1;
    auto [ai, cost] = sg.query(0, pos);
    cost *= -1;

    if (pos == 0) return 0;

    int diff = x - ai;
    int nakkes = (diff / cost + 1) * cost;

    ret += 2 * (diff / cost + 1);
    ret += work(x - nakkes);
    return ret;
}

void Solve() {
    int n, m;
    cin >> n >> m;
    sg.ID = {-INF, -INF};
    sg.comb = [](pair<int, int> a, pair<int, int> b) {
        if (a.S > b.S) return a;
        return b;
    };

    sg.build(n + 6);


    memset(dp, -1, sizeof(dp));


    vector<int> a(n + 1), b(n + 1), c(m + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> c[i];

    for (int i = 1; i <= n; i++)
        vp.pb({a[i], -a[i] + b[i]});

    sort(all(vp));

    for (int i = 1; i <= n; i++)
        sg.upd(i, vp[i]);
//    sg.print();
    sort(all(c));

    int ans = 0;
    for (auto metal: c) {
        ans += work(metal);
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