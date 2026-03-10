/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)   
#endif
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 1e7 + 5 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;


vector <ll> spf (N,1), primes;

vector <ll> sieve(ll n ){
    vector <ll> prime ;
    for (ll i=1 ; i<n ; i++ ) spf[i]= i ; 
    for  (ll i =2 ; i<=n ; i++){
            if (spf[i]==i ){ 
            prime.pb ( i);
            for ( ll j=i ; j<=n ; j+=i)
                spf[j]=min(ll(spf[i]), ll(i) );
        }
    }
    return prime ;
}

vector<pair<ll,ll>> factors(ll n){
    vector<pair<ll,ll>> res;
    for(ll i = 0; i < primes.size() && primes[i]*primes[i] <= n;i++){
        if(n % primes[i])continue;
        ll cnt = 0 ;
        while(n % primes[i] == 0){
            n /= primes[i];
            cnt ++ ;
        }
        res.pb({primes[i],cnt});
    }
    if(n > 1)res.pb({n,1});
    return res;
}


ll phi(ll n) {
    vector<pair<ll, ll>>divisors = factors(n); 
    //pairs {prime number, exponent}
    
    ll ans = 1;
    for(auto [prime, exp] : divisors) {
    ll power = 1;
        for (ll i = 1; i<exp; i++){
            power *= prime;
    }   
    ans *= (power * prime - power); // (p^exp - p^{exp-1})
    }
    return ans;
}


void solve() {
    long long a , m ; 
    cin >> a >> m; 
    cout << phi(m/__gcd(a,m)) <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    primes = sieve (1e7);
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}