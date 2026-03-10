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
    ll n, mn  = -INF; 
    cin >> n; 
    vector <int> v(10);
    vector <pair <ll,ll>> vp;  
    for (ll i= 1 ; i<=9 ; i++) {
        cin >> v[i];
        vp.pb({v[i],i}) ;
    }
    sort (all(vp));
    ll length_min = n / (vp[0].F) ;
    if ( length_min == 0 ){cout << -1 <<endl; return ; }
    pi p = make_pair (vp[0].F +1 ,0) ; 
    ll pos = lower_bound ( all(vp) , p ) -vp.begin() ;
    pos -- ; 
    kar ( vp ) 
    string res = "" ; 
    for (ll i = 0 ; i< length_min ; i++ ) res+= (vp[pos].S+'0');
    ll cost = vp[0].F * int ( length_min) ; 
    kar (cost)  ; 
    for (ll i= 0 ;i< length_min ; i++){
        cost -= vp[0].F ; 
        ll reste = n - cost ;
        pi best = vp[0] ; 
        for (ll j = 0 ; j <9 ; j++){
            if ( vp[j].S > best.S && vp[j].F <= reste )
                best= vp[j];
        }
        res [i] = (best.S + '0') ;
        cost += best.F ; 
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