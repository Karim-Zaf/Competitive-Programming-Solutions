#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
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
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
template<class T> struct Seg { // comb(ID,b) = b
    const T ID = {2e9, 2e9};    ll n; vector<T> seg;
    T comb(T a, T b) { return  (a.S < b.S ? a : b);}
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
 
int a[N_Max], nxt[N_Max];
Seg<pair<int, int>> st;
map<int, set<int>> mp;
int N, Q;
 
void update(int pos, int val){
    auto it = mp[a[pos]].find(pos);
    int r = N + 1;
    if (next(it) != mp[a[pos]].end()){
        r = *next(it);
        st.upd(pos, {2e9, 2e9});
    }
    int l = 0;
    if (it != mp[a[pos]].begin()){
        l = *prev(it);
        st.upd(l, {2e9, 2e9});
    }
    if (l >= 1 && r <= N) st.upd(l, {l, r});
    mp[a[pos]].erase(pos);
    it = mp[val].lower_bound(pos);
    r = N + 1, l = 0;
    if (it != mp[val].end()){
        r = *it;
        st.upd(pos, {pos, r});
    }
    if (it != mp[val].begin()){
        l = *prev(it);
        st.upd(l, {l, pos});
    }
    mp[val].insert(pos);
    a[pos] = val;
}
 
void solve(){
    cin >> N >> Q;
    st.init(N + 5);
    map<int, int> lst;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = N; i >= 1; i--){
        mp[a[i]].insert(i);
        if (!lst[a[i]]) st.upd(i, {2e9, 2e9});
        else st.upd(i, {i, lst[a[i]]});
        lst[a[i]] = i;
    }
    for (int i = 1; i <= Q; i++){
        int t;
        cin >> t;
        if (t == 0){
            int ind, val;
            cin >> ind >> val;
            update(ind, val);
            continue;
        }
        int l, r;
        cin >> l >> r;
        pair<int, int> p1 = st.query(l, r);
        if (p1.S > r){
            cout << -1 << endl;
            continue;
        }
        pair<int, int> p2 = {2e9, 2e9};
        if (p1.F + 1 <= p1.S - 1)
            p2 = st.query(p1.F + 1, p1.S - 1);
        if (p2.S <= r){
            cout << p1.F << " " << p1.S << " " << p2.F << " " << p2.S << endl;
            continue;
        }
        if (l <= p1.F - 1)
            p2 = st.query(l, p1.F - 1);
        if (p2.S <= r){
            cout << p1.F << " " << p1.S << " " << p2.F << " " << p2.S << endl;
            continue;
        }
        if (p1.S + 1 <= r)
            p2 = st.query(p1.S + 1, r);
        if (p2.S <= r){
            cout << p1.F << " " << p1.S << " " << p2.F << " " << p2.S << endl;
            continue;
        }
        cout << -1 << endl;
    }
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}