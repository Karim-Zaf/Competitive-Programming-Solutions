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
#define endl '\n'
#define int ll

const ll N =30+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

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
void solve(){
    int n , m , q ;
    cin >> n >> m >> q ;
    Seg <int> sg ;
    sg.build(n+1) ;
    vector <array <int,5>> queries (q+1);
    vector <int> capacity(n+1);
    vector<array <int,2>>days(m+1) ;
    for (int i= 1 ; i<=n ; i++) cin>> capacity[i];
    for (int i= 1 ; i<=m ; i++) cin >> days[i][0]>>days[i][1];
    for (int i = 1 ; i<=q ; i++) {
        cin >> queries[i][0]>> queries[i][1]>> queries[i][2];
        queries[i][3]=i;
    }
    int j= 1 ;
    sort (all(queries)) ;
    for(int i=1 ; i<=m;i++){
        sg.upd(days[i][0],min(capacity[days[i][0]],sg.query(days[i][0],days[i][0])+days[i][1]));
        while (j<=q && queries[j][0]==i){queries[j][4]= sg.query(queries[j][1],queries[j][2]); j++;}
    }
    sort (all(queries),[](array <int,5>a , array <int,5>b){return a[3]<b[3];});
    for (int i= 1 ;i<= q ; i++ ) cout << queries[i][4] << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}