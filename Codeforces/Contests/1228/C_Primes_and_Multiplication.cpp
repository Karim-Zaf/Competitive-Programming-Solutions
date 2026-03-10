#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
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
const int N_Max = 1e9 + 5;
const int Nax = 1e7 + 7;
const int LOG = 18;
const int BITS = 30;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<int, int> p){cout << p.F << " " << p.S << endl;}
void dbgpi(vector<pair<int, int>> v){for (auto x : v) dbgg(x);}

ll spf[Nax];
vector<ll> primes;

void sieve(){
    for (int i = 2; i * i < N_Max; i++){
        if (spf[i] == 0){
            primes.pb(i);
            for (int j = i + i; j * j < N_Max; j += i)
                spf[j]++;
        }
    }
}

vector<ll> factorize(ll N){
    vector<ll> ret;
    for (ll prime : primes){
        if (prime * prime > N)
            break;
        if (N % prime != 0)
            continue;
        ret.pb(prime);
        while (N % prime == 0)
            N /= prime;
    }
    if (N > 1)
        ret.pb(N);
    return ret;
}

ll binpow(ll a, ll b){
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll x, N;
    cin >> x >> N;
    vector<ll> a = factorize(x);
    ll ans = 1;
    for (ll prime : a){
        ll cnt = 0;
        for (ll i = prime; i <= N; i *= prime){
            cnt = (cnt + N / i) % (mod - 1);
            if (i > N / prime)
                break;
        }
        // cout << cnt << endl;
        ans = ans * binpow(prime, cnt) % mod;
    }
    cout << ans << endl;
}  

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    sieve();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
a + b = a ^ b + 2 * (a & b)
THINK ABOUT : dp, bs, st, pf, bitmask, dfs, mo, two pollers
Think outside the box
int overflow
check initialization of the answer
check corner cases(small values)
stay focused ans organized
*/
