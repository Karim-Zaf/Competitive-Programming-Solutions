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


template<class T>
struct Seg { // comb(ID,b) = b
    const T ID = -INF;
    ll n;
    vector<T> seg;

    T comb(T a, T b) { return max(a, b); }

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
    int n;
    cin >> n;

    Seg<int> sg;
    sg.build(n + 4);

    vector<int> v(n + 1), dp(n + 1), pos(n + 1), vals(n + 1, -INF);
    for (int i = 1; i <= n; i++)cin >> v[i];


    for (int i = 1; i <= n; i++) {
        if (!pos[v[i]])pos[v[i]] = i;
        else {
            int prv = pos[v[i]];

            int tryy = sg.query(prv, i) + prv;

            tryy += (i - prv - 1);

            dp[i] = max(dp[i], tryy);
            dp[i] = max(dp[i], i - prv - 1 + dp[prv - 1]);

            sg.upd(i, dp[i] - i);
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n] << endl;
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