#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define int ll
const int mod = 1e9 + 7;
const ll inf = 1e18 + 500;
const long double EPS = 1e-10;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
struct node{
    char fs, ls;
    bool flag;
    int mask;
};
const int N_Max = 200100;
int lazy[4 * N_Max];
node st[4 * N_Max];
string s;
int n, q;
 
node merge(node l, node r){
    node res;
    res.fs = l.fs;
    res.ls = r.ls;
    res.mask = l.mask | r.mask;
    res.flag = l.flag || r.flag || l.ls == r.fs;
    return res;
}
 
void build(int id, int ns, int ne){
    if (ns == ne){
        st[id] = {s[ns], s[ne], false, (1 << s[ns] - 'a')};
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    build(lc, ns, mid);
    build(rc, mid + 1, ne);
    st[id] = merge(st[lc], st[rc]);
}
 
void upd(int id, int sz, int c) {
    lazy[id] = c;
    st[id] = {char(c + 'a'), char(c + 'a'), (sz == 1 ? false : true), (1 << c)};    
}
 
void pushdown(int id, int ns, int ne){
    if (lazy[id] == -1) return;
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    upd(lc, mid - ns + 1, lazy[id]);
    upd(rc, ne - mid, lazy[id]);
    lazy[id] = -1;
}
 
void update(int id, int ns, int ne, int l, int r, char x){
    if (ns > r || ne < l) return;
    if (ns >= l && ne <= r){
        upd(id, ne - ns + 1, x - 'a');
        return;
    }
    pushdown(id, ns, ne);
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    update(lc, ns, mid, l, r, x);
    update(rc, mid + 1, ne, l, r, x);
    st[id] = merge(st[lc], st[rc]);
}
 
node query(int id, int ns, int ne, int l, int r){
    if (ns >= l && ne <= r) {
        return st[id];
    }
    pushdown(id, ns, ne);
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    if (r <= mid) return query(lc, ns, mid, l, r);
    if (l > mid) return query(rc, mid + 1, ne, l, r);
    return merge(query(lc, ns, mid, l, r), query(rc, mid + 1, ne, l, r));
}
 
 
void solve() {
    cin >> n >> q;
    cin >> s;
 
    for (int i = 0; i <= 4 * n; i++) 
        lazy[i] = -1;
    s = "#" + s;
    build(1, 1, n);
 
    while (q--) {
        string t;
        cin >> t;
        if (t == "QUERY"){
            int l, r;
            cin >> l >> r;
            node nd = query(1, 1, n, l, r);
            if (nd.flag == false && __builtin_popcount(nd.mask) <= 2) {
                cout << "YES" << endl;
            }else {
                cout << "NO" << endl;
            }   
        }else {
            int l, r;
            char c;
            cin >> l >> r >> c;
            update(1, 1, n, l, r, c);
        }
    }
}   
 
signed main(){
    FAST
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}