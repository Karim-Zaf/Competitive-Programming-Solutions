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

const int N = 3e5 + 30, MOD = 1e9 + 7, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> graph[N], depth(N), a(N), ans(N), tin(N), tout(N);
int n, c0;
int up[N][30], timer;

void dfs(int parent) {
    tin[parent] = ++timer;
    for (int i = 1; i < 28; i++)
        up[parent][i] = up[up[parent][i - 1]][i - 1];

    for (auto child: graph[parent]) {
        if (up[parent][0] == child)continue;
        depth[child] = depth[parent] + 1;
        up[child][0] = parent;
        dfs(child);
    }
    tout[parent] = timer;
}

int Binary_Lifting(int a, int k) {
    for (int i = 28; i >= 0; i--)
        if (k & (1 << i))
            a = up[a][i];
    return a;
}

template<class T>
struct Seg { // comb(ID,b) = b
    const T ID = 1e9;
    ll n;
    vector<T> seg;

    T comb(T a, T b) { return min(a, b); }

    void build(ll _n) {
        n = _n;
        seg.assign(2 * n, ID);
    }

    void pull(ll p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }

    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }

    void print() {
        for (int i = 0; i < n; i++)cout << query(i, i) << " ";
        cout << '\n';
    }
};

void init() {
    timer = 0;
    for (int i = 0; i <= n; i++) {
        graph[i].clear();
        depth[i] = tin[i] = tout[i] = 0;
        for (int j = 0; j < 30; j++) up[i][j] = 0;
    }
}

void Solve() {
    cin >> n >> c0;
    Seg<int> sg;
    sg.build(n + 5);
    init();
    for (int i = 1; i < n; i++) cin >> a[i];

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);
    ans[0] = n;
    sg.upd(tin[c0], depth[c0]);
    for (int i = 1; i < n; i++) {
        int Node = a[i];
        int prv = ans[i - 1];
        ans[i] = ans[i - 1];
        for (int j = 0; j <= min(depth[Node], prv); j++) {
            int lc = Binary_Lifting(Node, j);
            int pot = -2 * depth[lc] + depth[Node];
            pot += sg.query(tin[lc], tout[lc]);
            ans[i] = min(ans[i], pot);
        }

        sg.upd(tin[Node], depth[Node]);
    }

    for (int i = 1; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt", "r", stdin);
    freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}