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

const ll N = 1e6 + 1 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;


template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return  a+b; }
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

void solve(){
    int n , m , x ; 
    cin >> n >> m ; 
    vector <int> vis(n), nb_div(N);
    Seg<ll> sg ; 
    set <int> s ; 
    sg.build(n);
    for (int i= 1 ; i<N ; i++)
        for (int j = i ; j <N ; j+=i )
            nb_div[j]++;
    for (int i= 0 ; i<n ;i++){ 
        cin >> x ;
        sg.upd(i,x);
        s.insert(i);
    }
    while ( m-- ){
        int x , l,  r  ; 
        cin >> x >> l>> r ; 
        l-- ; r--;
        if ( x== 1 ){
            auto it = s.lower_bound( l );
            set <int> erase ;
            while (*it <=r && it != s.end()){
                ll curr = sg.query(*it,*it);
                sg.upd(*it , nb_div[curr]);
                vis[*it]++;
                if ( vis[*it] >=6) erase.insert(*it);
                it ++ ;
            }
            for (auto pp : erase ) s.erase(pp);
        }else cout << sg.query(l,r) << endl; 
    }


}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}