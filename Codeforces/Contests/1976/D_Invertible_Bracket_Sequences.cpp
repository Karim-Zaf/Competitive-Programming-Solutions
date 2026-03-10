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
struct Seg {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = -INF; /**/ int n;/**/ vector<T> seg;/**/
    T merge(T a, T b) { return max(a, b); } // Function
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
    int n, res = 0;
    string s;
    cin >> s;
    n = s.size();


    Seg<int> sg;
    sg.build(n + 4);

    s = "#" + s;
    vector<int> pref(n + 1);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        if (s[i]=='(') pref[i]=1 ;
        else pref[i]=-1 ;
        pref[i] += pref[i - 1];
    }
    for (int i =0; i <= n; i++) {
        mp[pref[i]].pb(i);
        sg.upd(i, pref[i]);
    }


    // a valid subsegment --> sum = 0  and maximum pic when reversed still >= 0
    for (int i = 1; i <= n ; i++) {
        int l = i, r = n, ans = -1;
        while (l <= r) {
            int md = l + (r - l) / 2;
            int mx = sg.query(i, md);
            int nw = mx - pref[i - 1];
            int fin = pref[i - 1] - nw;
            if (fin >= 0) {
                l = md + 1;
                ans = md;
            } else r = md - 1;
        }
        if (ans == -1) continue;
        int lef = lower_bound(all(mp[pref[i - 1]]), i) - mp[pref[i - 1]].begin();
        int righ = upper_bound(all(mp[pref[i - 1]]), ans) - mp[pref[i - 1]].begin() - 1;
        res += max(0ll, righ - lef + 1);
    }
    cout << res << endl;
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