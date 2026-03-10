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
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define MOD mod
#define INF (ll)(1e18)

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return  __gcd(a,b); }
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
    long long x ;
    cin>> n; 
    if (n==1 ){cin>> x ; cout << 1 <<endl; return;} 
    if (n==2){
        long long a , b ; 
        cin >> a >> b; 
        long long res = __gcd(a,b) ; 
        if (abs(a-b)==1 )cout << 1 <<endl;
        else cout << 2 <<endl;
        return;
    }


    vector<long long> v (n);
    Seg<ll> sg ;
    sg.build(n-1) ;  
    long long res = 1 ; 
    for (int i= 0 ; i<n ; i++ ){
        cin >> v[i] ;
        if (i ) {
            sg.upd(i-1,abs(v[i]-v[i-1])) ;
            if (abs(v[i]-v[i-1])!=1) 
                res = 2 ; 
        }
    }
    int r= 0 , l = 0 ;
    n-- ; 
    if (v[0]==1 ) r++ ; 
    while (r<n){
        ll now = sg.query(l,r) ; 
        while ( l<r && now==1) {
            l++ ;
            now = sg.query(l,r) ;
        }
        if (now!=1)
            res = max (res , ll(r-l+2));
        r++ ;
    }
    cout << res <<endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}