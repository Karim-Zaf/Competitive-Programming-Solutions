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
    ll n, k , res = 0, cnt = 0 , mn = 0 ; 
    cin >> n >> k ; 
    vi v(n) ;
    priority_queue <ll,vector <ll> , greater<>> pq ;  
    for (ll i= 0 ;i<n ; i++ ){
        cin >> v[i] ; 
        res += v[i] ;
    }
    sort (all(v));
    ll i= 1 , j = n-1 , lef , righ, louta = 0  ; 
    for (ll i = n -1 ,j=0 ; i>=0 && j<k ; i--, j++){
        mn += v[i] ;
        pq.push(v[i]) ;
    }
    ll jdid = mn  ;   
    for (ll i = 1  , j= 0 ; i<n && j<k ;i+=2 ,j++){
        louta += v[i]+v[i-1] ;  
        jdid -= pq.top() ;
        pq.pop() ; 
        mn = min (mn , louta + jdid ) ;
    }
    cout << res -mn << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}