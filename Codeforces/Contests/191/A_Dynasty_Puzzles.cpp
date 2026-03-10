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
    int  n  ; 
    cin >> n ;
    vector <string> v (n) ; 
    for (int i=  0;i<n ; i++ ) cin >> v[i] ; 
    long long dp [26][26],res = 0;
    for (int j= 0; j<26 ; j++)
        for (int k= 0; k<26 ; k++)
            dp[k][j]= 0 ;
    dp[v[0][0]-'a'][v[0].back()-'a'] = v[0].size() ;
    for (int i = 1;i<n ; i++ ){
        int back = v[i].back() -'a' , front = v[i][0]-'a'; 
        for (int j = 0 ;j<26 ;j++)
            if (dp[j][front])
                dp[j][back] = max (dp[j][back],dp[j][front]+ll(v[i].size()));
        dp[front][back] =  max (dp[front][back], ll (v[i].size())) ;
    }
    for (int j = 0 ;j<26 ; j++)
        res = max ( res , dp[j][j]) ;

    cout << res <<endl;

}



int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}