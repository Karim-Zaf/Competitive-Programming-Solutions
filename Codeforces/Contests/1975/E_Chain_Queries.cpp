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

/*----------------------------------lazy-------------------------------------*/

int Tree[4 * N], a[N], pref[N], q;
int lazy[4 * N], n;
int upd[4 * N];

int merge(int a, int b) { return a + b; }

void unlazy(int id) {
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id] += lazy[id];
    lazy[l] += lazy[id], lazy[r] += lazy[id];
    upd[l] = upd[r] = 1, upd[id] = lazy[id] = 0;
}

void build(int ns = 1, int ne = n, int id = 0) {
    lazy[id] = upd[id] = 0;
    if (ns == ne) {
        Tree[id] = pref[ns];
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

int query(int qs, int qe, int ns = 1, int ne = n, int id = 0) {
    unlazy(id);
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe)return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}

/*----------------------------------LCa-------------------------------------*/

vector<int> graph[N], depth(N);
int up[N][30];

void dfs(int parent) {
    for (int i = 1; i < 28; i++)
        up[parent][i] = up[up[parent][i - 1]][i - 1];

    for (auto child: graph[parent]) {
        if (up[parent][0] == child)continue;
        depth[child] = depth[parent] + 1;
        up[child][0] = parent;
        dfs(child);
    }
}

int Binary_Lifting(int a, int k) {
    for (int i = 28; i >= 0; i--)
        if (k & (1 << i))
            a = up[a][i];
    return a;
}

int Lca(int a, int b) {
    if (depth[b] > depth[a]) swap(a, b);

    int k = depth[a] - depth[b];
    a = Binary_Lifting(a, k);
    if (a == b) return a;

    for (int i = 28; i >= 0; i--) {
        if (up[a][i] == up[b][i]) continue;
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}

int dist(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[Lca(a, b)];
}

/*----------------------------------euler-------------------------------------*/
int timer = 0, start[N], endd[N];

void Euler_Tour(int curr, int parent) {
    start[curr] = ++timer;
    for (auto child: graph[curr])
        if (child != parent)
            Euler_Tour(child, curr);
    endd[curr] = timer;
}

/*----------------------------------sg-------------------------------------*/

template<class T>
struct Seg {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = {0, 0, 0}; /**/ int n;/**/ vector<T> seg;/**/
    T comb(T a, T b) {
        if (a[2] == b[2] && a[1] > b[1]) return a;
        if (a[2] > b[2])return a;
        return b;
    } // Function
    void build(int _n) { n = _n, seg.assign(2 * n, ID); } /**/
    void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }/**/
    void upd(int p, T val) { seg[p += n] = val;/**/for (p /= 2; p; p /= 2)pull(p);/**/}/**/
    T query(int l, int r) {/**/T ra = ID, rb = ID;/**/for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1)ra = comb(ra, seg[l++]);/**/if (r & 1)rb = comb(seg[--r], rb);
        }/**/return comb(ra, rb);
    }/**/void print(int i = -1) {/**/while (++i < n)
            cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " ");/**/}
};

/*----------------------------------solution-------------------------------------*/

Seg<array<int, 3>> sg;

void dfs_rasmi(int curr, int parent = 0) {
    pref[start[curr]] = pref[start[parent]] + a[curr];

    for (auto child: graph[curr]) {
        if (child == parent)continue;
        dfs_rasmi(child, curr);
    }
}

set<pair<int, int>> sp;
set<int> khabi[N];

void init() {
    timer = 0;
    sg.build(n + 5);
    sp.clear();
    for (int i = 0; i <= n + 5; i++) {
        graph[i].clear();
        start[i] = endd[i] = depth[i] = pref[i] = 0;
        for (int j = 0; j < 30; j++) up[i][j] = 0;
        khabi[i].clear();
        int q = query(i, i);
        update(i, i, -q);
    }

}


void test() {
    if (sp.size() == 0) {
        cout << "NO\n";
        return;// thabet menha
    }
    if (sp.size() == 1) {
        cout << "YES\n";
        return;
    }

    auto [x, dep, cnt] = sg.query(0, n+2);
    int aa = prev(sp.end())->S, bb, bg = sp.begin()->S;



    if (cnt == 2 ) {
        int one = *khabi[dep].begin(), two = *next(khabi[dep].begin());
        if (Lca(aa, one) == one) bb = two;
        else bb = one;
    }

    int lc = Lca(aa, bg);
    if (cnt > 2 || cnt == 2 && Lca(aa, bb) != bg) {
        cout << "NO\n";
        return;
    }

    auto pre = [&](int u) {
        return query(start[u], start[u]);
    };

    if (cnt == 1) {
        int q = pre(aa) - pre(lc) + a[lc];
        if (dist(lc, aa) + 1 == q && q == sp.size())cout << "YES\n";
        else cout << "NO\n";
    } else {
        int q = pre(aa) + pre(bb) - 2 * pre(lc) + 1 * a[lc];
        if (dist(aa, bb) + 1 == q && q == sp.size())cout << "YES\n";
        else cout << "NO\n";
    }

}


void Solve() {

    cin >> n >> q;
    init();

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

    }
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    Euler_Tour(1, -1);
    dfs(1);
    dfs_rasmi(1);
    build();


    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            sp.insert({depth[i], i});
            khabi[depth[i]].insert(i);
            int sz = khabi[depth[i]].size();
            sg.upd(depth[i], {0, depth[i], sz});
        }


    }

    while (q--) {
        int u;
        cin >> u;
        if (a[u] == 0) {
            update(start[u], endd[u], 1);
            khabi[depth[u]].insert(u);
            sp.insert({depth[u], u});
        } else {
            update(start[u], endd[u], -1);
            khabi[depth[u]].erase(u);
            sp.erase({depth[u], u});
        }
        a[u] ^= 1;
        int sz = khabi[depth[u]].size();
        sg.upd(depth[u], {0, depth[u], sz});

        test();
    }

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