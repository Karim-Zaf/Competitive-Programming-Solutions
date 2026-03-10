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
    int n ; 
    cin >> n; 
    ll tab[n][n] ;
    tuple<int,int,string> dp[n][n] ; 
    for (int i = 0 ;i<n ; i++ )
        for (int j = 0 ;j<n ; j++ )
            cin >> tab[i][j] ; 

    function <int(int,int)> log_ = [](int n , int b){
        int res = 0 ; 
        while (n%b==0 && n){
            res++ ; 
            n/= b ; 
        }
        return res ; 
    }; 
    for (int i = 0 ;i<n ; i++ ){
        for (int j = 0 ;j<n ; j++ ){
            int deux = log_ (tab[i][j],2) ;
            int cinq = log_ (tab[i][j],5) ;
            if (i==0 && j==0) dp[i][j]= make_tuple (deux,cinq,"") ;
            else if ( i == 0 ) {
                deux += get<0>(dp[i][j-1]) ; 
                cinq+= get<1>(dp[i][j-1]) ;  
                dp[i][j] =make_tuple ( deux, cinq, "") ;
            }else if ( j == 0 ) {
                deux += get<0>(dp[i-1][j]) ; 
                cinq+= get<1>(dp[i-1][j]) ; 
                dp[i][j] =make_tuple ( deux, cinq, "") ;
            } else {
                ll deux_up=get<0>(dp[i-1][j]);
                ll cinq_up=get<1>(dp[i-1][j]);
                ll deux_left=get<0>(dp[i][j-1]);
                ll cinq_left=get<1>(dp[i][j-1]); 
                deux += min(ll(get<0>(dp[i-1][j])),ll(get<0>(dp[i][j-1]))); 
                cinq += min(ll(get<1>(dp[i-1][j])),ll(get<1>(dp[i][j-1]))) ; 
                dp[i][j] =make_tuple ( deux, cinq, "") ;
            }
        }
    }
    if (min ( get<0> (dp[n-1][n-1]) , get<1> (dp[n-1][n-1]) ))
        for (int i = 0 ;i<n ; i++ )
            for (int j = 0 ;j<n ; j++ ) 
                if ( tab[i][j]==0){
                    cout << "1\n" ; 
                    for (int ii = 0; ii< i ; ii++ )cout << "D";
                    for (int jj = 0; jj< n-1 ; jj++ )cout << "R";
                    for (int ii = i+1;ii< n ; ii++ )cout << "D";
                    return; 
                }

    if ( get<0> (dp[n-1][n-1]) <= get<1> (dp[n-1][n-1]) ){
        cout << get<0>(dp[n-1][n-1])<<endl; 
        int i = n-1 , j = n-1 ; 
        string res = ""; 
        while ( i!= 0 || j != 0 ){
            if ( i == 0 ) {
                res= "R"+res ; 
                j-- ; 
            }else if ( j == 0 ){
                res= "D"+res ; 
                i-- ; 
            }else{
                int deux = log_ (tab[i][j],2) ;
                int deux_up=get<0>(dp[i-1][j]);
                int deux_left=get<0>(dp[i][j-1]);
                if ( deux_up + deux == get<0> (dp[i][j])){
                    res= "D"+res ; 
                    i-- ; 
                } else {
                    res= "R"+res ; 
                    j-- ; 
                }
            }
        }
        cout << res <<endl;
    }  else {
        cout << get<1>(dp[n-1][n-1])<<endl; 
        int i = n-1 , j = n-1 ; 
        string res = ""; 
        while ( i!= 0 || j != 0 ){
            if ( i == 0 ) {
                res= "R"+res ; 
                j-- ; 
            }else if ( j == 0 ){
                res= "D"+res ; 
                i-- ; 
            }else{
                int cinq = log_ (tab[i][j],5) ;
                int cinq_up=get<1>(dp[i-1][j]);
                int cinq_left=get<1>(dp[i][j-1]);
                if ( cinq_up + cinq == get<1> (dp[i][j])){
                    res= "D"+res ; 
                    i-- ; 
                } else {
                    res= "R"+res ; 
                    j-- ; 
                }
            }
        }
        cout << res <<endl;
    }

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}