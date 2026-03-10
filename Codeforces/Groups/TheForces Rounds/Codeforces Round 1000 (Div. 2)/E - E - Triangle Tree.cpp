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

template <class T>
struct Seg{ /*CHANGE THE ID YA KARIM !!*/
    const T ID = 0;
    int n;
    vector<T> seg;
    T merge(T a, T b){ return a + b; } // Function
    void build(int _n){ n = _n, seg.assign(2 * n, ID); }
    void pull(int p){ seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }

    void upd(int p, T val){
        seg[p += n] = val;
        for (p /= 2; p; p /= 2)pull(p);
    }

    T query(int l, int r){
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
            if (l & 1)ra = merge(ra, seg[l++]);
            if (r & 1)rb = merge(seg[--r], rb);
        }
        return merge(ra, rb);
    }

    void print(int i = -1){
        while (++i < n)cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " "); /**/
    }
};

vector<int> graph[N], depths[N];
vector<int> sz(N, 1), depth(N), bigchild(N);
vector<int> depthes[N];
int n, ans = 0;

Seg<int> sum, occ;

void dfs(int curr, int parent = 0){
    depth[curr] = depth[parent] + 1;

    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs(child, curr);
        if (bigchild[curr] == -1 || sz[child] > sz[bigchild[curr]]) bigchild[curr] = child;
        sz[curr] += sz[child];
    }
}

void work(int curr, int parent = 0, int keep = 0){
    for (auto child : graph[curr]){
        if (child == parent) continue;
        if (child == bigchild[curr]) continue;
        work(child, curr, 0);
    }
    if (bigchild[curr] != -1){ work(bigchild[curr], curr, 1); }

    if (bigchild[curr] != -1) depths[curr].swap(depths[bigchild[curr]]);
    depths[curr].pb(depth[curr]);

    for (auto& child : graph[curr]){
        if (child == parent || child == bigchild[curr]) continue;
        for (auto& dep : depths[child]){
            int cnt = occ.query(dep + 1, n);
            int add = cnt * (2 * (dep - depth[curr]) - 1);
            ans += add;
        }
        for (auto& dep : depths[child]){
            int cnt = occ.query(0, dep);
            int add = 2 * (sum.query(0, dep) - depth[curr] * cnt) - cnt;
            ans += add;
        }

        for (auto& dep : depths[child]){
            depths[curr].pb(dep);
            occ.upd(dep, occ.query(dep, dep) + 1);
            sum.upd(dep, sum.query(dep, dep) + dep);
        }
    }

    if (!keep){
        for (auto& x : depths[curr]){
            occ.upd(x, 0);
            sum.upd(x, 0);
        }
    }
    else{
        int dep = depth[curr];
        occ.upd(dep, occ.query(dep, dep) + 1);
        sum.upd(dep, sum.query(dep, dep) + dep);
    }
}

void init(){
    for (int i = 0; i <= n + 4; i++){
        graph[i].clear();
        sz[i] = 1;
        depth[i] = 0;
        bigchild[i] = -1;
        depths[i].clear();
    }
    sum.build(n + 6);
    occ.build(n + 6);
    ans = 0;
}

void Solve(){
    cin >> n;

    init();
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;

        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1);
    work(1);

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
