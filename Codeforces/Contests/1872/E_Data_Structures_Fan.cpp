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
#define endl '\n'
#define int ll


const long long N=1e4+8,MOD=1e9+7,mod=1e9+7,INF=1e18;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return  (a^b); }
    ll n; vector<T> seg;
    void build(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

void Solve(){
    int n , xr = 0, xrzero=0 ;cin >> n;
    string s ;
    vector <int> v(n ) ; 
    Seg <int > sg , oth; 
    sg.build(n+1 ) ;
    oth.build(n+1 ) ;
    for (int i= 0 ;i<n ; i++) cin>>v[i];

    cin >> s ;
    for (int i= 0 ;i<n ; i++) {
        if (s[i]=='0') {
            sg.upd(i,v[i]);
            xrzero^=v[i];
        }
        oth.upd(i,v[i]);
        xr^= v[i] ;
    }

    int q ; cin >> q;  
    while (q--){
        int x ; cin>> x; 
        if (x==2){
            cin >> x; 
            if (x) cout << (xr^xrzero)<< " ";
            else cout << xrzero << " ";
            continue;
        }
        int l , r ;
        cin >> l >> r ; 
        l-- ; r-- ;
        xrzero^= oth.query(l,r) ;
    }
    cout << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}