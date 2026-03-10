

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

const ll N = 1ll<<27 , MOD =1e9+7, Q =2e5+3 ; 
map<ll,ll> mp ; 

vi tab  ;

void solve (){ 
    ll n , l , r , res = 0  ; 
    cin >> n;  
    ll pos = upper_bound (all (tab ) , n ) - tab.begin () ;
    pos -- ;
    l = n- tab[pos]; r= n- tab[pos];
    for (ll i= pos ; i>=0 ; i--){ 
        ll lef = tab[i]+l -1 ; 
        ll righ = tab[i]+r; 
        ll curr  = (  (righ*(righ+1)*(2*righ+1)/6) -  (lef*(lef+1)*(2*lef+1)/6) ) ; 
        res += curr ; 
        l = max (0ll , l-1) ; 
        r = min ( i-2 , r) ;
    }
    cout << res <<endl;
}

void preprocess () {
    ll cnt = 1 ;
    tab.pb(-1);
    for (ll i= 0; i<2025 ; i++){
        cnt+= i ; 
        tab.pb(cnt);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;    
    preprocess() ; 
    cin >> test_case ; 
    while (test_case--)  solve() ;
}