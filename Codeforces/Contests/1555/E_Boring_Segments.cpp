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
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e8 + 10;


template<class T>
struct Lazy {
    int n;/**/T ID = 0;/**/vector<T> Tree, lazy, updated;/**/
    function<T(T, T)> merge;// Merge function
    void init(int _n) { n = _n, Tree.assign(n << 2, ID), lazy.assign(n << 2, ID), updated.assign(n << 2, 0); }/**/
    /*Push down the update*/void unlazy(int id) {
        if (updated[id] == 0)return;
        int l = (id << 1) + 1, r = (id << 1) + 2;
        Tree[id] = lazy[id];
        lazy[l] = lazy[id], lazy[r] = lazy[id], Tree[l] = lazy[id], Tree[r] = lazy[id];
        updated[id] = 0;
        updated[l] = updated[r] = 1;
    }/*UPDATING*/void upd(int qs, int qe, int val, int ns, int ne, int id) {
        if (qs > ne || qe < ns) return;
        if (qs <= ns && ne <= qe) {/**/updated[id] = 1, Tree[id] = val, lazy[id] = val;/**/return;/**/} /**/unlazy(id);
        int l = (id << 1) + 1, r = (id << 1) + 2, md = (ne + ns) >> 1;
        upd(qs, qe, val, ns, md, l), upd(qs, qe, val, md + 1, ne, r);
        Tree[id] = merge(Tree[l], Tree[r]);
    }/*Get_Update*/void upd(int qs, int qe, int val) { upd(qs, qe, val, 1, n, 0); }/**/
    /*QUERYING*/T query(int qs, int qe, int ns, int ne, int id) {
        if (qs > ne || qe < ns) return ID;
        if (qs <= ns && ne <= qe)return Tree[id];/**/unlazy(id);
        int l = (id << 1) + 1, r = (id << 1) + 2, md = (ne + ns) >> 1;
        return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
    }/*GET_QUERY*/T query(int qs, int qe) { return query(qs, qe, 1, n, 0); }
};

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> vp(n);

    Lazy<int> mx, mn;
    mx.ID = -INF, mn.ID = INF;
    mx.merge = [](int a, int b) { return max(a, b); };
    mn.merge = [](int a, int b) { return min(a, b); };
    mx.init(2 * m + 3), mn.init(2 * m + 3);

    for (auto &x: vp) {
        cin >> x[1] >> x[2] >> x[0];
        x[1] <<= 1;
        x[2] <<= 1;
    }
    for (int i = 1; i <= 2 * m+1; i++) {
        mx.upd(i, i, INF);
        mn.upd(i, i, -INF);
    }
    sort(all(vp));
    int ans = INF;

    for (auto [x, l, r]: vp) {
        mx.upd(l, r, x);
        mn.upd(l, r, x);
        int maxi = mx.query(2, 2*m );
        int mini = mn.query(2, 2*m );
        int diff = maxi - mini;
        if (diff >= 0 && diff <= 1e7) ans = min(ans, maxi - mini);
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