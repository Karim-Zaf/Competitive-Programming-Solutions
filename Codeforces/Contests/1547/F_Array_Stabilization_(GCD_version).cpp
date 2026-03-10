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

const int  N=5e6+8,MOD=1e9+7,mod=1e9+7,INF=1e18;


vector <int> v;
int n ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  __gcd (a,b); }
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

Seg <int> sg ;

bool ok (int x){
    set <int> s ;
    for (int i= 0;i<n;i++){
        int g = sg.query(max(0ll,i - x),i);
        if ( i - x<0)
            g=__gcd (g,sg.query(max(i,n+i-x),n-1));
        s.insert(g);
    }return s.size()==1;
}

void Solve(){
    cin >> n;
    sg.build(n);
    set <int> s ;
    for (int i= 0 ;i<n ;i++){
        int x ; cin >> x ;
        sg.upd(i,x) ;
        s.insert(x);
    }
    if (s.size()==1){cout << 0 << endl;return;}
    int l =  0 ,  r = 1e9, res = -1 ;
    while (l<=r){
        int md = l + (r-l)/2 ;
        if (ok(md+1)){
            res = md+1 ;
            r = md-1 ;
        }else l = md+1;
    }
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while(Test_case--)Solve();
}