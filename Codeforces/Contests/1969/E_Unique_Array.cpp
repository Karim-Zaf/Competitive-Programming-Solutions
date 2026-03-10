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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

/*----------------------------------------Lazy--------------------------------------------*/

int Tree[4 * N], a[N];
int lazy[4 * N], n;
int upd[4 * N];

int merge(int a, int b) { return min(a, b); }

void unlazy(int id) {
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id] += lazy[id];
    lazy[l] += lazy[id], lazy[r] += lazy[id];
    upd[l] = upd[r] = 1, upd[id] = lazy[id] = 0;
}

void update(int qs, int qe, int val, int ns = 1, int ne = n, int id = 0) {
    unlazy(id);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe) {
        lazy[id] += val, upd[id] = 1;
        unlazy(id);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

int query(int qs, int qe, int ns = 1, int ne = n, int id = 0) {
    unlazy(id);
    if (qs > ne || qe < ns) return INF;
    if (qs <= ns && ne <= qe) return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}

void print() {
    for (int i = 1; i <= n; i++) cout << query(i, i) << " ";
    cout << endl;
}

void Solve() {
    int ans = 0;
    cin >> n;
    vector<int> v(n + 2);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) update(i, i, -query(i, i));

    vector<set<int>> mp(n + 2);
    vector<int> indx(n + 1, 1);
    for (int i = 1; i <= n; i++) mp[i].insert(0);
    for (int i = 1; i <= n; i++) mp[v[i]].insert(i);
    for (int i = 1; i <= n; i++) mp[i].insert(n + 1);

    for (int i = 1; i <= n; i++) {
        int prv_prv = -1;
        auto it = mp[v[i]].lower_bound(i);

        it = prev(it);
        int prv = *it;
        if (it != mp[v[i]].begin()) prv_prv = *prev(it);
        indx[v[i]]++;

        if (prv_prv != -1) update(prv_prv + 1, prv, -1);
        update(prv + 1, i, 1);

        int q = query(1, i);
        if (q == 0) {
            update(prv + 1, i, -1);
            update(1, i, 1);
            if (prv_prv != -1) update(prv_prv + 1, prv, 1);
            mp[v[i]].erase(i);
            ans++;
        }
    }

    cout << ans << endl;
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
