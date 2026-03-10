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

vector<array<int, 3>> edges;
int n, cnt = 0;

int SpanningTree() {
    int ret = 0;
    cnt = 0;
    sort(all(edges));
    DSU dsu;
    dsu.init(n + 2);

    for (auto [x, u, v]: edges) {
        if (dsu.same_set(u, v))continue;
        ret += x;
        dsu.unite(u, v);
        cnt++;
    }
    edges.clear();
    return ret;
}

void Solve() {
    cin >> n;
    map<int, vector<pair<int, int>>> l, r;
    set<int> seti;
    for (int i = 1, lef, righ, x; i <= n; i++) {
        cin >> lef >> righ >> x;
        l[lef].pb({x, i});
        r[righ].pb({x, i});
        seti.insert(lef);
        seti.insert(righ);
    }

    vector<int> v(all(seti));

    set<pair<int, int>> s;

    for (auto pos: v) {

        for (auto x: l[pos]) s.insert(x);
        for (auto [x, ind]: r[pos]) {
            auto it = s.lower_bound({x, ind});
            it++;
            if (it != s.end()) edges.pb({abs(x - it->F), ind, it->S});
            it--;
            if (it == s.begin()) continue;
            it--;
            edges.pb({abs(x - it->F), ind, it->S});
        }
        for (auto x: r[pos]) s.erase(x);
    }

    int ans = SpanningTree();
    cout << (cnt == n - 1 ? ans : -1) << endl;

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