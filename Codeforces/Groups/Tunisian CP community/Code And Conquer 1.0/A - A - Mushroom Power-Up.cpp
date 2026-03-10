/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#pragma gcc optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define endl '\n'

const int N = 5e5 + 20, mod = 1e9 + 7;

vector<int> pos[N];
vector<pair<int, int>> a[N];

int n, q;
ll ans = 0;

vector<pair<int, ll>> Tree[4 * N];

void build(int ns = 0, int ne = n, int id = 0) {
    if (ns == ne) {
        for (auto x: a[ns]) Tree[id].pb(x);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l), build(md + 1, ne, r);
    Tree[id].resize(Tree[l].size() + Tree[r].size());
    merge(all(Tree[l]), all(Tree[r]), Tree[id].begin());
}


void build2(int ns = 0, int ne = n, int id = 0) {
    int sz = Tree[id].size();
    for (int i = sz - 2; i >= 0; i--) Tree[id][i].S += Tree[id][i + 1].S;

    if (ns == ne) return;
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build2(ns, md, l), build2(md + 1, ne, r);
}

ll query(int qs, int qe, int x, int ns = 0, int ne = n, int id = 0) {
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe) {
        pair<int, ll> p = {x, -1e18};
        int pos = lower_bound(all(Tree[id]), p) - Tree[id].begin();
        if (pos >= Tree[id].size()) return 0;
        return Tree[id][pos].S;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return query(qs, qe, x, ns, md, l) + query(qs, qe, x, md + 1, ne, r);
}


void Solve() {
    cin >> n >> q;
    vector<int> v(n + 1);
    vector<ll> r(n + 2), l(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]].pb(i);
    }
    v.clear();

    for (int i = 1; i < N; i++) {
        int prvl = 1;
        int sz = pos[i].size();
        for (int j = 0; j < sz; j++) {
            l[prvl] += pos[i][j], l[pos[i][j] + 1] -= pos[i][j];
            prvl = pos[i][j] + 1;
        }
        int prvr = n + 1;
        for (int j = sz - 1; j >= 0; j--) {
            r[prvr] -= pos[i][j], r[pos[i][j]] += pos[i][j];
            prvr = pos[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }

    for (int i = 1; i < N; i++) {
        int sz = pos[i].size();
        for (int j = 0; j < sz - 1; j++)
            a[pos[i][j]].pb({pos[i][j + 1], -pos[i][j] + pos[i][j + 1]});

        if (sz) {
            a[0].pb({pos[i][0], pos[i][0]});
            a[pos[i].back()].pb({n + 1, -pos[i].back()});
        }

        pos[i].clear();
    }

    for (int i = 0; i <= n; i++) {
        sort(all(a[i]));
    }

    build();
    build2();


    while (q--) {
        ll x, y;
        cin >> x >> y;
        int pp = (x ^ ans) % n + 1;
        int qq = (y ^ ans) % n + 1;

        int lef = min(pp, qq);
        int righ = max(pp, qq);

        ans = r[righ] - l[lef] + query(0, lef - 1, righ + 1);
        cout << ans << endl;
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