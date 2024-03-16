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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

map<int, int> mp;
vector<array<int, 4>> v;
vector<int> Tree[4 * N];
int n, q, timer = 0;

void build(int ns = 0, int ne = n - 1, int id = 0) {
    if (ns == ne) {
        Tree[id].pb(v[ns][1]);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l);
    build(md + 1, ne, r);
    Tree[id].pb(INF);
    Tree[id].resize(Tree[l].size() + Tree[r].size());
    merge(all(Tree[l]), all(Tree[r]), Tree[id].begin());
}

int query(int qs, int qe, int x, int ns = 0, int ne = n - 1, int id = 0) {
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe)return upper_bound(all(Tree[id]), x) - Tree[id].begin();
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return query(qs, qe, x, ns, md, l) + query(qs, qe, x, md + 1, ne, r);
}

void Solve() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][2] >> v[i][3] >> v[i][0] >> v[i][1];
        mp[v[i][0]] = 1;
        mp[v[i][1]] = 1;
    }
    sort(all(v));

    cin >> q;
    vector<array<int, 2>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
        mp[queries[i][0]] = 1;
        mp[queries[i][1]] = 1;
    }
    for (auto x: mp)mp[x.F] = ++timer;
    for (int i = 0; i < n; i++) v[i][0] = mp[v[i][0]], v[i][1] = mp[v[i][1]];

    build();
    for (auto [x, y]: queries) {
        array<int, 4> a = {mp[x], INF, INF, INF};
        int p = upper_bound(all(v), a) - v.begin() - 1;
        cout << query(0, p, mp[y]) << endl;
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
