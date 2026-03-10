#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(all(v))));
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9+7;

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void nop() {
    cout << -1 << endl;
    return;
}


const ll MAXN = 1e6;

long long fac[MAXN + 1], inv[MAXN + 1];

/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y, long long p) {
    long long res = 1;
    x %= p;
    while (y) {
        if (y & 1) {
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
        y >>= 1;
    }
    return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(long long p) {
    fac[0] = 1;
    for (ll i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
}

/** Precomputes all modular inverse factorials from 0 to MAXN in O(n + log p)
 * time */
void inverses(long long p) {
    inv[MAXN] = exp(fac[MAXN], p - 2, p);
    for (ll i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
}

/** Computes nCr mod p */
long long choose(long long n, long long r, long long p = mod) {
    return fac[n] * inv[r] % p * inv[n - r] % p;
}
void prep(long long p)
{
    factorial(p) ;
    inverses(p) ;
}

void fix(ll& x)
{
    assert(abs(x)<mod) ;
    if(x<0) x+= mod ;
}

ll mul(ll x , ll y)
{
    fix(x) ;
    fix(y) ;
    return x*y % mod ;
}
ll add(ll x , ll y)
{
    fix(x) ;
    fix(y) ;
    return (x+y) % mod ;
}


void solve() {
    int n , m , c ;
    cin>>n>>m>>c ;
    ll nb = exp(c , mul(n , n) , mod) ;
    ll ans = 0 ;
    for(int k = 0 ; k<m ; k++){
        ans = add(ans , exp(nb , __gcd(m , k) , mod)) ;
    }
    cout<<mul(ans , exp(m , mod-2 , mod))<<endl;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}