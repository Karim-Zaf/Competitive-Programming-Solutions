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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
typedef tree<pair<int,int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;


/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

struct DSU {
    vector<int> sz, parent;
    vector<indexed_set> v;
    vector<set<pair<int,int>>> mp;
    int n;

    DSU(int _n) {
        n = _n;
        mp.resize(n + 5);
        for (int i = 0; i < n; i++) {
            indexed_set x;
            x.insert({i, i});
            v.pb(x);
            parent.pb(i);
            sz.pb(1);
            mp[i].insert({i, 0});
        }
    }

    int get(int a) { return (parent[a] == a ? a : parent[a] = get(parent[a])); }

    bool unite(int a, int b, int time) {
        if ((a = get(a)) == (b = get(b))) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];

        for (auto& [l,r] : v[b]) {
            pair<int,int> add = {l, r};
            auto it = v[a].lower_bound({r, -INF});

            if (it != v[a].end() && it->F == r + 1) {
                add.S = it->S;
                v[a].erase(*it);
            }

            it = v[a].lower_bound({r, -INF});

            if (it != v[a].begin()) {
                it--;
                if (it->S == l - 1) {
                    add.F = it->F;
                    v[a].erase(*it);
                }
            }

            v[a].insert(add);
            mp[add.F].insert({add.S, time});
        }
        return true;
    }

    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int a) { return sz[get(a)]; }
};

void Solve() {
    int n, m, q;

    cin >> n >> m >> q;
    vector<array<int, 3>> s;
    vector<int> ans(q);
    DSU dsu(n + 4);


    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        dsu.unite(u, v, i);
    }

    vector<array<int, 3>> queries(q);
    for (auto& x : queries) cin >> x[0] >> x[1];
    for (int i = 0; i < q; i++) queries[i][2] = i;
    sort(all(queries));

    int curr_l = 1;

    set<pair<int,int>> seti;
    for (auto& [l,righ,j] : queries) {
        while (curr_l <= l) {
            for (auto& [r, time] : dsu.mp[curr_l]) {
                while (true) {
                    auto it = seti.lower_bound({r, INF});
                    if (it == seti.begin()) break ;
                    it--;
                    if (time > it->S) break ;
                    seti.erase(*it);
                }
                auto it = seti.lower_bound({r, time});
                if (it == seti.end() || time < it->S) seti.insert({r, time});
            }
            curr_l++;
        }
        ans[j] = seti.lower_bound({righ, -INF})->S;
    }

    for (auto& x : ans) cout << x << " ";
    cout << endl;
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
