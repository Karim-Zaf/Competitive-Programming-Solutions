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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10, LG = 32;
/*----------------------------------------Lazy--------------------------------------------*/

int Tree[LG][4 * N], a[N];
int lazy[LG][4 * N], n;
int upd[4 * N];

int merge(int a, int b) { return a + b; }

void unlazy(int id, int ns, int ne) {
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    for (int i = 0; i < 30; i++) if (lazy[i][id]) Tree[i][id] = (ne - ns + 1) - Tree[i][id];

    upd[l] = upd[r] = 1;
    upd[id] = 0;
    for (int i = 0; i < LG; i++) lazy[i][l] ^= lazy[i][id], lazy[i][r] ^= lazy[i][id];
    for (int i = 0; i < LG; i++) lazy[i][id] = 0;
}

void build(int ns = 1, int ne = n, int id = 0) {
    if (ns == ne) {
        for (int i = 0; i < LG; i++) if ((1 << i) & a[ns]) Tree[i][id]++;
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l);
    build(md + 1, ne, r);
    for (int i = 0; i < LG; i++) Tree[i][id] = Tree[i][l] + Tree[i][r];
}

void update(int qs, int qe, int val, int ns = 1, int ne = n, int id = 0) {
    unlazy(id, ns, ne);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe) {
        for (int i = 0; i < LG; i++) {
            if ((1 << i) & val) lazy[i][id] ^= 1;
        }
        upd[id] = 1;
        unlazy(id, ns, ne);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);

    for (int i = 0; i < LG; i++) Tree[i][id] = Tree[i][l] + Tree[i][r];
}

int query(int qs, int qe, int ns = 1, int ne = n, int id = 0) {
    unlazy(id, ns, ne);
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe) {
        int ret = 0;
        for (int i = 0; i < LG; i++) ret += (1 << i) * Tree[i][id];
        return ret;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return query(qs, qe, ns, md, l) + query(qs, qe, md + 1, ne, r);
}

void Solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    build();


    int q;
    cin >> q;
    while (q--) {
        int x, l, r;
        cin >> x >> l >> r;
        if (x == 1) {
            cout << query(l, r) << endl;
        } else {
            cin >> x;
            update(l, r, x);
        }
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
