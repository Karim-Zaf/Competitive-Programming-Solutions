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
const ll mod = 998244353;
 
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
 
ll get(ll n){
    vector<ll> primes ;
    ll m = n ;
    for(ll i = 2 ; i*i<=n ; i++){
        ll c = 0 ; while(n%i==0){++c ; n/=i ;} ;
        if(c) primes.pb(i) ;
    }
    if(n>1) primes.pb(n) ;
    ll sz = primes.size() ;
    ll ret = 0 ;
    for(ll i = 0 ; i<(1<<sz) ; i++){
        ll val = 1 , y = 1 ;
        for(ll j = 0 ; j<sz ; j++) if((1<<j) & i) val*= primes[j] , y*=-1 ;
        ret += m/val * y ;
    }
    return ret ;
}
 
 
 
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
 
 
ll a , b , m ;
map<int,int> tab ;
void gen(ll val , ll mask , ll p2){
    if(p2==(1<<15)){
        tab[val] = mask ;
        return ;
    }
    gen(val , mask , p2*2) ;
    ll nval = val * exp(a , p2 , m) % m;
    gen(nval , mask | p2 , p2*2) ;
}
ll phi ;
ll ans = -1 ;
void gengen(ll val , ll mask , ll p2){
    if(ans!=-1) return ;
    if(p2==(1<<30)){
        ll needed = b * exp(val , phi-1 , m) % m ;
        if(tab.count(needed)){
            ans = mask | tab[needed] ;
        }
        return ;
    }
    gengen(val , mask , p2*2) ;
    ll nval = val * exp(a , p2 , m) % m ;
    gengen(nval , mask | p2 , p2*2) ;
}
 
void solve() {
    cin>>a>>b>>m ;
    tab.clear() ;
    phi = get(m) ;
    ans = -1 ;
    gen(1 , 0 , 1) ;
    gengen(1 , 0 , 1<<15) ;
    cout<<ans<<endl;
    assert(exp(a , ans , m) == b) ;
 
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
    ll tt = 1;
    cin>>tt ;
    while (tt--) {
        solve();
    }
 
    return 0;
}