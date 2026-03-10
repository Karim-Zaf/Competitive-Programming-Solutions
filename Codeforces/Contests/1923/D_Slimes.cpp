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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int pref[N];



int get (int l , int r) {
    return pref[r]-pref[l-1];
}










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
    }void print(){
        for(int i=0;i<n;i++)cout<<query(i,i)<<" ";cout<<'\n';}
};
template<class T> struct Seg3 { // comb(ID,b) = b
    const T ID = -INF;    ll n; vector<T> seg;
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
    }void print(){
        for(int i=0;i<n;i++)cout<<query(i,i)<<" ";cout<<'\n';}
};


int n ;
vector<int> v ;
Seg2<int>mn ;
Seg3<int> mx ;

bool verif (int l , int r , int x){
    int mxx =mx.query(l,r);
    int mnn =mn.query(l,r);
    if (mxx==mnn && mxx<=x) return false ;
    return true;
}

int workrigh (int i,int x){
    int ret = -1;
    int l = i , r = n ;
    while(l<=r){
        int md = l + (r-l)/2 ;
        if (get(i,md)>x && verif (i,md,x)){
            r = md -1;
            ret = md;
        }else {
            l = md +1 ;
        }
    }
    return ret;
}

int worklef (int i,int x){
    int ret = -1;
    int l = 1 , r = i ;
    while(l<=r){
        int md = l + (r-l)/2 ;
        if (get(md,i)>x && verif (md,i,x)){
            l = md +1;
            ret = md;
        }else {
            r = md -1 ;
        }
    }
    return ret;
}

void Solve() {
    cin >> n ;
    v.resize(n+5);
    vector<int> ans;
    for (int i= 1 ;i<=n ;i++){
        cin >> v[i] ;
        pref[i]= pref[i-1]+v[i];
        mx.upd(i,v[i]);
        mn.upd(i,v[i]);
    }

    for (int i= 1 ;i<=n ;i++){
        int one = worklef(i-1,v[i]);
        if (one!=-1)one = i -one ;
        int two = workrigh(i+1,v[i]);
        if (two!=-1)two -= i ;
        if (one == -1) one = INF;
        if (two == -1) two = INF;
        ans.pb(min(one,two));
    }
    for (auto x: ans)
        cout << (x>=INF ? -1: x) << " ";
    cout << endl;
}

int32_t main(){
    mx.build(N) ;
    mn.build(N) ;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}