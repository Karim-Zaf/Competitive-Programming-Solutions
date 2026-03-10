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
 
template<class T> struct Seg{
    const T ID = 0; ll n; vector<T> seg;
    T comb(T a, T b) {return  (a + b) % mod;}
    void init(ll _n) {n = _n; seg.assign(2 * n, ID);}
    void pull(ll p) {seg[p] = comb(seg[2 * p], seg[2 * p + 1]);}
    void upd(ll p, T val){seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p);}
    T query(ll l, ll r){
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};
 
int add(int a, int b){return (a + 0LL + b) % mod;}
 
int sub(int a, int b){return (a - b + 0LL + mod) % mod;}
 
int mult(int a, int b){return a * 1LL * b % mod;}
 
int divide(int a, int b){return a * 1LL * inv(b) % mod;}
 
vector<int> divisors[N_Max];
Seg<ll> st;
 
void solve(){
    int N;
    cin >> N;
    vector<int> a(N + 1), dp(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= N; i++){
        dp[i] = add(1, st.query(0, a[i] - 1));
        for (int d : divisors[i])
            if (a[d] < a[i]) dp[i] = sub(dp[i], dp[d]);
        ans = add(ans, dp[i]);
        st.upd(a[i], add(st.query(a[i], a[i]), dp[i]));
    }
    cout << ans << endl;
    for (int i = 1; i <= N; i++) st.upd(a[i], 0);
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    st.init(N_Max);
    for (int i = 1; i < N_Max; i++)
        for (int j = 2 * i; j < N_Max; j += i)
            divisors[j].pb(i);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}