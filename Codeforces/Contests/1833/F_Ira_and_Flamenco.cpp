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
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define MOD mod
#define INF (ll)(1e18)

const ll N = 2e5+5 , MOD =1e9+7, Q =2e5+3 ;

ll fact [N] ; 

ll binpow(ll a, ll b){
    if(b == 0)return 1;
    ll x = binpow(a, b/2) % MOD;
    ll g = x*x;
    g %= MOD;
    if(b%2 == 0)return g;
    g*=a;
    g%=MOD;
    return g;
}
 
 
ll modinv(ll a){ return binpow(a, MOD-2); }

void solve (){
    int n , m , lef = 0 , x , r= 0   ; 
    long long res = 0 ; 
    cin >> n>> m ;
    map<int , int >  mp ; 
    vector <int> v; 
    for (int i= 0 ;i<n ; i++ ){
        cin >> x ;
        if (! mp[x])
            v.pb( x ) ; 
        mp[x] ++ ;  
    } 
    n = v.size() ; 
    vector <long long> pref ( n ,1) ; 
    sort (all( v) ) ; 

    function <long long (long long , long long  )> Comb = [] (ll p  , ll n )  {
        return  fact[n] *modinv (fact[n-p]) %mod * modinv (fact[p]) % mod ; 
    }; 
    pref[0] = mp[v[0]] ; 
    for (int i= 1 ; i<n ; i++ )
        pref[i] = pref[i-1] * mp[v[i]] % mod ; 
    while ( r < n ) {
        lef = lower_bound (all (v) , v[r]-m+1)  - v.begin() ;
        while ( r+1 < n && lef == lower_bound (all (v) , v[r+1]-m+1)  - v.begin() )r++ ; 

        if ( r-lef+1 >= m  ){
            res += pref[r]* modinv ( lef == 0 ? 1 : pref[lef-1] )%mod *Comb( m , r-lef+1 ) ; 
            res %= mod ;  
        }
        r++ ; 
    }
    cout << res <<endl;

}

void preprocess ( ) {
    fact [0] = 1 ; 
    for (int i = 1 ; i < N ; i++ )
        fact [i] = (fact [i-1] * i % mod ) ; 
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    preprocess ()  ;
    while (test_case--)  solve() ;
}