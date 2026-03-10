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
    vector<int> par, sz, w;
    vector<array<int, 3>> op;
    bool flag;

    DSU() {
    }

    DSU(int n) {
        par.resize(n + 1);
        sz.resize(n + 1);
        w.resize(n + 1);
        flag = true;
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            sz[i] = 1;
            w[i] = 0;
        }
    }

    bool is_bipartite() {
        return flag;
    }

    pair<int, int> find(int u) {
        int ans = 0;
        while (par[u] != u) {
            ans ^= w[u];
            u = par[u];
        }
        return make_pair(u, ans);
    }

    bool merge(int u, int v) {
        auto pu = find(u), pv = find(v);
        u = pu.first;
        v = pv.first;
        int last = flag;
        int z = pu.second ^ pv.second ^ 1;
        if (u == v) {
            if (z) {
                flag = false;
            }
            op.push_back({-1, -1, last});
            return false;
        }
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        op.push_back({u, w[u], last});
        par[u] = v;
        w[u] = z;
        sz[v] += sz[u];
        return true;
    }

    void undo() {
        assert(!op.empty());
        auto x = op.back();
        flag = x[2];
        int u = x[0];
        if (u != -1) {
            sz[par[u]] -= sz[u];
            par[u] = u;
            w[u] = x[1];
        }
        op.pop_back();
    }
};


void Solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 5);

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        dsu.merge(u, v);
    }
    int q;
    cin >> q;

    // for (int i = 1; i <= n; i++) cout << dsu.find(i) << " ";
    // cout << endl;
    while (q--) {
        int sz;
        cin >> sz;

        bool ok = false;
        for (int i = 1; i <= sz; i++) {
            int a, b;
            cin >> a >> b;
            ok |= (dsu.find(a).F == dsu.find(b).F);

            dsu.merge(a, b);
        }
        cout << (ok ? "Cycle" : "Nop") << endl;
        while (sz--) dsu.undo();
        // for (int i = 1; i <= n; i++) cout << dsu.find(i) << " ";
        // cout << endl;
    }


}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
