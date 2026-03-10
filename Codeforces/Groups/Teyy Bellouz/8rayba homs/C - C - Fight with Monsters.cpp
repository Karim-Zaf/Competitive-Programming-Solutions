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
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){   
    ll a , b , n  , h , hprime  , k , kk ,  res = 0, s = 0 ; 
    cin >> n >> a >> b >> kk ; 
    vi v(n), nw ; 
    k= kk ; 
    for (ll i= 0 ;i<n ; i++ ) cin >> v[i] ; 
    for (ll i= 0 ;i<n ; i++ ) {
        h = v[i]/(a+b) + (v[i]%(a+b)? 1:0) ;  
        hprime = (v[i]-a) /(a+b) + ((v[i]-a)%(a+b)? 1:0) ;
        ll one = (hprime +1)*a + hprime * b ;
        ll two = h*a + h * b ;
        ll jdid =  (v[i]-two+b)/a + ((v[i]-two+b)%a?1 : 0) ; 
        if ( one <= two  ||  v[i]<=a )  res++ ; 
        else nw.pb( jdid );  
    }
    sort (all(nw)) ;
    ll i= 0 , add =0 ;
    while ( add +nw[i] <= k && i < nw.size() ){
        add+= nw[i];
        res++ ; 
        i++ ; 
    }
    cout << res  <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}