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
#define dbg(...)  
#define watch(...)  
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
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)

const ll N = 1e7+2 , MOD =1e9+7, Q =2e5+3 ; 

ll binpow(ll a, ll b){
    if(b == 0)return 1;
    ll x = binpow(a, b/2);
    ll g = x*x;
    // g %= MOD;
    if(b%2 == 0)return g;
    g*=a;
    // g%=MOD;
    return g;
}
 
void solve(){ 
    ll n ,res = INF, sum = 0 ; cin >> n; 
    vi v(n ) ; 
    for (ll i= 0 ;i<n ; i++){
        cin >> v[i] ; 
        sum += v[i] ;
    }
    sort (all( v) ) ;
    ll mx = v.back() ;
    for (ll k = 1 ; k<= 3e5 ; k++){
        ll dhareb = 1  , curr = 0 , ok = 0 ;
        for( ll i= 0 ;i<n ; i++ ){
            // kar (dhareb)    ;
            curr += abs ( v[i] - dhareb) ;
            if ( abs (dhareb-v[i])>=sum) { ok = 1; break;}
            dhareb *= k ; 
        }
        if (ok )break;
        // kar (curr);
        res = min ( res , curr) ;
    }
    cout << res <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;    
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}