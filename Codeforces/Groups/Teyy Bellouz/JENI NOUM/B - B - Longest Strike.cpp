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
    ll n, k , l = 0, r=0; 
    cin >> n >> k ; 
    map <ll ,ll> mp ; 
    vi v(n) ;
    vector <pair <ll,ll>> nw ;  
    for( ll i= 0; i<n ; i++){
        cin >> v[i] ; 
        mp[v[i]]++ ; 
    }
    // kar ( v) ; 
    for (auto s : mp){
        nw.pb(make_pair(s.F,s.S)) ;
    }
    // kar ( nw ) ;
    ll i = 0 ; 
    while ( i <nw.size() ){
        ll pot_l = nw[i].F ;
        if ( nw[i].S>=k) {
            i++ ; 
            while (i <nw.size() && nw[i].S >= k && nw[i].F-nw[i-1].F==1) i++ ;
            ll pot_r = nw[i-1].F ; 
            // kar (make_pair (pot_l,pot_r))
            if ( pot_r -pot_l >= r-l){
                r = pot_r ; l = pot_l ; 
            }
        } 
        else i ++ ; 
    }
    if ( l == 0 ) cout << - 1 <<endl;
    else  cout << l << " "<< r <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}