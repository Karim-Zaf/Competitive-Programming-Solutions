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

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

vector <int> spf (N,1), primes;

// vector <ll> sieve(int n ){
//     vi vs(n+1,0), pri ;
//     for  (int i =2 ; i<=n ; i++){
//         if (!vs[i]){
//             pri.pb ( i);
//             for ( int j=i ; j<=n ; j+=i)
//                 vs[j]=1;
//         }
//     }
//     return pri ;
// }

vector <int> sieve(int n ){
    vector <int> prime ;
    for (int i=1 ; i<n ; i++ ) spf[i]= i ; 
    for  (int i =2 ; i<=n ; i++){
            if (spf[i]==i ){ 
            prime.pb ( i);
            for ( int j=i ; j<=n ; j+=i)
                spf[j]=min(ll(spf[i]), ll(i) );
        }
    }
    return prime ;
}

vector<int> factors(int n){
    vector<int> res  ; 
    set <int> temp ; 
    while (  n > 1 ) {
        temp.insert(spf[n]) ; 
        n/= spf[n] ; 
    }
    for (int val : temp ) res.pb(val) ; 
    return res ; 
}


void solve (){
    int n , x ; 
    cin >> n ;
    primes = sieve(N) ;  
    vector<ll> res_one , res_two ; 
    while (n--){
        cin >> x ;
        vector <int> f  = factors  ( x) ;
        if (f.size()< 2 ) {
            res_one.pb(-1);
            res_two.pb(-1); 
        }else if ( x%2 ){
            res_one.pb(f[0]);
            res_two.pb(f[1]);
        }else{
            res_one.pb(f[0]);
            ll add = 1 ; 
            for (int i = 1 ; i<f.size() ; i++) add *= f[i] ; 
            res_two.pb(add) ; 
        }
    }
    for (ll val : res_one ) cout << val << " " ;cout <<endl; 
    for (ll val : res_two ) cout << val << " " ;cout <<endl; 
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}