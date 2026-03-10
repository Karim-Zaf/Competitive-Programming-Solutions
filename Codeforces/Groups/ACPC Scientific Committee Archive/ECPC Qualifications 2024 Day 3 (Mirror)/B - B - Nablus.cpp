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

void count_sort(vector<int> &p , vector<int> &c){
    int n = (int)p.size() ;
    vector<int> cnt(n) ;
    for(auto x : c) cnt[x]++ ;
    
    vector<int> pos(n) ;
    pos[0] = 0;
    for(int i = 1 ; i < n ; i++) pos[i] = pos[i - 1] + cnt[i - 1] ;
    vector<int> new_p(n);
    for(auto x : p){
        int g = c[x] ;
        new_p[pos[g]] = x ;
        pos[g]++ ;
    }
    p = new_p;
}

void buildSuffixArray(string const& s , vector<int> &p , vector<int> &c){
    int n = s.size() ;
    
    // build for length 1
    vector<pair<char,int>> vec(n) ;
    for(int i = 0 ; i < n ; i++) vec[i] = {s[i] , i} ;
    sort(vec.begin() , vec.end()) ;
    for(int i = 0 ; i < n ; i++) p[i] = vec[i].S ;
    c[p[0]] = 0;
    for(int i = 1 ; i < n ; i++)
        c[p[i]] = c[p[i - 1]] + (vec[i].F != vec[i - 1].F) ;
    
    for(int k = 0 ; (1 << k) < n ; k++){
        for(int i = 0 ; i < n ; i++) 
            p[i] = (p[i] - (1 << k) + n) % n;
        count_sort(p , c) ;
        vector<int> new_c(n) ;
        new_c[p[0]] = 0;
        for(int i = 1 ; i < n ; i++) {
            pair<int,int> pre = {c[p[i - 1]] , c[(p[i - 1] + (1 << k)) % n]} ;
            pair<int,int> cur = {c[p[i]] , c[(p[i] + (1 << k)) % n]} ;
            new_c[p[i]] = new_c[p[i - 1]] ;
            if(pre != cur) new_c[p[i]]++ ;
        }
        c.swap(new_c) ;
    }
}
int lower_bound(vector<int> &p , string &t , string &s){
    int sz = t.size();
    int n = s.size() ;
    int l = 0 , r = n - 1 , lo = n;
    while(l <= r){
        int mid = (l + r) / 2;
        string cur = s.substr(p[mid] , sz) ;
        
        if(cur >= t) {
            r = mid - 1;
            lo = mid ;
        }else l = mid + 1; 
    }
    return lo ;
}
int upper_bound(vector<int> &p , string &t , string &s){
    int sz = t.size();
    int n = s.size() ;
    int l = 0 , r = n - 1 , ro = n;
    while(l <= r){
        int mid = (l + r) / 2;
        string cur = s.substr(p[mid] , sz) ;
        
        if(cur > t) {
            r = mid - 1;
            ro = mid ;
        }else l = mid + 1; 
    }
    return ro ;
}
vector<int> build_lcp(string const& s ,vector<int> &p , vector<int> &c){
    int n = (int)p.size() ;
    vector<int> lcp(n) ;
    int k = 0 ;
    for(int i = 0 ; i < n - 1 ; i++){
        int idx = c[i] ;
        int j = p[idx - 1] ;
        while(s[i + k] == s[j + k]) k++ ;
        lcp[idx] = k ;
        k = max(0 , k - 1) ;
    }
    return lcp ;
}
template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 2e9;    ll n; vector<T> seg;
    T comb(T a, T b) { return  min(a , b); }
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
    string s ; 
    cin >> s ; 
    s += "#" ; 
    n++ ;
    vector<int> ans(n + 5) ;
    vector<int> p(n) , c(n) ; 
    buildSuffixArray(s , p , c) ;
    vector<int> lcp = build_lcp(s , p , c) ;
    Seg<int> segTree , segTreeidx ; 
    segTree.init(n + 5) ;
    segTreeidx.init(n + 5) ;
    for(int i = 0 ; i < n ; i++) {
        segTree.upd(i , lcp[i]) ;
        segTreeidx.upd(i , p[i]) ;
    }
    set<int> st;
    for(int len = 1 ; len < n ; len++) st.insert(len) ;
    
    for(int i = 1 ; i < n ; i++){
        if(st.empty()) break; 
        int sz = n - p[i] - 1;
        int mn = *st.begin() ;
        if(mn > sz) continue ;
        for(int len = mn ; len <= sz ; len++){
            int l = i + 1 , r = n - 1 , mxr = i;
            while(l <= r){
                int mid = (l + r) / 2 ;
                int g = segTree.query(i + 1 , mid) ;
                if(g >= len) {
                    mxr = mid ;
                    l = mid + 1;
                } else r = mid - 1;
            }
            ans[len] = segTreeidx.query(i , mxr) ;
        }
        for(int len = mn ; len <= sz ; len++) st.erase(len) ;
    }
    for(int i = 1 ; i < n ; i++) cout << ans[i] + 1 << " " ;
    cout << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}