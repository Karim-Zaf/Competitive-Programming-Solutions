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

const int N = 3e5 + 30, mod = 1e9, INF = 1e18 + 10;

vector<array<int, 6>> v;
vector<array<int, 6>> Tree[2][4 * N];
int n, q, timer = 0;

vector<array<int, 6>> merge(vector<array<int, 6>>& a, vector<array<int, 6>>& b) {
    vector<array<int, 6>> ret;

    int na = a.size(), nb = b.size(), ia = 0, ib = 0;

    while (ia < na && ib < nb) {
        if (a[ia][0] < b[ib][0]) ret.pb(a[ia++]);
        else ret.pb(b[ib++]);
    }

    while (ia < na) ret.pb(a[ia++]);
    while (ib < nb) ret.pb(b[ib++]);

    return ret;
}


void build(int ns = 1, int ne = n, int id = 0) {
    if (ns == ne) {
        Tree[0][id].pb(v[ns]);
        swap(v[ns][0], v[ns][1]);
        Tree[1][id].pb(v[ns]);
        swap(v[ns][0], v[ns][1]);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l);
    build(md + 1, ne, r);
    Tree[0][id] = merge(Tree[0][l], Tree[0][r]);
    Tree[1][id] = merge(Tree[1][l], Tree[1][r]);
}


void build2(int ns = 1, int ne = n, int id = 0) {
    if (ns == ne) return;
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build2(ns, md, l);
    build2(md + 1, ne, r);
    for (int indx = 0; indx < 2; indx++) for (int i = 1; i < Tree[indx][id].size(); i++) for (int j = 2; j < 6; j++) Tree[indx][id][i][j] += Tree[indx][id][i - 1][j];
}

int query(int qs, int qe, int x, int ns = 1, int ne = n, int id = 0) {
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe) {

        int ret = 0, a = Tree[1][id].back()[3], b = Tree[1][id].back()[4];

        array<int, 6> p = {x, -INF, 0, 0, 0, 0};

        int pos = lower_bound(all(Tree[0][id]), p) - Tree[0][id].begin() - 1;

        ret += Tree[0][id].back()[2];
        a -= Tree[0][id].back()[3];
        b -= Tree[0][id].back()[4];

        if (pos >= 0) {
            ret -= Tree[0][id][pos][2];
            a += Tree[0][id][pos][3];
            b += Tree[0][id][pos][4];
        }
        pos = lower_bound(all(Tree[1][id]), p) - Tree[1][id].begin() - 1;

        if (pos >= 0) {
            ret += Tree[1][id][pos][5];
            a -= Tree[1][id][pos][3];
            b -= Tree[1][id][pos][4];
        }
        return ret + a * x + b;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return query(qs, qe, x, ns, md, l) + query(qs, qe, x, md + 1, ne, r);
}

void Solve() {
    int m, last = 0;
    cin >> n;

    v.resize(n + 4);
    for (int i = 1; i <= n; i++) for (int j = 0; j < 6; j++) cin >> v[i][j];

    build();
    build2();

    cin >> m;
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        x += last;
        x %= mod;
        last = query(l, r, x);
        cout << last << endl;
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
