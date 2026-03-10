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


vector<int> graph[N], depth(N), p(N);
int up[N][30];

void dfs_init(int parent) {
    for (int i = 1; i < 28; i++) up[parent][i] = up[up[parent][i - 1]][i - 1];

    for (auto child : graph[parent]) {
        if (up[parent][0] == child) continue;
        depth[child] = depth[parent] + 1;
        up[child][0] = parent;
        dfs_init(child);
    }
}

int Binary_Lifting(int a, int k) {
    for (int i = 28; i >= 0; i--) if (k & (1 << i)) a = up[a][i];
    return a;
}

int Lca(int a, int b) {
    if (depth[b] > depth[a]) swap(a, b);

    int k = depth[a] - depth[b];
    a = Binary_Lifting(a, k);
    if (a == b) return a;

    for (int i = 28; i >= 0; i--) {
        if (up[a][i] == up[b][i]) continue;
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}

void Solve() {
    int n, w;
    cin >> n >> w;
    vector<int> cnt(n + 3), sum(n + 4);
    vector<pair<int,int>> vp(n - 1), paths[n + 4];

    map<pair<int,int>, vector<int>> mp;

    for (int i = 1; i <= n; i++) graph[i].clear();

    for (int u = 2; u <= n; u++) {
        cin >> p[u];
        int v = p[u];
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for (auto& x : vp) cin >> x.F >> x.S;

    dfs_init(1);

    for (int i = 1; i <= n; i++) {
        int v = i;
        int u = i - 1;
        if (v == 1) u = 1, v = n;

        int lc = Lca(u, v);

        int curr = u;
        while (curr != lc) {
            int fouk = Binary_Lifting(curr, 1);
            int curr_u = curr;
            int curr_v = fouk;
            if (curr_u > curr_v) swap(curr_u, curr_v);
            paths[i].pb({curr_u, curr_v});
            mp[{curr_u, curr_v}].pb(i);
            curr = fouk;
            cnt[i]++;
        }

        curr = v;

        while (curr != lc) {
            int fouk = Binary_Lifting(curr, 1);
            int curr_u = curr;
            int curr_v = fouk;
            if (curr_u > curr_v) swap(curr_u, curr_v);
            paths[i].pb({curr_u, curr_v});
            mp[{curr_u, curr_v}].pb(i);

            curr = fouk;
            cnt[i]++;
        }
    }


    int nb = n, sum_edges = 0, ans = 0, cayes = 0;
    for (auto [x, y] : vp) {

        int u = x;
        int v = p[u];
        if (u > v) swap(u, v);

        w -= y;
        for (auto Node : mp[{u, v}]) {
            cnt[Node]--;
            sum[Node] += y;

            if (cnt[Node] == 0) {
                cayes += sum[Node];
                ans -= sum[Node] - y;
                nb--;
            } else {

                ans += y;
            }
        }
        cout << nb * w + ans + cayes << " ";
    }
    cout << endl;
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
