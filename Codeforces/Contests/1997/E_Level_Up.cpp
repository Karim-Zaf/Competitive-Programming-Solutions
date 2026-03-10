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
#define int ll
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

vector<pair<int,int>> t[N];

vector<int> pos[N];

void Solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]].pb(i);
    }


    indexed_set s;

    for (int x = 1; x <= n; x++) t[x].pb({1, 1});

    for (int i = 1; i <= n; i++) s.insert(i);
    for (int val = 1; val <= n; val++) {

        for (auto& p : pos[val - 1]) s.erase(p);

        for (int x = 1; x <= n; x++) {
            auto [valll, pos] = t[x].back();

            auto it = s.lower_bound(pos);
            if (it == s.end()) break ;

            pos = *it;

            int position = s.order_of_key(pos);

            if (position + x >= s.size()) break ;

            int nxt = *s.find_by_order(position + x);

            t[x].pb({val + 1, nxt});
        }
    }

    while (q--) {
        int i, x;
        cin >> i >> x;

        pair<int,int> p = {v[i], INF};
        int pos = upper_bound(all(t[x]), p) - t[x].begin();
        if (pos != t[x].size() && t[x][pos].S <= i) cout << "NO\n";
        else cout << "YES\n";
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
