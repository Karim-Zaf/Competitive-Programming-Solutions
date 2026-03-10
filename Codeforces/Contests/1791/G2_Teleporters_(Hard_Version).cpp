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

const int  N=4e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

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
    }void print(){
        for(int i=0;i<n;i++)cout<<query(i,i)<<" ";cout<<'\n';}
};

void Solve() {
    int n , c , ans = 0;
    cin >> n >> c;
    Seg <int> sg ;
    sg.build(n+5) ;
    vector<int> v(n+1) , id(n+1);
    vector <pair<int,int>> s ;
    for (int i= 1; i<=n ;i++){
        cin >> v[i] ;
        int ans1 = i + v[i] , ans2 = n+1 - i +v[i];
        s.pb ({min (ans1 , ans2),i}) ;
    }
    sort (all(s));
    for (int i= 0 ; i< n ; i++){
        sg.upd(i+1,s[i].F) ;
        id [s[i].S]= i+1 ;
    }
    for (int i= 1; i<=n ;i++){
        int ans_l = i+ v[i] ;

        if (ans_l > c) continue;

        int prec = sg.query (id[i],id[i]);

        sg.upd (id[i],0);
        int l = 0 , r = n , res =-1 , nw_c = c- ans_l;
        while (l<=r){
            int md = l + (r-l)/2 ;
            int sum = sg.query (0 , md) ;
            if (sum<=nw_c) {
                l = md +1 ;
                res = md ;
            }
            else r= md -1 ;
        }
        if (res >= id[i]) ans = max (ans, res);
        else ans = max (ans , res+1) ;


        sg.upd (id[i],prec);
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
