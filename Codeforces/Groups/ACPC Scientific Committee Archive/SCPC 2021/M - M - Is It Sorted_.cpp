//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 3e5 + 7;
const int Nax = 1e6 + 5;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

const int N = 100010 ; 
int a[N], l[N] ; 

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = -2e9;    ll n; vector<T> seg;
    T comb(T a, T b) { return  max(a , b); }
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

//nearest
  
 
void prep_prev(int N){
    vector<int> stack;
    for (int i = 0; i < N; i++) l[i] = 0;
    for (int i = N - 1 ; i >= 0; i--){
        while (!stack.empty() && a[stack.back()] < a[i]){
            l[stack.back()] = i + 1;
            stack.pop_back();
        }
        stack.pb(i);
    }
}
void solve(){
    int n ; 
    cin >> n ;
    map<int,int> f ; 
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
        f[a[i]]++ ;
    } 
    
    // compression
    int idx = 1 ;
    for(auto x : f) f[x.F] = idx++ ; 
    for(int i = 0 ; i < n ; i++) a[i] = f[a[i]] ;
    
    // computing nearest element to the left of i greater than ai
    prep_prev(n);

    // init SEGMENT TREE
    Seg<int> st;
    st.init(n + 5) ;

    // computing LIS
    st.upd(0 , 1) ;
    
    int ans = 1 ;
    for(int i = 1 ; i < n ; i++) {
        if(l[i] == i) continue ;
        int cur = st.query(l[i] , i) + 1; 
        if(st.query(i , i) < cur) st.upd(i , cur) ;
        ans = max(ans , cur) ;
    }
    
    // the answer is total - LIS
    cout << n - ans << endl;
}

int main(){
    FAST
    freopen("store.in","r",stdin);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}