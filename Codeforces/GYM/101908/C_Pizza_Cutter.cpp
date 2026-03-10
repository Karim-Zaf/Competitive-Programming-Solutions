/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<pair<int, int>> x, y;
int n, m, h, v;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

int verif(vector<pair<int, int>> &x, vector<pair<int, int>> &y, int oth ) {
    int ans = 1;
    indexed_set s;
    for (auto [x1, x2]: x) {
        pair<int, int> p = {x2, -1};
        ans += s.size() - s.order_of_key(p) + 1;
        s.insert({x2, x1});

    }
    s.clear();
    for (auto [x1, x2]: y) {
        pair<int, int> p = {x2, INF};
        ans += s.size() - s.order_of_key(p) + oth + 1;
        s.insert({x2, x1});
    }
    return ans;
}

void Solve() {
    cin >> n >> m;
    cin >> h >> v;
    x.resize(h);
    y.resize(v);

    for (auto &p: x) cin >> p.F >> p.S;
    for (auto &p: y) cin >> p.F >> p.S;

    sort(all(x));
    sort(all(y));

    cout << min(verif(y,x,v),verif(x, y,h))  << endl;
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