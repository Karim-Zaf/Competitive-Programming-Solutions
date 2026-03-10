/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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

const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 1e9; T comb(T a, T b) { return  min(a,b); }
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

void solve (){
    int n ; 
    cin >> n; 
    vector <array<int,3>> v(n);
    vector <array<int,2>> ca, cb , ab ;
    map <int,int> id1, id2 , id3 ; 
    Seg <int > caa , cbb , abb;
    caa.build(n);
    cbb.build(n);
    abb.build(n);

    for (int i= 0 ;i<n ;i++){
        cin >> v[i][0] >> v[i][1]>>v[i][2];
        ca.pb({v[i][2],v[i][0]});
        cb.pb({v[i][1],v[i][2]});
        ab.pb({v[i][0],v[i][1]});
    }  

    sort (all(ca));
    sort (all(cb));
    sort (all(ab));

    for (int i= 0 ;i<n ;i++){
        id1[ca[i][0]]=i;
        caa.upd(i,ca[i][1]);
    } 
    for (int i= 0 ;i<n ;i++){
        id2[cb[i][0]]=i;
        cbb.upd(i,cb[i][1]);
    } 
    for (int i= 0 ;i<n ;i++){
        id3[ab[i][0]]=i;
        abb.upd(i,ab[i][1]);
    }   

    for (int i= 0 ;i<n ;i++ ){
        int ok = 0, curr = 1e9 ;

        array<int,2>  one = {v[i][2],v[i][0]};
        if (id1[v[i][2]]>=1)
            curr = caa.query(0,id1[v[i][2]]-1) ; 
        // kar (one);
        if (curr <v[i][0]){ok = 1 ;}

        curr = 1e9;

        one = {v[i][1],v[i][2]};
        if (id2[v[i][1]]>=1)
            curr = cbb.query(0,id2[v[i][1]]-1) ; 
        // kar (cbb.query(id2[v[i][1]],id2[v[i][1]]));
        if (curr <v[i][2]){ok = 1 ;}

        curr = 1e9;
        one = {v[i][0],v[i][1]};
        if (id3[v[i][0]]>=1)
            curr = abb .query(0,id3[v[i][0]]-1) ; 
        if (curr <v[i][1]){ok = 1 ;}
        // kar (curr);

        if (!ok ){cout << 1 << endl; cout << i+1 << endl; return;}
    }
    cout << 0 << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}