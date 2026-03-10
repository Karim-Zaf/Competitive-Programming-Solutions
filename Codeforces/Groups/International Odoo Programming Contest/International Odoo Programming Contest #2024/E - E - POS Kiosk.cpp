/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

const int N = 1e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = INF ;    ll n; vector<T> seg;
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
void Solve() {
    Seg<int> sg ;

    int n ;
    cin >> n ;
    sg.build(n+5) ;
    vector<int> v(n+4) , pref(n+4) , quer (n+4);
    vector<int> suff(n+2) ;
    map<int,int> mp ;


    set<array<int,4>> s;
    for (int i= 1; i<=n ;i++) cin >> v[i] ;
    for (int i=n ; i>=1; i--){
        suff[i]= v[i]+ suff[i+1] ;
    }
    int timer = 0 ;
    for (int i= 0 ;i<=n ;i++) mp[suff[i]]=1 ;
    for (auto x: mp) mp[x.F]=++timer ;

    int res = 0;
    kar (suff);
    for (int i= n+1; i>= 1; i--){
        int pos = sg.query(0, mp[suff[i]]);
        sg.upd(mp[suff[i]],i);
        if (pos == INF) {
            continue ;
        }

        quer[i] += quer[pos] + (suff[i]- suff[pos]) * ( n- pos +2 ) ;
        kar (pos) ;
        res += quer[pos] + (suff[i]- suff[pos]) * ( n- pos +2 ) ;
    }
    kar (quer) ;
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}

//Seg<int> sg ;
//
//    int n , ans = 0;
//    cin >> n ;
//    sg.build(n+5) ;
//    vector<int> v(n+4) , pref(n+4) ;
//    map<int,int> mp ;
//    indexed_set s;
//
//    for (int i=n ; i>=1; i--)
//        cin >> v[i];
//    kar (v) ;
//    for (int i= 1; i<=n ;i++){
//        pref[i]= pref[i-1]+v[i] ;
//    }
//
//    for (int i= 0 ;i<=n ;i++) mp[pref[i]]=1 ;
//    kar (mp );
//    int timer = 0 ;
//    for (auto x: mp) mp[x.F]=++timer ;
//
//    for (int i= 1;i<=n ;i++){
//        int nb_tahti = s.order_of_key({pref[i],INF});  // lower_than me
//        ans += nb_tahti * pref[i] - (sg.query(0,mp[pref[i]]));
//        sg.upd(mp[pref[i]], sg.query(mp[pref[i]],mp[pref[i]]+pref[i]));
//        s.insert({pref[i],i}) ;
//    }
//    kar (s);
//    kar (mp );
//    kar (pref);
//    cout << ans << endl;