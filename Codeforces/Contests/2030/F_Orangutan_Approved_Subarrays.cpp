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

const int N = 4e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> Tree[4 * N], prv;
int n, q, timer = 0;

void build(int ns = 1, int ne = n, int id = 0){
    if (ns == ne) return void(Tree[id] = {prv[ns]});

    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l);
    build(md + 1, ne, r);
    Tree[id].resize(Tree[l].size() + Tree[r].size());
    merge(all(Tree[l]), all(Tree[r]), Tree[id].begin());
}

int query(int qs, int qe, int x, int ns = 1, int ne = n, int id = 0){
    if (qs > ne || qe < ns) return -INF;
    if (qs <= ns && ne <= qe){
        int pos = lower_bound(all(Tree[id]), x) - Tree[id].begin();
        if (pos == 0) return -INF;
        return Tree[id][pos - 1];
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return max(query(qs, qe, x, ns, md, l), query(qs, qe, x, md + 1, ne, r));
}

void Solve(){
    cin >> n >> q;

    vector<pair<int,int>> queries[n + 3];
    vector<int> v(n + 1), ans(q);
    map<int,int> lst;
    prv.resize(n + 3);
    fill(all(prv), 0);

    for (int i = 1; i <= n; i++)cin >> v[i];

    for (int i = 1; i <= n; i++){
        prv[i] = lst[v[i]];
        lst[v[i]] = i;
    }

    build();

    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        queries[r].pb({l, i});
    }

    int apartir = -INF;
    for (int r = 1; r <= n; r++){
        int curr = query(prv[r] + 1, r - 1, prv[r]);
        apartir = max(apartir, curr);
        for (auto [l,i] : queries[r]){ ans[i] = (l > apartir); }
    }

    for (auto x : ans)cout << (x ? "YES" : "NO") << endl;
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
