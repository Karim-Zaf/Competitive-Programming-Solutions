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
    vector<int> sz, parent;

    void init(int n){
        for (int i = 0; i < n; i++){
            parent.pb(i);
            sz.pb(1);
        }
    }

    int get(int a){ return (parent[a] == a ? a : parent[a] = get(parent[a])); }

    bool unite(int a, int b){
        if ((a = get(a)) == (b = get(b))) return false;
        if (sz[a] > sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same_set(int a, int b){ return get(a) == get(b); }
    int size(int a){ return sz[get(a)]; }
};

void Solve(){
    int n;
    cin >> n;
    vector<int> p(n + 1), indx(n);

    for (int i = 1; i <= n; i++) cin >> p[i];

    for (auto& x : indx) cin >> x;
    DSU dsu;
    dsu.init(n + 1);
    for (int i = 1; i <= n; i++) dsu.unite(i, p[i]);
    set<int> s;
    int ans = 0;
    for (auto x : indx){
        int curr = dsu.get(x);
        if (s.find(curr) == s.end())ans += dsu.size(curr);
        s.insert(curr);
        cout << ans << " ";
    }
    cout << endl;
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
