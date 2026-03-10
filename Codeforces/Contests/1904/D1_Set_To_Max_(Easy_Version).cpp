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

const int  N=2e5+40 ,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


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
    }void print(){
        for(int i=0;i<n;i++)cout<<query(i,i)<<" ";cout<<'\n';}
};
template<class T> struct Seg2 { // comb(ID,b) = b
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
    }void print(){
        for(int i=0;i<n;i++)cout<<query(i,i)<<" ";cout<<'\n';}
};


void Solve() {
    int n ;
    cin >> n ;
    Seg<int> sg ;
    sg.build(n);
    vector<int> a(n) , b(n) ;
    Seg2<int> sum ;
    sum.build(n);
    for (int i= 0; i<n; i++){
        cin >> a[i] ;
        sg.upd(i,a[i]);
    }
    for (auto &x: b) cin >> x;
    for (int i= 1; i<=n ; i++){
        set<int> pos , lezem, deux;
        for (int j = 0 ; j<n ; j++){
            if (b[j]==i && a[j]>i){cout << "NO\n" ; return;}
            if (b[j]==i && a[j]<i)lezem.insert(j);
            if (a[j]==i)pos.insert(j);
        }
        for (auto p : lezem){
            auto it = pos.lower_bound(p);
            if (it != pos.end()&&sg.query(p,*it)<=i&&sum.query(p,*it)==0){
                pos.insert(p);continue;
            }
            if (it==pos.begin()){cout << "NO\n" ; return;}
            it--;
            if (sg.query(*it,p)<=i&&sum.query(*it,p)==0){
                pos.insert(p);continue;
            }
            cout << "NO\n";
            return ;
        }
        for (int j = 0 ; j<n ; j++){
            if (b[j]==i ){
                a[j]= i;
                sum.upd(j,1);
            }
        }

    }
    cout << "YES\n";
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}