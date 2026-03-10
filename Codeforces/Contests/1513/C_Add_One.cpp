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
long long dp[N][10][10] ;

void solve (){
    long long n , m ,res = 0 ;  
    cin >> n >> m ;
    string ch = to_string (n) ;
    for (int i = 0 ;i<ch.size() ; i++) {
        int curr = ch[i]-'0' ;
        for (int j = 0 ;j<= 9 ;j++){
            res += dp[m][curr][j];
            res %= mod ; 
        }
    }
    cout << res << endl;
}

void preprocess(){
    for (int j = 0 ;j<=9 ; j++) 
        for (int i = 0 ;i<=9 ; i++) 
            dp[0][j][i] =0 ;

    for (int i = 0 ;i<=9 ; i++) 
        dp[0][i][i] =1  ;

    for (int s = 0 ;s<=9 ; s++){ 
        for (int i = 1 ;i< N ; i++ ){
            for (int j = 1 ;j<= 9 ; j++)
                dp[i][s][j] = dp[i-1][s][j-1];
            dp[i][s][0]=dp[i-1][s][9];
            dp[i][s][1]=(dp[i][s][1] + dp[i-1][s][9]);
            dp[i][s][1]%= mod ;
        }
    }
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    preprocess () ;
    cin >> test_case ; 
    while (test_case--)  solve() ;
}