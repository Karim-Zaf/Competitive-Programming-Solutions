/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

struct DSU{
    vector<int> sz, parent, mn;

    void init(int n){
        for (int i = 0; i < n; i++){
            parent.pb(i);
            sz.pb(1);
            mn.pb(INF);
        }
    }

    int get(int a){ return (parent[a] == a ? a : parent[a] = get(parent[a])); }

    bool unite(int a, int b){
        if ((a = get(a)) == (b = get(b))) return false;
        if (sz[a] > sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        mn[a] = min(mn[a], mn[b]);
        mn[b] = min(mn[a], mn[b]);

        return true;
    }

    bool same_set(int a, int b){ return get(a) == get(b); }
    int size(int a){ return sz[get(a)]; }
    int mini(int a){ return mn[get(a)]; }
};

void Solve(){
    int n, m, ans = INF;
    cin >> n >> m;

    vector<array<int, 3>> v;
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        v.pb({w, x, y});
    }
    DSU dsu;
    dsu.init(n + 1);
    sort(all(v));

    for (auto [w, x,y] : v){
        int curr_mn = min(dsu.mini(x), dsu.mini(y));
        curr_mn = min(curr_mn, w);
        dsu.mn[dsu.get(x)] = curr_mn;
        dsu.mn[dsu.get(y)] = curr_mn;

        dsu.unite(x, y);
        if (dsu.same_set(1, n)){ ans = min(ans, dsu.mini(1) + w); }
    }

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
