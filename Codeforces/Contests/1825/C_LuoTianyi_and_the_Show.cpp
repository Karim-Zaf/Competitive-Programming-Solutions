

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
    ll n , m ,x ,  lef = 0 , righ = 0 , res = -INF; 
    cin >> n >> m; 
    vi v  ;
    map<ll,ll> mp ; 
    for (ll i= 0;i<n ; i++){
        cin>> x ; 
        if ( x == -1 )lef ++ ; 
        else if ( x== -2 ) righ ++ ;
        else if (!mp[x]) v.pb(x ) ; 
        mp[x]++ ; 
    }
    sort(all(v)) ; 
    res = max ( min ( lef , m ) , min (righ ,m )) ; 
    for (ll i= 0;i<v.size() ; i++){
        ll dispo_lef = v[i]-1 - i ;
        ll dispo_righ = m-v[i]-(v.size() - i-1) ;
        dispo_righ = max (0ll, dispo_righ); 
        dispo_lef = max (0ll, dispo_lef); 
        ll dispo = dispo_righ + dispo_lef ;
        res = max ( res , min (righ,dispo)+ (ll)(v.size()));
        res = max ( res , min (lef, dispo)+ (ll)(v.size()));
        res = max ( res , min ( lef , dispo_lef ) + min ( righ , dispo_righ)+ (ll)(v.size()));
    }
    cout << min (res ,m) << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}