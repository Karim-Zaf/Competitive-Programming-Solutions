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

const ll N = 1e6+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){
    int m , n ; 
    cin >> m >> n; 
    string mx;
    map <string ,int > mp ; 
    for (int i =0  ;i<m ;i++){
        string x ; cin >> x ;
        int idx = -1 ; 
        for (int j=0 ;j<n ;j++ )
            if (x[j]=='*')
                idx = j ; 
        for (char c= 'a' ; c<='z'; c++ ){
            string nw = x ; 
            nw [idx]= c ; 
            mp[nw]++ ;
            mx = nw ; 
        }
    }
    for(auto x : mp){
        if (mp[mx]==x.S && x.F<mx)
            mx= x.F;
        if (mp[mx]<x.S)
            mx= x.F;
    }
    cout << mx << " " << mp[mx] <<endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}