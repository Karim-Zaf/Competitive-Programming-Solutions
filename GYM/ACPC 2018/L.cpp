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

ll st[4 * N_Max], lazy[4 * N_Max];
int parity[4 * N_Max];
int Q, q;

void build(int id, int ns, int ne){
    lazy[id] = 1e15;
    parity[id] = 0;
    if (ns == ne){
        st[id] = ns;
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    build(lc, ns, mid);
    build(rc, mid + 1, ne);
}

void pushdown(int id, int ns, int ne){
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    if (lazy[id] == 1e15) return;
    if (!parity[id]){
        st[lc] = lazy[id] + st[lc];
        if (lazy[lc] == 1e15) lazy[lc] = lazy[id];
        else lazy[lc] = lazy[id] + lazy[lc];
        st[rc] = lazy[id] + st[rc];
        if (lazy[rc] == 1e15) lazy[rc] = lazy[id];
        else lazy[rc] = lazy[id] + lazy[rc];
    }
    else{
        st[lc] = lazy[id] - st[lc];
        if (lazy[lc] == 1e15) lazy[lc] = lazy[id];
        else lazy[lc] = lazy[id] - lazy[lc];
        st[rc] = lazy[id] - st[rc];
        if (lazy[rc] == 1e15) lazy[rc] = lazy[id];
        else lazy[rc] = lazy[id] - lazy[rc];
    }
    parity[lc] ^= parity[id];
    parity[rc] ^= parity[id];
    lazy[id] = 1e15;
    parity[id] = 0;
}

void update(int id, int ns, int ne, int l, int r, ll x){
    if (ns > r || ne < l) return;
    if (ns >= l && ne <= r){
        st[id] = x - st[id];
        if (lazy[id] < 1e15){
            lazy[id] = x - lazy[id], parity[id] ^= 1;
        }
        else lazy[id] = x, parity[id] = 1;
        return;
    }
    pushdown(id, ns, ne);
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    update(lc, ns, mid, l, r, x);
    update(rc, mid + 1, ne, l, r, x);
}

ll query(int id, int ns, int ne, int ind){
    if (ns == ne) return st[id];
    pushdown(id, ns, ne);
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    if (ind <= mid) return query(lc, ns, mid, ind);
    return query(rc, mid + 1, ne, ind);
}

void solve(){
    cin >> Q;
    build(1, 0, 1e5);
    for (q = 1; q <= Q; q++){
        int x;
        cin >> x;
        ll y = query(1, 0, 1e5, x);
        update(1, 0, 1e5, x, 1e5, 2 * y);
        cout << y << endl;
    }
}

int main(){
    FAST
    freopen("reflection.in","r",stdin);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}
