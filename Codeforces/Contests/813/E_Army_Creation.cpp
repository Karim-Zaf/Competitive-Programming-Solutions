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
const int N = 1e5 + 2;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

vector<int> vect(N);
indexed_set Tree[4 * N];
int n, q, timer = 0, m;
ll ans = 0;

void build(int ns = 1, int ne = n, int id = 0) {

    if (ns == ne) {
        if (vect[ns] == 0) return;
        return void(Tree[id].insert(vect[ns]));
    }

    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l), build(md + 1, ne, r);
    for (auto& x : Tree[l]) Tree[id].insert(x);
    for (auto& x : Tree[r]) Tree[id].insert(x);

}

int query(int qs, int qe, int x, int ns = 1, int ne = n, int id = 0) {
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe) return Tree[id].order_of_key(x + 1);
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return query(qs, qe, x, ns, md, l) + query(qs, qe, x, md + 1, ne, r);
}

void Solve() {
    int k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, vector<int>> mp;
    for (auto& x : v) cin >> x;
    for (int i = 0; i < n; i++) mp[v[i]].pb(i);

    for (auto [x, indexes] : mp) {
        int sz = indexes.size();
        for (int i = 0; i < sz; i++) {
            int nxt = i + k;
            if (nxt >= sz) continue ;
            vect[indexes[i] + 1] = indexes[nxt] + 1;
        }
    }
    build();
    int q, lst = 0;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = (l + lst) % n + 1;
        r = (r + lst) % n + 1;

        if (l > r) swap(l, r);
        lst = (r - l + 1) - query(l, r, r);
        cout << lst << endl;
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
