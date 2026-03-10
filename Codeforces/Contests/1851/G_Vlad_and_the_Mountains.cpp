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


struct DSU {
    vector<int> sz, parent;

    void init(int n) {
        for (int i = 0; i < n; i++) {
            parent.pb(i);
            sz.pb(1);
        }
    }

    int get(int a) { return (parent[a] == a ? a : parent[a] = get(parent[a])); }

    bool unite(int a, int b) {
        if ((a = get(a)) == (b = get(b))) return false;
        if (sz[a] > sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int a) { return sz[get(a)]; }
};

void Solve() {
    int n, m, q;
    cin >> n >> m;

    vector<int> a(n);
    vector<pair<int, int>> roads(m);

    for (auto &x: a) cin >> x;
    for (auto &x: roads) cin >> x.F >> x.S;

    cin >> q;
    vector<array<int, 3>> queries(q);
    for (auto &x: queries) cin >> x[0] >> x[1] >> x[2];

    DSU dsu;
    dsu.init(n);

    /* ---------------------------------------------------------------------*/


    vector<int> ans(q);
    map<int, vector<array<int, 3>>> store;
    vector<array<int, 3>> edges;

    for (int i = 0; i < m; i++) {
        edges.pb({max(a[roads[i].F - 1], a[roads[i].S - 1]), roads[i].F - 1, roads[i].S - 1});
    }
    sort(all(edges));

    for (int i = 0; i < q; i++) {
        store[a[queries[i][0] - 1] + queries[i][2]].pb({i, queries[i][0] - 1, queries[i][1] - 1});
    }

    int p = 0;

    for (auto &[value, vect]: store) {
        while (p < m && edges[p][0] <= value) {
            dsu.unite(edges[p][1], edges[p][2]);
            p++;
        }

        for (auto [pos, aa, bb]: vect) {
            ans[pos] = dsu.same_set(aa, bb);
        }

    }

    for (int i = 0; i < q; i++) cout << (ans[i] ? "YES" : "NO") << endl;
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