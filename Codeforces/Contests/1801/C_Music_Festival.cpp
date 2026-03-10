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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

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
        for(int i=0;i<10;i++)cout<<query(i,i)<<" ";cout<<'\n';}
};

Seg<int> sg ;

void Solve() {
    int n ,res =0;
    cin >> n ;
    vector <vector<int>> v(n);
    for (int i= 0; i<n; i++){
        int k; cin >> k ;
        for (int j= 0 ;j<k ;j++){
            int x ; cin>> x;
            if (v[i].empty()||x>v[i].back())
                v[i].pb(x);
        }
        reverse(all(v[i]));
    }
    sort (rall(v));
    for (auto vect : v){
        for (int i= 0; i<vect.size(); i++){
            int curr=vect[i] , ans = i+1 ;
            ans +=  sg.query (vect[0]+1,N-1);
            sg.upd(curr,max(ans,sg.query(curr,curr)));
            res = max (res, ans );
        }
    }
    cout << res << endl;
    for (auto vect : v) {
        for (auto x: vect )
            sg.upd(x,0);
    }
}


int32_t main(){
     #ifndef ONLINE_JUDGE
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case ;
    sg.build(N) ;
    while (Test_case--) Solve();
}