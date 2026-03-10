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

int n, m;
vector<int> graph[N], ans(N, -INF), quer[N], a(N);
vector<pair<int, int>> add[N];

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  a+b; }
    void build(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }return comb(ra,rb);
    }
};

Seg<int> sg;

void dfs(int curr = 1, int parent = -1, int indx = 1) {
    for (auto [timer, val]: add[curr])
        sg.upd(timer, val * indx);
    for (auto timer: quer[curr])
        ans[timer] = a[curr] + indx * sg.query(0, timer);

    for (auto child: graph[curr]) {
        if (parent == child)continue;
        dfs(child, curr, indx * -1);
    }
    for (auto [timer, val]: add[curr]) sg.upd(timer, 0);
}

void Solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    sg.build(m + 5);

    for (int timer = 1; timer <= m; timer++) {
        int x, u;
        cin >> x >> u;
        if (x == 1) {
            int val;
            cin >> val;
            add[u].pb({timer, val});
        } else {
            quer[u].pb(timer);
        }
    }
    dfs();

    for (int i = 1; i <= m; i++)
        if (ans[i] != -INF)
            cout << ans[i] << endl;

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