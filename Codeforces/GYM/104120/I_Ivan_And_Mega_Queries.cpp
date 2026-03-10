#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define ld double
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define affichea(a,n) for(ll i=0 ; i<n ; i++) cout << a[i] <<" " ;
#define yes cout << "Yes" << endl;
#define no cout<<"No"<<endl;
#define F first
#define S second
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define double long double
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 500100 ; 
ll a[N] , idx[N] ; 

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  max(a,b); }
    void init(ll _n) { n = _n; seg.assign(2*n,ID); }
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

void solve(){
    int n ; 
    cin >> n ; 
    Seg<ll> st ;
    st.init( n + 5 ) ;  
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ; 
        st.upd(i , a[i]) ;
    }
    int q ; 
    cin >> q ; 
    while(q--){
        int m ; 
        cin >> m ; 
        for(int i = 1 ; i <= m ; i++) cin >> idx[i] ;
        
        ll ans = a[idx[m]]  ;
        multiset<array<ll,2>> s ; 

        s.insert({- a[idx[m]] , 1}) ;
        
        ll prev = a[idx[m]] ; 

        for(int i = m - 1 ; i >= 1 ; i--) {
            ll g = st.query(idx[i] , idx[i+1]) , c = 0 ; 
            vector<array<ll,2>> e ;  
            ll cur = prev ; 
            for(auto it = s.upper_bound({-g , -(ll)(2e9)}) ; it != s.end() ; it++){
                array<ll,2> arr = *it ; 
                cur += arr[0] * arr[1] ;
                e.pb(arr) ;  
                c += arr[1] ;  
            }
            for(auto arr : e) s.erase(s.find(arr)) ; 

            cur += g * c ;
            
            prev = cur ;
            prev += a[idx[i]] ;  
            ans += prev ;  
            s.insert({-g , c}) ;
            s.insert({-a[idx[i]] , 1}) ; 
        }
        cout << ans << endl ;
    }
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  