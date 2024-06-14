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
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(m);

    map<pair<int, int>, int> mp;

    for (auto &[u, v, w]: edges) {
        cin >> u >> v >> w;
        mp[{u, v}] |= w;
    }

    edges.clear();
    for (auto [ed, w]: mp)
        edges.pb({ed.F, ed.S, w});

    int q;
    cin >> q;
    vector<array<int, 3>> queries(q);
    vector<int> ans(q);
    for (auto &[l, r, j]: queries) cin >> l >> r;
    for (int j = 0; j < q; j++) queries[j][2] = j;


    for (int i = 1024; i >= 1; i--) {
        DSU dsu;
        dsu.init(n + 1);

        for (auto [u, v, w]: edges) {
            if ((i | w) == i)
                dsu.unite(u, v);
        }

        for (auto [l, r, j]: queries) {
            if (dsu.same_set(l, r))
                ans[j] = i;
        }
    }
    for (auto x: ans) cout << x << endl;
}

int32_t main() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
//    #endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
