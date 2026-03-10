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

/*----------------------------------------Lazy--------------------------------------------*/

int Tree[4 * N];
int lazy[4 * N], n;
int upd[4 * N];

int merge(int a, int b){ return a + b; }

void unlazy(int id,int ns,int ne){
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id] += (ne - ns + 1) * lazy[id];
    lazy[l] += lazy[id], lazy[r] += lazy[id];
    upd[l] = upd[r] = 1, upd[id] = lazy[id] = 0;
}

void build(int ns = 0, int ne = n, int id = 0){
    if (ns == ne){
        Tree[id] = lazy[id] = upd[id] = 0;
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l);
    build(md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

void update(int qs, int qe, int val, int ns = 1, int ne = n, int id = 0){
    unlazy(id, ns, ne);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe){
        lazy[id] += val, upd[id] = 1;
        unlazy(id, ns, ne);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

int query(int qs, int qe, int ns = 1, int ne = n, int id = 0){
    unlazy(id, ns, ne);
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe)return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}

void Solve(){
    int m;
    cin >> n >> m;
    vector<int> v(m);

    build();
    for (int i= 0 ; i<=n ;i++)update(i,i, -query(i,i));
    for (auto& x : v) cin >> x;
    sort(all(v));

    int ans = 0;
    for (auto x : v){
        int lef = max(0ll, n - x);

        ans += query(max(1ll, lef), n);
        update(1, min(n-1, x), 1);
    }
    ans *= 2;
    cout << ans << endl;
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
