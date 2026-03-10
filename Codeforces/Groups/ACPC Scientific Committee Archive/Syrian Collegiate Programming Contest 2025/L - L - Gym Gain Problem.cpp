#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz(a) (a).size()
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
const ll mod = 167772161;
const int N_Max = 2e6 + 5;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
typedef complex<double> C;
 
void fft(vector<C> &a) {
    int n = (int)a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        for(int i = k; i < 2 * k ; ++i) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vector<int> rev(n);
    for(int i = 0 ; i < n ; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for(int i = 0; i < n ; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) for(int j = 0 ; j < k ; ++j) {
                auto x = (double *)&rt[j + k],
                     y = (double *)&a[i + j + k];  
                C z(x[0] * y[0] - x[1] * y[1],
                    x[0] * y[1] + x[1] * y[0]);  
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
}
 
template <int M> vector<ll> convMod(const vector<ll> &a, const vector<ll> &b) {
    if (a.empty() || b.empty()) return {};
    vector<ll> res(sz(a) + sz(b) - 1);
    int B = 32 - __builtin_clz(sz(res)), n = 1 << B, cut = int(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    for(int i = 0 ; i < sz(a) ; ++i) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    for(int i = 0 ; i < sz(b) ; ++i) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    for(int i = 0 ; i < n ; ++i) {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    for(int i = 0 ; i < sz(res) ; ++i) {
        ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
        ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}
 
int invfact[N_Max];
int fact[N_Max];
 
int add(ll a, ll b){return (a % mod + b % mod) % mod;}
 
int sub(ll a, ll b){return (a % mod - b % mod + mod) % mod;}
 
int mult(ll a, ll b){return (a % mod) * (b % mod) % mod;}
 
int divide(ll a, ll b){return (a % mod) * inv(b) % mod;}
 
int Comb(int N, int K){
    if (N < K) return 0;
    return mult(fact[N], mult(invfact[K], invfact[N - K]));
}
 
void prep(){
    fact[0] = 1;
    for (int i = 1; i < N_Max; i++) fact[i] = mult(fact[i - 1], i);
    invfact[N_Max - 1] = inv(fact[N_Max - 1]);
    for (int i = N_Max - 2; i >= 0; i--) invfact[i] = mult(i + 1, invfact[i + 1]);
}
 
void solve(){
    int N, K, M;
    cin >> N >> K >> M;
    vector<ll> a(N), d(N), ans(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < K; i++){
        vector<ll> vec;
        for (int j = i; j < N; j += K) vec.pb(a[j]);
        int len = (int)vec.size();
        vector<ll> d(len);
        for (int j = 0; j < len; j++) d[j] = Comb(M - 1 + j, j);
        vector<ll> res = convMod<mod>(vec, d);
        int ind = 0;
        for (int j = i; j < N; j += K, ind++)
            ans[j] = res[ind];
    }
    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    prep();
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}