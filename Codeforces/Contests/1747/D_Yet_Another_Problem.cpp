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

const int  N=2e5+30,NN = 5e5, MOD=1e9+7,mod=1e9+7,INF=1e18+10;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  a^b ; }
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
    }void print(){
        for(int i=0;i<n;i++)cout<<query(i,i)<<" ";cout<<'\n';}
};
template<class T> struct Seg2 { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  a+b ; }
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
    }void print(){
        for(int i=0;i<n;i++)cout<<query(i,i)<<" ";cout<<'\n';}
};
void Solve() {
    Seg<int> sg ;
    Seg2<int> sum ;
    int n  , q; cin >> n >> q ;
    sg.build(n+3);
    sum.build(n+3);
    map <int,int> ver[2] ;
    vector<int> ans (n+5);
    int blasa ;
    for (int i= 1 ; i<=n ; i++){
        int x ; cin >> x;
        sum.upd(i,x);
        sg.upd(i,x);
        ver [i%2][sg.query(0,i)]=i ;
        ans[i] = ver[(i%2)^1][sg.query(0,i)];
    }
    while (q--){
        int l , r ; cin >> l >> r ;
        if (sg.query (l,r)==0) {
            if (sum.query(l,r)==0) cout << 0 << endl;
            else if ((r-l)%2 && r-l>1){
                if (sum.query(l,l)==0||sum.query(r,r)==0 ) cout << 1 << endl;
                // zouz intervallowet odd
                else if (ans[r]>=l) cout << 2 << endl;
                else cout << -1 << endl;
            }
            else if ((r-l)%2==0) cout << 1 << endl;
            else cout << -1 << endl;
        }else cout << -1 << endl;
    }
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}