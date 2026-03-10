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

const int  N=3e5+30,MOD=998244353,mod=998244353,INF=1e18+10;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  max(a,b); }
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
template<class T> struct Seg2 { // comb(ID,b) = b
    const T ID = INF;    ll n; vector<T> seg;
    T comb(T a, T b) { return  min(a,b); }
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

void Solve() {
    int n , ans = 1;
    cin>> n ;
    Seg<int> mx ;
    Seg2<int> mn ;
    vector<int> v(2*n+1), pos(n+3,-1) ;
    vector<pair<int,int>> vp ;
    mx.build(2*n+5);
    mn.build(2*n+5);

    for (int i=1 ;i<=2*n ; i++) {
        cin >> v[i];
        if (pos[v[i]]!=-1) mx.upd(pos[v[i]],i);
        if (pos[v[i]]!=-1) mn.upd(i,pos[v[i]]);
        pos[v[i]]=i;
    }

    int l =1, r = pos[v[1]];
    while (r<2*n){
        int nw_r = mx.query(l,r);
        if (nw_r ==r){
            vp.pb({l,r});
            l = r +1 , r = pos[v[r+1]];
        }else r = nw_r ;
    }
    vp.pb({l,r});
    for (auto[lef,righ]: vp){
        int curr = 0 ;
        for (int i=lef ; i<= righ ; i++){
            if (i==pos[v[i]])continue;
            l = i,  r= pos[v[i]];
            while (true){
                int nw_r = mx.query (l,r);
                int nw_l = mn.query (l,r);
                if (nw_r==r && nw_l == l)break;
                l= nw_l , r = nw_r;
            }
            if (l==lef && r== righ){
                curr += 2 ;
                curr%= mod ;
            }
        }
        ans= ans *curr%mod;
    }

    cout << vp.size() << " " << ans <<endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}