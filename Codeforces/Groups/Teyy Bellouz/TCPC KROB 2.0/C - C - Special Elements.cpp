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

const ll N = 2e5+5 , MOD =1e9+7, Q =2e5+3 ;



void solve (){
    int n ,res = 0 ; 
    cin >> n; 
    vector <int>  v( n +1) , pref(n+1,0) , mp (8001,0)  ;
    for (int i = 1 ;i<=n ; i++ ) 
        cin >> v[i] ;   
    for (int i= 1 ;i<=n ; i++)
        pref[i] = pref[i-1] + v[i] ; 
    for (int i = 2 ;i<=n ; i++ )
        for (int j = 0 ; j<i-1 ; j++ )
            if (pref[i]-pref[j]<=8000)
                mp[pref[i]-pref[j]]= 1 ; 
    for (int i = 1 ; i<=n ; i++ )
        res += mp[v[i]] ;      
    cout <<res <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}