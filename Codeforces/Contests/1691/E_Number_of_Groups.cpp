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
    DSU dsu;
    map<int, vector<array<int, 4>>> l, r;
    set<int> s;


    int n;
    cin >> n;
    dsu.init(n + 2);

    for (int i = 1, lef, righ, c; i <= n; i++) {
        cin >> c >> lef >> righ;
        l[lef].pb({lef, righ, c, i});
        r[righ].pb({lef, righ, c, i});
        s.insert(lef);
        s.insert(righ);
    }


    map<int,int> mp[2];
    set<int> seti[2];

    set<array<int, 4>> track[2];

    for (auto& p : s) {
        for (auto& [lef,righ , c , i] : l[p]) {
            int curr = dsu.get(i);
            mp[c][curr]++;
            seti[c].insert(curr);
            track[c].insert({lef, righ, c, i});
        }

        if (!seti[0].empty() && !seti[1].empty()) {
            int rass = *seti[0].begin();

            for (int i = 0; i < 2; i++) mp[i].clear();
            for (int i = 0; i < 2; i++) for (auto& x : seti[i]) dsu.unite(x, rass);
            for (int i = 0; i < 2; i++) mp[i][dsu.get(rass)] = track[i].size();
            for (int i = 0; i < 2; i++) seti[i].clear();
            for (int i = 0; i < 2; i++) seti[i].insert(dsu.get(rass));
        }
        // kar(p);
        // karr(track);
        // kar(seti[0], seti[1])

        for (auto& [lef,righ, c, i] : r[p]) {
            auto& ss = seti[c];
            int curr = dsu.get(i);
            if (mp[c][curr] == 1) ss.erase(curr);
            mp[c][curr]--;
            track[c].erase({lef, righ, c, i});
        }
    }


    s.clear();
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
