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

const int N = 6e5 + 30, mod = 1e9 + 7, INF = 1e9 + 10;

/*----------------------------------------Lazy--------------------------------------------*/
int n;
int Tree[4 * N];
int lazy[4 * N];
int upd[4 * N];

int merge(int a, int b){ return max(a, b); }

void unlazy(int id){
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id] += lazy[id];
    if (r < 4 * N) lazy[l] += lazy[id], lazy[r] += lazy[id];
    if (r < 4 * N)upd[l] = upd[r] = 1;
    upd[id] = lazy[id] = 0;
}

void update(int qs, int qe, int val, int ns = 0, int ne = n, int id = 0){
    unlazy(id);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe){
        lazy[id] += val, upd[id] = 1;
        unlazy(id);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

int query(int qs, int qe, int ns = 0, int ne = n, int id = 0){
    unlazy(id);
    if (qs > ne || qe < ns) return -1e9;
    if (qs <= ns && ne <= qe)return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}

void prep(){ for (int i = 0; i <= n; i++){ update(i, i, -query(i, i)); } }

void Solve(){
    cin >> n;
    prep();

    vector<int> v(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++){
        update(v[i], v[i], -query(v[i], v[i]));

        update(0, v[i] - 1, 1);
        ans[i] = max(0ll, query(0, n));
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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
