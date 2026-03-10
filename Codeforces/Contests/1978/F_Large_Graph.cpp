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
#define endl '\n'

const int N = 1e6 + 5;

vector<int> mp[N], divi[N];
vector<bool> vis(N);

void sieve() {

    for (int i = 2; i < N; i++) {
        if (vis[i]) continue ;
        for (int j = i; j < N; j += i) {
            divi[j].pb(i);
            vis[j] = true;
        }
    }
    vis.assign(N, false);
}

struct DSU {
    vector<int> sz, parent;

    void init(int n) {
        for (int i = 0; i < n; i++) {
            parent.pb(i);
            sz.pb(1);
        }
    }

    int get(int a) { return (parent[a] == a ? a : parent[a] = get(parent[a])); }

    bool unite(int a, int b) {
        if ((a = get(a)) == (b = get(b))) return false;
        if (sz[a] > sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int a) { return sz[get(a)]; }
};

void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n + 3), values;
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 2; i <= n; i++)
        for (auto d : divi[v[i]]) {
            mp[d].pb(i);
            if (!vis[d]) values.pb(d);
            vis[d] = true;
        }

    DSU dsu;
    dsu.init(2 * n + 2);

    for (auto& x : values) {
        vector<int>& curr = mp[x];
        if (curr.size() <= 1) continue;

        int sz = curr.size(), dist;

        for (int i = 1; i < sz; i++) {
            dist = curr[i] - curr[i - 1];
            if (dist <= k) {
                dsu.unite(2 * curr[i], 2 * curr[i - 1]);
                dsu.unite(2 * curr[i] + 1, 2 * curr[i - 1] + 1);
            }
            dist = (n - curr[i]) + curr[i - 1];

            if (dist <= k) dsu.unite(2 * curr[i], 2 * curr[i - 1] + 1);
        }

        dist = (n - curr.back()) + curr.front();
        if (dist <= k) dsu.unite(2 * curr.back(), 2 * curr.front() + 1);

    }

    for (int pos = 2; pos <= n; pos++) {
        if (__gcd(v[pos], v[1]) == 1) continue;

        /* Left */
        int dist = pos - 1;
        if (dist <= k) dsu.unite(2, 2 * pos + 1);

        /* Right */
        dist = n - pos + 1;
        if (dist <= k) dsu.unite(2, 2 * pos);
    }

    ll ans = 0;
    dsu.unite(2, 3);

    set<int> s;
    for (int i = 1; i <= n; i++) {
        ans += (n - 1) * (v[i] == 1);
        if (k >= n || v[i] == 1) dsu.unite(2 * i, 2 * i + 1);
        s.insert(dsu.get(2 * i));
        s.insert(dsu.get(2 * i + 1));
    }

    ans += s.size();
    cout << ans << endl;

    for (auto d : values) {
        vis[d] = false;
        mp[d].clear();
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    sieve();
    while (Test_case--) Solve();
}
