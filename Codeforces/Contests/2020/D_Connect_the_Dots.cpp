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

int MX = 10;

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

    vector<array<int, 3>> queries(m);
    for (auto& x : queries) cin >> x[0] >> x[1] >> x[2];

    set<int> t[MX + 5][MX + 5];

    for (int i = 1; i <= MX; i++) {
        for (int j = 1; j <= n; j++) {
            t[i][j % i].insert(j);
        }
    }
    set<int> s;
    DSU dsu;
    dsu.init(n + 4);


    for (auto [a , d , k] : queries) {

        set<int> &curr = t[d][a % d], er;
        auto it = curr.lower_bound(a);
        if (it == curr.end()) continue ;

        int rass = a, lst = -1;

        while (it != curr.end() && (*it) <= a + d * k) {
            dsu.unite(rass, *it);
            er.insert(*it);
            lst = *it;
            it++;
        }
        for (auto x : er) curr.erase(x);
        curr.insert(lst);
        curr.insert(rass);
    }


    for (int i = 1; i <= n; i++) s.insert(dsu.get(i));

    cout << s.size() << endl;
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
