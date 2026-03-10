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

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  a+b; }
    void build(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }return comb(ra,rb);
    }
};

void Solve(){
    int q , sz =1 ;
    cin >> q ;
    vector <int> timer (q+3), graph[q+4] ,ans (q+4);
    vector <pair <int,int>> add [q+4];
    for (int i= 1; i<=q ; i++){
        int x ; cin >> x;
        if (x==1){
            int u ; cin >> u ;
            graph[++sz].pb(u);
            graph[u].pb(sz);
            timer [sz]= i ;
        }else {
            int u , x ;
            cin >> u >> x ;
            add [u].pb({i,x});
        }
    }

    Seg<int> sg ;
    sg.build(q+4);

    function <void(int,int)> dfs =[&] (int curr , int parent = -1) {
        for (auto [time,val] : add [curr])sg.upd(time,val);

        ans[curr]= sg.query(timer[curr],q+3);
        for (auto child: graph[curr]){
            if (child == parent ) continue;
            dfs (child, curr) ;
        }
        for (auto [time,val] : add [curr])sg.upd(time,0);
    };
    dfs(1,-1);
    for (int i= 1; i<= sz ; i++) cout << ans [i] << " " ; cout << endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
