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
const int N_Max = 1e6 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

ll st[4 * N_Max];
ll a[N_Max];
int N, Q;

ll merge(ll l, ll r){
    return l ^ r;
}

void build(int id, int ns, int ne){
    if (ns == ne){
        st[id] = a[ns];
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    build(lc, ns, mid);
    build(rc, mid + 1, ne);
    st[id] = merge(st[lc], st[rc]);
}

void update(int id, int ns, int ne, int p, ll x){
    if (p < ns || p > ne) return;
    if (ns == ne){
        st[id] = x;
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    update(lc, ns, mid, p, x);
    update(rc, mid + 1, ne, p, x);
    st[id] = merge(st[lc], st[rc]);
}

ll query(int id, int ns, int ne, int l, int r){
    if (ns > r || ne < l) return 0;
    if (ns >= l && ne <= r) return st[id];
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    return merge(query(lc, ns, mid, l, r), query(rc, mid + 1, ne, l, r));
}

void solve(){
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    build(1, 1, N);
    for (int q = 1; q <= Q; q++){
        char type;
        cin >> type;
        if (type == 'P'){
            int l, r;
            cin >> l >> r;
            int xr = query(1, 1, N, l, r);
            cout << (xr > 0 ? "FRANK" : "JUAN") << endl;
            continue;
        }
        int k, x;
        cin >> k >> x;
        a[k] += x;
        update(1, 1, N, k, max(0LL, a[k]));
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