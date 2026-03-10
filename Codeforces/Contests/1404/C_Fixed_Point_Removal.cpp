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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e9 + 10;


/*----------------------------------------Lazy--------------------------------------------*/

pair<int, int> Tree[4 * N];
int a[N];
int lazy[4 * N], n;
int upd[4 * N];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    if (a.F < b.F) return a;
    if (a.F == b.F && a.F > b.F) return a;
    return b;
}

void unlazy(int id) {
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id].F += lazy[id];
    if (r < 4 * N) lazy[l] += lazy[id], lazy[r] += lazy[id];
    if (r < 4 * N) upd[l] = upd[r] = 1;
    upd[id] = lazy[id] = 0;
}

void build(int ns = 1, int ne = n, int id = 0) {
    if (ns == ne) {
        Tree[id] = {a[ns], ns};
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l);
    build(md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

void update(int qs, int qe, int val, int ns = 1, int ne = n, int id = 0) {
    unlazy(id);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe) {
        lazy[id] += val, upd[id] = 1;
        unlazy(id);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

pair<int, int> query(int qs, int qe, int ns = 1, int ne = n, int id = 0) {
    unlazy(id);
    if (qs > ne || qe < ns) return {INF, INF};
    if (qs <= ns && ne <= qe) return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}


vector<int> v;
vector<int> Treew[4 * N];

void build2(int ns = 1, int ne = n, int id = 0) {
    if (ns == ne) {
        Treew[id].pb(v[ns]);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build2(ns, md, l);
    build2(md + 1, ne, r);
    Treew[id].pb(INF);
    Treew[id].resize(Treew[l].size() + Treew[r].size());
    merge(all(Treew[l]), all(Treew[r]), Treew[id].begin());
}

int query2(int qs, int qe, int ns = 1, int ne = n, int id = 0) {
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe) {
        int lef = lower_bound(all(Treew[id]), qs) - Treew[id].begin();
        int righ = upper_bound(all(Treew[id]), qe) - Treew[id].begin();
        return righ - lef;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return query2(qs, qe, ns, md, l) + query2(qs, qe, md + 1, ne, r);
}

void Solve() {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        a[i] = i - a[i];
        if (a[i] < 0) a[i] = INF;
    }
    build();
    vector<vector<int>> vect;
    vector<int> curr;
    int prev = INF;


    while (true) {
        auto [val, indx] = query(1, n);

        if (val) break ;

        if (indx < prev) {
            sort(all(curr));
            if (prev != INF) vect.pb(curr);
            prev = indx;
            curr.clear();
        }
        update(indx, n, -1);
        update(indx, indx, INF);
        curr.pb(indx);
    }
    vect.pb(curr);


    v.resize(n + 1);
    for (auto curr : vect) {
        for (auto x : curr) v[x] = curr[0];
    }
    build2();
    while (q--) {
        int one, two;
        cin >> one >> two;

        int l = one + 1, r = n - two;
        cout << query2(l, r) << endl;
    }


}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
