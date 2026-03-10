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

const ll N =1e7+2 , MOD =1e9+7, Q =2e5+3 ; 


void solve (){  
    ll n , sum = 0 , res = INF , ver = 1 ; 
    cin >> n; 
    vi v(n) ; 
    for (ll i= 0 ;i<n ; i++ ) {
        cin >> v[i] ; 
        sum += v[i] ; 
        if (i) ver &= v[i]==v[i-1] ; 
    }
    for (ll i = 1 ; i <=3000 ; i++ ){
        if ( sum % i )continue ; 
        ll cherche = sum / i ; 
        ll j= 0 ,verif = 1 , operation = 0; 
        while (j<n ){
            ll nw_sum = 0 ;
            while (j< n && nw_sum <cherche){
                nw_sum += v[j] ;
                j++ ;  
            }
            if (nw_sum !=cherche){ verif = 0 ; break ; }
        }
        if (verif)res = min (res , n-i);
    }
    cout << res <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;    
    cin >> test_case ; 
    while (test_case--)  solve() ;
}