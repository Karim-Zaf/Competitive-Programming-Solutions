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

const int N = 2e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

using ul = uint64_t;
using db = long double;

ul modMul(ul a, ul b, const ul mod) {
    ll ret = a * b - mod * (ul) ((db) a * b / mod);
    return ret + ((ret < 0) - (ret >= (ll) mod)) * mod;
}

ul modPow(ul a, ul b, const ul mod) {
    if (b == 0) return 1;
    ul res = modPow(a, b / 2, mod);
    res = modMul(res, res, mod);
    return b & 1 ? modMul(res, a, mod) : res;
}

bool prime(ul n) { // not ll!
    if (n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
    ul A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n - 1), d = n >> s;
    for (auto a: A) {   // ^ count trailing zeroes
        ul p = modPow(a, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--) p = modMul(p, p, n);
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}

int timer = 0, tin[N], tout[N];
vector<int> graph[N];

int Tree[4 * N], a[N], value[N];
int lazy[4 * N], n, q;
int upd[4 * N];

int merge(int a, int b) { return a + b; }

void unlazy(int id, int ns, int ne) {
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id] = lazy[id] * (ne - ns + 1);
    lazy[l] = lazy[id], lazy[r] = lazy[id];
    upd[l] = upd[r] = 1, upd[id] = lazy[id] = 0;
}

void build(int ns = 1, int ne = n, int id = 0) {
    if (ns == ne) {
        Tree[id] = a[ns];
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l);
    build(md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

void update(int qs, int qe, int val, int ns = 1, int ne = n, int id = 0) {
    unlazy(id, ns, ne);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe) {
        lazy[id] = val, upd[id] = 1;
        unlazy(id, ns, ne);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

int query(int qs, int qe, int ns = 1, int ne = n, int id = 0) {
    unlazy(id, ns, ne);
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe)return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}


void Euler_Tour(int curr, int parent) {
    tin[curr] = ++timer;
    a[timer] = value[curr];
    for (auto child: graph[curr])
        if (child != parent)
            Euler_Tour(child, curr);
    tout[curr] = timer;
}


void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> value[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    Euler_Tour(1, -1);
    build();

    cin >> q;
    while (q--) {
        int x, v;
        cin >> x;
        if (x == 1) {
            cin >> v >> x;
            update(tin[v], tout[v], x);
        } else {
            cin >> v;
            int sum = query(tin[v], tout[v]);
            cout << (sum % 2 == 0 && sum != 2 || prime(sum - 2) ? "YES" : "NO") << endl;
        }
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
