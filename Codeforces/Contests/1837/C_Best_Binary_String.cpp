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

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){  
    string ch ;
    cin >> ch ; 
    int n = ch.size() ; 
    int j = 0 ;
    while (j<n && ch[j]=='?' ) {
        j++ ; 
    }
    if (ch[0]=='?'){
        if ( j== n ) {ch[0] = '0';}
        else ch[0]=ch[j] ; 
    }
    for (int i = 0 ; i<n ; i++ ){
        if ( ch[i] != '?')continue ; 
        if ( i<n-1 && n> 0 ){
            if ( ch[i-1]=='1' && ch[i+1] == '1') {
                ch[i] = '1' ; 
            }   if ( ch[i-1]=='0' && ch[i+1] == '0')
                ch[i] = '0' ; 
        } if ( i>0){
            ch[i] = ch[i-1] ; 
        }
    }
    cout << ch <<endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}