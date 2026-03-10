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
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 1e7 + 5 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return  (a+b); }
    ll n; vector<T> seg;
    void build(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] += val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

void solve(){
    int n , m , ans = 0 ; 
    vector<pair<int,int>> Intervalles_joke [100005] ;
    vector <int> Last_joke [100005] ;
    cin >> n >> m ;
    set<int> s ;
    vector <array<int,3>> Qry ;
    for (int i= 0 ; i < m  ; i++ ){
        int  x, l , k ; 
        cin >> x >> l >> k ; 
        int left = max ( 1 , x-k ) , right = min ( n , x+k ) ;
        Intervalles_joke[l].pb(make_pair(left,right));
        Qry.pb({left,right,l});
    }
    Seg<ll> Sg ;
    Sg.build(n+5) ; 
    reverse(all(Qry));
    for (int i= 1 ; i<= n ;i++) s.insert(i);
    for (int i = 0; i<m ;i++ ){
        vector <int> Fassekh ;
        array<int,3> Curr = Qry[i];
        auto it = s.lower_bound( Curr[0] ) ;
        while ( it != s.end()){
            if ( *it > Curr[1]) break ;
            Fassekh.pb(*it) ; 
            it ++ ;
        }
        for (auto p : Fassekh){
            Last_joke[Curr[2]].pb(p) ;
            s.erase(p);
        }
    }
    for (int i= 0 ;i<= 1e5 ; i++){

        for (auto [left,right] : Intervalles_joke[i]){
            Sg.upd( left , 1 ) ;
            Sg.upd( right+1 , -1 ) ;
        }
        for (auto Monkey : Last_joke[i])
            if (Sg.query(1,Monkey)>1)
                ans ++ ;

        for (auto [left,right] : Intervalles_joke[i]){
            Sg.upd( left , -1 ) ;
            Sg.upd( right+1 , 1 ) ;
        }

    }
    cout << ans <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}