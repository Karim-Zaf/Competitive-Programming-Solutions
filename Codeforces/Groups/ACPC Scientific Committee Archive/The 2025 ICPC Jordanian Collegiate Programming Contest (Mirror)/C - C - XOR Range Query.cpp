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
 
struct tnode {
    int pri;
    ll val;
    ll v;
    int sz;
    tnode* c[2];
    tnode(ll x) {
        pri = rand();
        val = x;
        v = x;
        sz = 1;
        c[0] = c[1] = NULL;
    }
};
using pt = struct tnode*;
 
int getsz(pt root) {
    if (!root) return 0;
    return root->sz;
}
 
void updsz(pt root) {
    if (!root) return;
    root->sz = 1 + getsz(root->c[0]) + getsz(root->c[1]);
}
 
ll getv(pt root) {
    if (!root) return 0;
    return root->v;
}
 
void updv(pt root) {
    if (!root) return;
    root->v = root->val ^ getv(root->c[0]) ^ getv(root->c[1]);
}
 
pair<pt, pt> split(pt root, int sz) {
    if (!root) return {root, root};
    if (getsz(root->c[0]) >= sz) {
        auto pi = split(root->c[0], sz);
        root->c[0] = pi.second;
        updsz(root);
        updv(root);
        return {pi.first, root};
    }
    auto pi = split(root->c[1], sz - getsz(root->c[0]) - 1);
    root->c[1] = pi.first;
    updsz(root);
    updv(root);
    return {root, pi.second};
}
 
pt merge(pt l, pt r) {
    if (!l) return r;
    if (!r) return l;
    if (l->pri > r->pri) {
        l->c[1] = merge(l->c[1], r);
        updsz(l);
        updv(l);
        return l;
    } 
    r->c[0] = merge(l, r->c[0]);
    updsz(r);
    updv(r);
    return r;
}
 
pt ins(pt root, ll x, int idx) {
    auto pi = split(root, idx - 1);
    return merge(merge(pi.first, new tnode(x)), pi.second);
}
 
pt rmv(pt root, int idx) {
    auto pi1 = split(root, idx);
    auto pi2 = split(pi1.first, idx - 1);
    return merge(pi2.first, pi1.second);
}
 
ll get(pt &root, int l, int r) {
    auto pi1 = split(root, r);
    auto pi2 = split(pi1.first, l - 1);
    ll ret = getv(pi2.second);
    root = merge(pi2.first, merge(pi2.second, pi1.second));
    return ret; 
}
 
void solve() {
    int n;
    cin >> n;
    
    pt root = NULL;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        root = merge(root, new tnode(x));
    }
 
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1){
            int idx;
            ll x;
            cin >> idx >> x;
            root = ins(root, x, idx);
        }else if(t == 2) {
            int idx;
            cin >> idx;
            root = rmv(root, idx);
        }else {
            int l, r;
            cin >> l >> r;
            cout << get(root, l, r) << endl;
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
    // cin >> t;
    while(t--)
        solve();
    return 0;
}