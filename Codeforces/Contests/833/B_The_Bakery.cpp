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

int dp[60][N];

/*----------------------------------------Lazy--------------------------------------------*/

int Tree[4 * N], a[N];
int lazy[4 * N], n;
int upd[4 * N];

int merge(int a, int b) { return max(a, b); }

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
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe) return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}


void Solve() {
    int k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= k; i++) {
        map<int,int> pos;
        for (int j = 1; j <= n; j++) {
            update(pos[v[j]] + 1, j, 1);
            pos[v[j]] = j;
            dp[i][j] = query(0, j);
        }
        for (int j = 1; j <= n; j++) {
            update(j, j, -query(j, j) + dp[i][j - 1]);
        }
    }
    cout << dp[k][n] << endl;
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
