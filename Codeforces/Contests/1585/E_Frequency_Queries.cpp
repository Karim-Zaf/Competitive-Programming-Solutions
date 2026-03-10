/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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

typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

const int N = 1e6 + 2, mod = 1e9 + 7, INF = 1e9 + 10;

vector<int> a(N), graph[N], ans(N);
vector<array<int, 3>> queries[N];
indexed_set s;
int mp[N];
int n, q;

void dfs(int curr, int parent = -1) {

    if (mp[a[curr]])s.erase({mp[a[curr]], a[curr]});
    mp[a[curr]]++;
    s.insert({mp[a[curr]], a[curr]});

    for (auto &child: graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
    }

    for (auto &[l, k, i]: queries[curr]) {
        int pos = s.order_of_key({l, -INF}) + k - 1;
        if (pos >= s.size()) {
            ans[i] = -1;
            continue;
        }
        auto it = s.find_by_order(pos);
        ans[i] = it->S;
    }

    s.erase({mp[a[curr]], a[curr]});
    mp[a[curr]]--;
    if (mp[a[curr]])s.insert({mp[a[curr]], a[curr]});

}

void init() {
    for (int i = 0; i <= n + 1; i++) {
        graph[i].clear();
        queries[i].clear();
        mp[i] = 0;
    }
}

void Solve() {
    cin >> n >> q;
    init();

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2, u; i <= n; i++) {
        cin >> u;
        graph[i].pb(u);
        graph[u].pb(i);
    }
    for (int i = 1; i <= q; i++) {
        int u, l, k;
        cin >> u >> l >> k;
        queries[u].pb({l, k, i});
    }

    dfs(1);

    for (int i = 1; i <= q; i++) cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}