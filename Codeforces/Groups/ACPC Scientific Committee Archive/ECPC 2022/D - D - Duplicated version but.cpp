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

template <class T> struct Seg { /*CHANGE THE ID YA KARIM !!*/
    const T ID = -INF;
    int n;
    vector<T> seg;
    T merge(T a, T b) { return max(a, b); }
    void init(int _n) { n = _n, seg.assign(2 * n, ID); }
    void pull(int p) { seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }
    void print(int i = -1) { while (++i < n) cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " "); }

    void upd(int p, T val) {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = merge(ra, seg[l++]);
            if (r & 1) rb = merge(seg[--r], rb);
        }
        return merge(ra, rb);
    }
};


void Solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> graph[n + 1], depth(n + 1), cnt(n + 1, -INF), b(n + 1), dp(n + 2);
    Seg<int> sg[2];

    sg[0].init(n + 4);
    sg[1].init(n + 4);

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for (int i = 1; i <= n; i++) cin >> b[i];

    function<void(int,int)> dfs = [&](int curr, int parent) {
        depth[curr] = depth[parent] + 1;

        if (cnt[depth[curr]] == -INF) cnt[depth[curr]] = b[curr];
        else if (cnt[depth[curr]] <= 0) cnt[depth[curr]] = max(cnt[depth[curr]], b[curr]);
        else cnt[depth[curr]] = max(cnt[depth[curr]], 0ll) + max(0ll, b[curr]);

        for (auto child : graph[curr]) {
            if (child == parent) continue;
            dfs(child, curr);
        }
    };
    dfs(1, 0);
    for (int dep = n; dep >= 1; dep--) {
        int lef = min(n + 1, dep + l), righ = min(n + 1, dep + r);

        dp[dep] = cnt[dep] + max(0ll, sg[dep % 2].query(lef, righ));

        sg[dep % 2].upd(dep, dp[dep]);
    }
    cout << max({0ll, sg[0].query(0, n + 1), sg[1].query(0, n + 1)}) << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
