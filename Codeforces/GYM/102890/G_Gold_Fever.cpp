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
const int N_Max = 1e5 + 5;
const int Nax = 1e6 + 7;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
int st[4 * N_Max];
int a[N_Max], b[N_Max], v[N_Max];
 
void update(int id, int ns, int ne, int l, int r, int val){
    if (l > ne || r < ns) return;
    if (ns >= l && ne <= r){
        st[id] = max(st[id], val);
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id + 1;
    int rc = 2 * id + 2;
    update(lc, ns, mid, l, r, val);
    update(rc, mid + 1, ne, l, r, val);
}
 
int query(int id, int ns, int ne, int ind){
    if (ind < ns || ind > ne) return 0;
    if (ns == ne) return st[id];
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id + 1;
    int rc = 2 * id + 2;
    return max({st[id], query(lc, ns, mid, ind), query(rc, mid + 1, ne, ind)});
}
 
void solve(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> v[i] >> a[i] >> b[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++){
        int l = i + a[i], r = min(N, i + b[i]);
        int value = v[i] + query(1, 1, N, i);
        ans = max(ans, value);
        if (l <= N) update(1, 1, N, l, r, value);
    }
    cout << ans << endl;
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