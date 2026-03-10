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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

ll po[22], SPT[N][22], a[N], lg[N], n;

ll merge(ll a, ll b){ return min(a, b); }

void Build_Sparse_Table(){
    po[0] = 1;
    for (int i = 1; i < 22; i++) po[i] = po[i - 1] * 2;
    for (int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; i++) SPT[i][0] = a[i];
    for (int i = 1; po[i] <= n; i++)
        for (int j = 1; j + po[i] <= n + 1; j++)
            SPT[j][i] = merge(SPT[j][i - 1], SPT[j + po[i - 1]][i - 1]);
}

ll query(int l,int r){
    int len = r - l + 1;
    int logg = lg[len];
    return merge(SPT[l][logg], SPT[r - po[logg] + 1][logg]);
}

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
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    Build_Sparse_Table();
    DSU dsu;
    dsu.init(n + 1);

    vector<pair<int,int>> vp(n);
    for (int i = 0; i < n; i++)vp[i] = {a[i + 1], i + 1};
    sort(all(vp));

    for (auto [val,i] : vp){
        int sz_kbal = 0;
        int sz_baad = 0;
        if (i > 1 && a[i - 1] < a[i]) sz_kbal = dsu.size(i - 1);
        if (i < n && a[i + 1] < a[i]) sz_baad = dsu.size(i + 1);

        ans += sz_kbal;

        int lef = i - sz_kbal;
        int righ = i + sz_baad;

        if (sz_kbal < sz_baad){
            for (int j = i - 1; j >= lef; j--){
                int l = i + 1, r = righ, res = i;
                while (l <= r){
                    int md = l + (r - l) / 2;

                    if (query(i, md) > query(j, i)){
                        l = md + 1;
                        res = md;
                    }
                    else{ r = md - 1; }
                }
                ans += res - i;
            }
        }
        else{
            for (int j = i + 1; j <= righ; j++){
                int l = lef, r = i - 1, res = lef - 1;
                while (l <= r){
                    int md = l + (r - l) / 2;
                    if (query(md, i) < query(i, j)){
                        l = md + 1;
                        res = md;
                    }
                    else{ r = md - 1; }
                }
                ans += res - lef + 1;
            }
        }

        if (i < n && a[i] > a[i + 1]) dsu.unite(i, i + 1);
        if (i > 1 && a[i] > a[i - 1]) dsu.unite(i, i - 1);
    }

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
