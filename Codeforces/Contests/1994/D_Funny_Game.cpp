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
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];


    DSU dsu;
    dsu.init(n + 5);
    vector<pair<int,int>> ans;

    for (int i = n - 1; i >= 1; i--) {
        vector<set<pair<int,int>>> mp(i + 4);
        int ok = 0;

        for (int j = 1; j <= n; j++) {
            mp[a[j] % i].insert({dsu.get(j), j});
        }

        for (int md = 0; md < i; md++) {

            if (mp[md].empty()) continue ;
            auto it1 = mp[md].begin();
            auto it2 = prev(mp[md].end());

            if (it1->F == it2->F) continue ;

            dsu.unite(it1->S, it2->S);
            ans.pb({it1->S, it2->S});
            ok = 1;
            break ;
        }
        if (!ok) return void(cout << "NO\n");
    }

    reverse(all(ans));
    cout << "YES\n";
    for (auto x : ans) cout << x.F << " " << x.S << endl;
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
