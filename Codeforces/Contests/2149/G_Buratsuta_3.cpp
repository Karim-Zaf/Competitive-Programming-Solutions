/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
typedef long long ll;
#pragma gcc optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define endl '\n'

const int N = 2e5 + 500, mod = 1e9 + 7, INF = 1e18 + 10;

int n;
vector<int> v;
vector<pair<int, int>> Tree[4 * N];
int mp[N];

void build(int ns = 1, int ne = n, int id = 0){
    if (ns == ne) return void(Tree[id] = {{1, v[ns]}});

    int md = ns + (ne - ns) / 2, l = 2 * id + 1, r = 2 * id + 2;
    build(ns, md, l);
    build(md + 1, ne, r);

    Tree[id].clear();
    set<int> values;
    for (auto [cnt, val] : Tree[l]){
        values.insert(val);
        mp[val] += cnt;
    }
    for (auto [cnt, val] : Tree[r]){
        values.insert(val);
        mp[val] += cnt;
    }

    for (auto val : values) Tree[id].push_back({mp[val], val});
    for (auto val : values) mp[val] = 0;

    sort(rall(Tree[id]));
    while (Tree[id].size() > 4) Tree[id].pop_back();

};

vector<int> values;

void query(int qs, int qe, int ns = 1, int ne = n, int id = 0){
    if (qs > ne || qe < ns)return;
    if (qs <= ns && ne <= qe){
        for (auto x : Tree[id]) values.push_back(x.S);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    query(qs, qe, ns, md, l);
    query(qs, qe, md + 1, ne, r);
}

void Solve(){
    int q;
    cin >> n >> q;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector<int> nw = v;
    sort(all(nw));

    map<int, int> key;
    vector<int> rev_key(n + 2);
    vector<int> mp[n + 3];
    for (int i = n; i >= 1; i--){
        key[nw[i]] = i;
        rev_key[i] = nw[i];
    }
    for (int i = 1; i <= n; i++) v[i] = key[v[i]];

    for (int i = 1; i <= n; i++){ mp[v[i]].pb(i); }

    build();

    while (q--){
        int l, r;
        cin >> l >> r;

        values.clear();
        query(l, r);

        vector<int> ans;
        for (auto x : values){
            int cnt = upper_bound(all(mp[x]), r) - lower_bound(all(mp[x]), l);
            if (cnt > (r - l + 1) / 3)ans.pb(x);
        }

        for (auto& x : ans) x = rev_key[x];
        sort(all(ans));

        if (ans.empty()) cout << -1;
        int prv = INF;
        for (auto x : ans){
            if (x == prv) continue;
            cout << x << " ";
            prv = x;
        }
        cout << endl;
    }
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
