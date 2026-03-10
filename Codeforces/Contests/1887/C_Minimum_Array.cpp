/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll ll
#define endl '\n'
#pragma gcc optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ll N = 5e5 + 2, mod = 1e9 + 7, INF = 1e18;

/*----------------------------------------Lazy--------------------------------------------*/

ll Tree[4 * N][3];
ll lazy[4 * N], q;
int upd[4 * N];

array<ll,3> merge(int id , int l, int r){
    Tree[id][0] = min(Tree[l][0], Tree[r][0]);
    Tree[id][1] = max(Tree[l][1], Tree[r][1]);
    if (Tree[l][1]>= Tree[r][1])Tree[id][2] = Tree[l][2];
    else Tree[id][2] = Tree[r][2];

    return {Tree[id][0], Tree[id][1], Tree[id][2]};
}
array<ll, 3> merge2(array<ll, 3> a, array<ll, 3> b){
    array<ll, 3> ret;

    ret[0] = min(a[0], b[0]);
    ret[1] = max(a[1], b[1]);
    if (a[1] >= b[1]) ret[2] = a[2];
    else ret[2] = b[2];
    return ret;
}

void unlazy(ll id){
    if (upd[id] == 0) return;
    ll l = 2 * id + 1, r = 2 * id + 2;
    Tree[id][0] += lazy[id];
    Tree[id][1] += lazy[id];

    Tree[id][0] = min(Tree[id][0], INF);
    Tree[id][1] = max(Tree[id][1], -INF);

    if ( r >= 4*N){
        upd[id] = lazy[id] = 0;
        return;
    }
    lazy[l] += lazy[id], lazy[r] += lazy[id];
    upd[l] = upd[r] = 1;
    upd[id] = lazy[id] = 0;


}

void build(int ns = 0, int ne = q, int id = 0){
    lazy[id] = upd[id] = 0;

    Tree[id][0] = Tree[id][1] = 0;
    Tree[id][2] = ns;
    
    if (ns == ne)return;
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    build(ns, md, l);
    build(md + 1, ne, r);
    // Tree[id] = merge(Tree[l], Tree[r]);
}

void update(int qs, int qe, ll val, int ns = 0, int ne = q, int id = 0){
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
 merge(id,l,r);
}

void remove(int pos, int ns = 0, int ne = q, int id = 0){
    unlazy(id);
    if (pos > ne || pos < ns) return;
    if (ns == ne){
        lazy[id] = upd[id]=0;
        Tree[id][0] = INF;
        Tree[id][1] = -INF;
        Tree[id][2] = -1;
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    remove(pos, ns, md, l);
    remove(pos, md + 1, ne, r);
 merge(id,l,r);
}

array<ll, 3> query(int qs, int qe, int ns = 0, int ne = q, int id = 0){
    unlazy(id);
    if (qs > ne || qe < ns){
        array<ll, 3> ret{INF, -INF, -1};
        return ret;
    }
    if (qs <= ns && ne <= qe)return {Tree[id][0],Tree[id][1],Tree[id][2]};
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge2(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}

void Solve(){
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    cin >> q;

    build();
    vector<pair<ll,ll>> mp[n + 2];

    for (int i = 1; i <= q; i++){
        ll l, r, val;
        cin >> l >> r >> val;

        mp[l].pb({val, i});
        mp[r + 1].pb({-val, i});
    }

    for (int i = 1; i <= n; i++){
        for (auto [val, time] : mp[i]){ update(time, q, val); }

        int indx = 0 ;
        while (true){
            auto [mn,mx,indx_mx] = query(0, q);

            if (mn == mx || indx_mx == -1){
                v[i] += mn;
                break;
            }
            assert(++indx <= 5e5+40);
            remove(indx_mx);
        };
    }

    for (ll i = 1; i <= n; i++) cout << v[i] << " ";
    cout << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    ll Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
