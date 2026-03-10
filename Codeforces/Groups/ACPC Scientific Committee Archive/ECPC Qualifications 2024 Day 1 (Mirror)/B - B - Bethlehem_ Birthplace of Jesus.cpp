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


int binpow(int a, int k, int res = 1,int Mod = mod) {
    while (k) {
        if (k % 2) res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a,int Mod = mod) { return binpow(a, Mod - 2); }
int mult(int a, int b,int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b,int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }
int divide(int a, int b,int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}


/*----------------------------------------Lazy--------------------------------------------*/

int Tree[4 * N][4];
int lazy[4 * N], n;
int upd[4 * N];

int merge(int a, int b) { return add(a, b); }

void unlazy(int id, int ns, int ne) {
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;

    // kar(ns, ne, Tree[id][3], lazy[id]);
    Tree[id][3] = add(Tree[id][3], 3 * lazy[id] % mod * Tree[id][2] % mod);
    Tree[id][3] = add(Tree[id][3], 3 * lazy[id] % mod * lazy[id] % mod * Tree[id][1] % mod);
    Tree[id][3] = add(Tree[id][3], (ne - ns + 1) * lazy[id] % mod * lazy[id] % mod * lazy[id] % mod);

    Tree[id][2] = add(Tree[id][2], 2 * lazy[id] % mod * Tree[id][1] % mod);
    Tree[id][2] = add(Tree[id][2], (ne - ns + 1) * lazy[id] % mod * lazy[id] % mod);

    Tree[id][1] = add(Tree[id][1], (ne - ns + 1) * lazy[id] % mod);

    lazy[l] = add(lazy[l], lazy[id]), lazy[r] = add(lazy[r], lazy[id]);
    upd[l] = upd[r] = 1, upd[id] = lazy[id] = 0;
}

void update(int qs, int qe, int val, int ns = 1, int ne = n, int id = 0) {
    unlazy(id, ns, ne);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe) {
        lazy[id] = add(lazy[id], val), upd[id] = 1;
        unlazy(id, ns, ne);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);
    for (int i = 0; i <= 3; i++) Tree[id][i] = add(Tree[l][i], Tree[r][i]);
}

int query(int qs, int qe, int ns = 1, int ne = n, int id = 0) {

    unlazy(id, ns, ne);
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe) return Tree[id][3];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}

void Solve() {
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        update(i, i, x);
    }
    int q;
    cin >> q;
    while (q--) {
        int x, l, r;
        cin >> x;
        if (x == 1) {
            cin >> l >> r >> x;
            update(l, r, x);
        } else {
            cin >> l >> r;
            cout << query(l, r) << endl;
        }
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
