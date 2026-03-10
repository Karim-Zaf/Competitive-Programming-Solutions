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
    ll n , m , consec =  0 , res = 0 ; 
    cin >> n >> m ; 
    ll t [m+1][n+1], pos[m+1][n+1] ; 
    for (ll  i = 1 ; i<=m ; i ++ )
        for( ll j = 1 ; j<= n  ; j ++ ){
            cin >> t[i][j] ; 
            pos [i][t[i][j]] = j  ; 
        }
    for (ll  j = 2 ; j<= n ;j ++ ){
        bool verif = true ; 
        for (ll  i = 2 ; i<= m ; i++){
            if ( pos[i][t[1][j-1]]!=pos[i][t[1][j]]-1)
                verif = false ;
        }
        if (verif && !consec) consec = 2 ; 
        else if ( verif ) consec++;
        else {
            res += (consec*(consec-1)/2 );
            consec = 0 ;
        }
    }
    res += (consec*(consec-1)/2 );
    cout << res+ n <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}