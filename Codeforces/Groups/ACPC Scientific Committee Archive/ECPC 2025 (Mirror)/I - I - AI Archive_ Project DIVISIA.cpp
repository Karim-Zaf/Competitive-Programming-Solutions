#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define F first
#define S second
#define pb push_back
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const int mod = 998244353;
const int N_Max = 200100;
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
 
vector<int> st[4 * N_Max];
int a[N_Max];
int N;
 
void merge(int id, int l, int r){
    int i = 0, j = 0;
    while (i < (int)st[l].size() && j < (int)st[r].size()){
        if (st[l][i] < st[r][j]) st[id].pb(st[l][i++]);
        else st[id].pb(st[r][j++]);
    }
    while (i < (int)st[l].size()) st[id].pb(st[l][i++]);
    while (j < (int)st[r].size()) st[id].pb(st[r][j++]);
}
 
void build(int id, int ns, int ne){
    if (ns == ne){
        st[id].pb(a[ns]);
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    build(lc, ns, mid);
    build(rc, mid + 1, ne);
    merge(id, lc, rc);
}
 
int query(int id, int ns, int ne, int l, int r, int x){
    if (ns > r || ne < l) return 0;
    if (ns >= l && ne <= r) return upper_bound(st[id].begin(), st[id].end(), x) - st[id].begin();
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    return query(lc, ns, mid, l, r, x) + query(rc, mid + 1, ne, l, r, x);
}
 
 
int n, q;
string s;
 
void solve() {
    cin >> s >> q;
    s += '$';
    n = s.size();
 
    for(int i = 1; i <= 4 * n; i++)
        st[i].clear();
        
    vector<int> p(n), c(n);
    buildSuffixArray(s, p, c);
 
    for(int i = 1; i < n; i++)
        a[i] = p[i];
    build(1, 1, n - 1);
 
    while(q--) {
        string t;
        cin >> t;
        int sz = t.size();
        int l = lower_bound(p, t, s);
        int r = upper_bound(p, t, s);
 
        int lo = 1, ro = n - 2;
        int eq = -1, ans = 0;
        while(lo <= ro) {
            int md = (lo + ro) / 2;
 
            // l <= suf < r && p[suf] <= md - sz
            int x = query(1, 1, n - 1, l, r - 1, md - sz);
            int y = r - l - query(1, 1, n - 1, l, r - 1, md - 1);
 
            if(x >= y){
                eq = md;
                ans = max(ans, min(x, y));
                ro = md - 1;
            } else lo = md + 1;
        }
 
        cout << ans << endl;
    }
}  
 
int main() {
    FAST
    // freopen("nocross.in","r",stdin);
    // freopen("nocross.out","w",stdout);
 
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
   
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}