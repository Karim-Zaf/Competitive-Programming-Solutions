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

const ll N = 1e5 + 1 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

int k ; 

vector <int> primes; 

void sieve(){
    vector <int> visited(N) ;
    for  (int i =2 ; i<N ; i++){
        if (visited[i]) continue;
        primes.pb(i) ;
        for ( int j=i ; j<N ; j+=i)
            visited[j]=1;
    }
}

pair<ll,ll> factors(int n){
    ll res = 1 , opp = 1 ;
    for(int i = 0; i < primes.size() && primes[i]*primes[i] <= n;i++){
        if(n % primes[i]) continue;
        ll add =1 ,cmpt =0 ;
        while(n % primes[i] == 0){
            n /= primes[i];
            add *= primes[i] ;
            cmpt ++;
            cmpt %= k ;
            if (cmpt==0) add = 1 ;
        }
        for (int j =0 ; j< ((k- cmpt)%k + k)%k ;j++)
            opp *= primes [i];
        res *= add ;
    }
    if(n > 1){
        res *= n ;
        for (int j = 1 ; j< k ; j++)
            opp*= n ;
    }
    return make_pair(res,opp);
}

void solve(){
    sieve ();
    int n ; 
    long long res = 0 ;
    cin>> n >> k  ;
    map <ll ,ll >  curr;
    vector <int> v(n) ,fact(n) ;
    for (int i= 0 ;i<n ;i++){
        cin >> v[i] ; 
        pair <ll,ll> p = factors(v[i]);
        res += curr[p.S] ;
        if (p.S == 1 ) {curr[1]++ ; if (p.F == 1 ) continue ;}
        curr [p.F]++;
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