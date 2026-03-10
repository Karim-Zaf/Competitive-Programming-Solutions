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
 
const int  N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;
 
array <int,3> query( int l , int r  ){
    array <int,3> a ;
    cout << "? "<< l << " " << r << endl;
    cout.flush();
    cin >> a[0]>> a[1]>> a[2] ;
    return a ;
}
 
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
    }
};
 
void Solve(){
    int n ;
    cin >> n ;
    vector <int> v(n+1) ;
    vector<vector <int>>mp(n+1) ;
    Seg <int> sg ;
    sg.build(n+1) ;
 
    for (int i= 1 ; i<=n; i++){
        int l = i ;
        int indx = 0;
        for (int j= 1;j<=i;j++)
            if (indx==mp[i].size()|| mp[i][indx]!=j){
                l = j ;
                break;
            }else indx++;
        array <int,3> a = query(l,i);
        int pos = lower_bound(all(mp[a[2]]),a[1])-mp[a[2]].begin() ;
        if (pos==mp[a[2]].size()||mp[a[2]][pos]!=a[1]) mp[a[2]].pb(a[1]);
        sort (all(mp[a[2]]));
        if (l==i)v[i]=a[0];
        else v[i]= a[0]-sg.query(l,i-1);
        sg.upd(i,v[i]);
    }
    cout << "! ";
    for (int i= 1;i<=n;i++ )cout <<v[i]<< " " ;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while(Test_case--)Solve();
}