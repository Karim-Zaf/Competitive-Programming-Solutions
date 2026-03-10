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
    int n;
    cin >> n;
    vector<int> v(n + 5);

    vector<int> ans(n + 5);

    for (int i = 1; i <= n; i++) cin >> v[i];

    DSU dsu;
    dsu.init(n + 5);

    set<pair<int,int>> s;
    map<int,int> mp;
    for (int i = 1; i <= n; i++) {

        if (mp[dsu.get(i)]) s.erase({mp[dsu.get(i)], dsu.get(i),});

        auto it = s.end();
        set<pair<int,int>> er;
        while (it != s.begin()) {
            it = prev(it);
            auto [val , indx] = *it;
            if (val <= v[i]) break ;
            er.insert(*it);
        }
        for (auto x : er) {
            s.erase(x);
            dsu.unite(dsu.get(i), x.S);
            mp[dsu.get(i)] = max(mp[dsu.get(i)], x.F);
        }

        mp[dsu.get(i)] = max(v[i], mp[dsu.get(i)]);
        s.insert({mp[dsu.get(i)], dsu.get(i),});

    }

    mp.clear();
    for (int i = 1; i <= n; i++) {
        mp[dsu.get(i)] = max(mp[dsu.get(i)], v[i]);
    }
    for (int i = 1; i <= n; i++) ans[i] = mp[dsu.get(i)];

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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
