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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/
void Solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1), ans(n + 3);

    for (int i = 1; i <= n; i++) cin >> v[i];


    indexed_set s;
    vector<vector<int>> queries(n + 1), mp(n + 1);
    vector<int> indx(n + 1);
    for (int i = 1; i <= n; i++) queries[1].pb(i);

    for (int i = 1; i <= n; i++) mp[v[i]].pb(i);

    for (int i = 1; i <= n; i++) {
        if (!mp[i].empty()) {
            s.insert(mp[i][0]);
            indx[i]++;
        }
    }
    s.insert(n + 1);


    for (int i = 1; i <= n; i++) {
        for (auto length : queries[i]) {
            ans[length]++;
            if (length + 1 >= s.size()) continue;
            int nxt = *s.find_by_order(length);
            queries[nxt].pb(length);
        }

        s.erase(i);
        if (indx[v[i]] < mp[v[i]].size()) {
            s.insert(mp[v[i]][indx[v[i]]]);
            indx[v[i]]++;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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
