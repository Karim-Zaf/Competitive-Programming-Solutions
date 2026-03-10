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

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 1e6;    ll n; vector<T> seg;
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
    int n , k ;
    cin >> n >> k ;
    vector<int> v(n+6) ;

    int l = 0 , r = n+1 , ans =-1;
    for (int i= 1; i<=n ; i++) cin >> v[i] ;
    auto ok = [&] (int sz) ->bool{
        Seg<int> sg ;
        sg.build(3*n+4);
        vector<int> pref(n+4,n+4) ;

        sg.upd(n+4,0);
        for (int i=1 ;i<=n; i++)
            pref[i]= pref[i-1]+ (v[i]>=sz? 1 : -1) ;
        for (int i= 1 ;i<=n ; i++){
            int pos = sg.query(0,pref[i]-1);
            if (pos <= i - k)return true;
            sg.upd(pref[i],min(i,sg.query(pref[i],pref[i])));
        }
        return false ;
    };
    while (l<=r){
        int md = l + (r-l)/2 ;
        if (ok (md)) {
            l =  md+1 ;
            ans = md ;
        }else r = md -1 ;
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}