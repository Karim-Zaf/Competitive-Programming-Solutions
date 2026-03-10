#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int mod = 1e9 + 7;
const ll inf = 1e18 + 500;
const long double EPS = 1e-10;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
const int N_Max = 100010;
 
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
    for(int i = 0 ; i < n ; i++) p[i] = vec[i].second ;
    c[p[0]] = 0;
    for(int i = 1 ; i < n ; i++)
        c[p[i]] = c[p[i - 1]] + (vec[i].first != vec[i - 1].first) ;
    
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
 
template <class T>
struct Seg{ /*CHANGE THE ID YA KARIM !!*/
    const T ID = 2e9;
    int n;
    vector<T> seg;
    T merge(T a, T b){ return min(a , b); }
    Seg(int _n) : n(_n), seg(2 * n, ID){}
    void pull(int p){ seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }
 
    void upd(int p, T val){
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }
 
    T query(int l, int r){
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
            if (l & 1) ra = merge(ra, seg[l++]);
            if (r & 1) rb = merge(seg[--r], rb);
        }
        return merge(ra, rb);
    }
 
    void print(int i = -1){
        while (++i < n) cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " ");
    }
};
 
struct Query{
    int id, l, r;
};
 
Query qry[N_Max];
ll ans[N_Max];
int a[N_Max];
int occ[N_Max];
vector<int> dv[N_Max];
vector<pair<int, int>> g[N_Max];
int n, q;
int l, r;
ll curans = 0;
 
void add(int val){
    for (auto [v, sgn] : g[val]) 
        curans += occ[v] * sgn, occ[v]++;    
}
 
void rmv(int val){
    for (auto [v, sgn] : g[val]) 
         occ[v]--, curans -= occ[v] * sgn; 
}
 
void update(int id){
    while (r < qry[id].r) add(a[++r]);
 
    while (l > qry[id].l) add(a[--l]);
    
    while (r > qry[id].r) rmv(a[r--]);
    
    while (l < qry[id].l) rmv(a[l++]);
}
 
void mo(){
    int B = sqrt(2 * n);
    sort(qry, qry + q, [B](Query a, Query b){return make_pair(a.l / B, a.r) < make_pair(b.l / B, b.r);});
    l = 0, r = -1;
    for (int i = 0; i < q; i++){
        update(i);
        ans[qry[i].id] = curans;
    }
}
 
void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += '$';
    n = s.size();
    
    vector<int> p(n), c(n);
    buildSuffixArray(s, p, c);
 
    vector<int> lcp = build_lcp(s, p, c);
    
    Seg<int> st(n + 5);
    for (int i = 0; i < n; i++) 
        st.upd(i, lcp[i]);
    
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[p[i]] = i;
 
    for (int i = 0; i < n; i++)
        a[i] = n - 2 - p[i] + 1;
 
    cin >> q;
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        r--, l--;
        int nwr = n - 2 - l;
        int nwl = nwr - (r - l);
 
        int p = pos[nwl];
        int lo = 0, ro = p - 1, ql = p;
        while (lo <= ro) {
            int md = (lo + ro) / 2;
            if (st.query(md + 1, p) >= r - l + 1) {
                ql = md;
                ro = md - 1;
            }else lo = md + 1;
        }
 
        lo = p + 1, ro = n - 1;
        int qr = p;
        while (lo <= ro) {
            int md = (lo + ro) / 2;
            if (st.query(p + 1, md) >= r - l + 1) {
                qr = md;
                lo = md + 1;
            }else ro = md - 1;
        }
 
        qry[i] = {i, ql, qr};
    }
 
    mo();
 
    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;
}   
 
signed main(){
    FAST
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    for (int p = 2; p < N_Max; p++){
        if (dv[p].empty()) {
            for (int m = p; m < N_Max; m += p)
                dv[m].push_back(p);
        }
    }
 
    for (int v = 1; v < N_Max; v++){
        int sz = dv[v].size();
        for (int mask = 1; mask < (1 << sz); mask++){
            int p = 1;
            int c = 0;
            for (int i = 0; i < sz; i++){
                if ((1 << i) & mask) {
                    p *= dv[v][i];
                    c++;
                }
            }
            if (c & 1) {
                g[v].push_back({p, 1});
            }else {
                g[v].push_back({p, -1});
            }  
        }
    }
 
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}