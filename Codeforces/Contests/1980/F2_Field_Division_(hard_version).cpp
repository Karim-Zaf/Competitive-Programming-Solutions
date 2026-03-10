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

    int n, m, k, res = 0;
    cin >> n >> m >> k;
    Seg<int> sg;
    sg.build(k + 4);

    map<int, int> mp;
    map<int, vector<pair<int, int>>> vect;
    vector<int> ans(k + 3), ans_suff(k + 4), ans_pref(k + 4), pref_mx(k + 4);
    vector<array<int, 3>> vp(k + 2);
    for (int i = 1; i <= k; i++) cin >> vp[i][0] >> vp[i][1];
    for (int i = 0; i <= k + 1; i++) vp[i][2] = i;

    vp[k + 1] = {0, m + 1};
    vp[0][1] = 1;
    sort(all(vp), [](array<int, 3> a, array<int, 3> b) -> bool {
        if (a[1] < b[1]) return true;
        if (a[1] == b[1] && a[0] < b[0]) return true;
        return false;
    });

    for (int i = 0; i <= k + 1; i++) {
        mp[vp[i][1]] = max(mp[vp[i][1]], vp[i][0]);
        vect[vp[i][1]].pb({vp[i][0], i});
        sg.upd(i, vp[i][0]);
    }

    vector<pair<int, int>> st{{INF, k + 1}};
    for (int i = k; i >= 0; i--) {
        while (vp[i][0] >= st.back().F)st.pop_back();
        auto [prec, indx] = st.back();

        ans_suff[i] = ans_suff[indx] + abs(vp[i][1] - vp[indx][1]) * (n - vp[i][0]);
        st.pb({vp[i][0], i});
    }


    /*--------------------------------ans----------------------------------*/
    int lst = 1;
    int suff = 0;

    for (int i = 1; i <= k + 1; i++) {
        int key = vp[i][1];
        ans_pref[i] = ans_pref[i - 1];
        ans_pref[i] += (key - lst) * (n - suff);
        suff = max(suff, vp[i][0]);
        lst = key;
        pref_mx[i] = suff;
    }
    cout << ans_pref[k + 1] << endl;

    /*------------------------------for each interval-------------------------------*/
    res = ans_pref[k + 1];
    for (int i = 1; i <= k; i++) {
        if (vp[i][1] == vp[i + 1][1] || vp[i][0] <= pref_mx[i - 1]) continue;

        sg.upd(i, -INF);

        int l = i - 1, r = k + 1, temp = -1;

        while (l <= r) {//upper_bound bkadrou
            int md = l + (r - l) / 2;
            int mx = sg.query(i, md);
            if (mx >= pref_mx[i - 1]) {
                r = md - 1;
                temp = md;
            } else {
                l = md + 1;
            }
        }
        int curr_ans = ans_pref[i - 1];
        if (temp == -1) curr_ans += (m - vp[i - 1][1] + 1) * (n - pref_mx[i - 1]);
        else curr_ans += ans_suff[temp] + (vp[temp][1] - vp[i - 1][1]) * (n - pref_mx[i - 1]);

        sg.upd(i, vp[i][0]);
        ans[vp[i][2]] = curr_ans - res;
    }

    for (int i = 1; i <= k; i++)cout << ans[i] << " ";
    cout << endl;

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