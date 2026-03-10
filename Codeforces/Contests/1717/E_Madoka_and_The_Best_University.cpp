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

const ll N = 1e5 + 5 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

vector<ll> phi ;

void phi_1_to_n(ll n = N) {
    phi.resize(n+1 ) ;
    phi[0] = 0;
    phi[1] = 1;
    for (ll i = 2; i <= n; i++)
        phi[i] = i-1 ;
 
    for (ll i = 2; i <= n; i++)
        for (ll j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}

void solve(){
    ll n ; 
    phi_1_to_n(N);
    long long res = 0 ;
    cin >> n ;
    vector<vector<int>> divisors(n+1) ; 
    for (int i= 1 ; i<=n ;i++)
        for (int j= 2*i ; j<=n ;j+=i)
            divisors[j].pb(i);

    function <ll(ll,ll)> lcm = [](ll a, ll b ){return b / __gcd(a,b) %MOD * a % MOD ; };

    for (ll c= 1 ; c<= n-2  ; c++){
        for (auto d : divisors[n-c]){
            res += lcm(c,d) * phi[(n-c)/d] %MOD;
            res %= MOD ;
        }
    }
    cout << res <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}