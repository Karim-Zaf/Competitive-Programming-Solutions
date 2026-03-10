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
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'

const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;

long long  dp[5003][5003] ;

void solve (){
    int n, a , b , k ;
    ll ans = 0 ;
    cin >> n >> a >> b >> k ; 
    dp[0][a]= 1 ; 
    for (int i = 0 ;i<=k ;i++){
        for (int j= 1 ; j<= n ; j++){
            int l = max ( 1 , j - abs(j-b)+1 ) , r = min (n , j+ abs(j-b)-1);
            dp[i+1][l]+= dp[i][j] ;
            dp[i+1][j]%=mod ;
            dp[i+1][j]-= dp[i][j] ;
            dp[i+1][j]+=mod ;
            dp[i+1][j]%=mod ;
            dp[i+1][j+1]+=dp[i][j] ;
            dp[i+1][j]%=mod ;
            dp[i+1][r+1]-=dp[i][j] ;
            dp[i+1][j]+=mod ;
            dp[i+1][j]%=mod ;
        }
        for (int j= 1 ; j<= n ; j++){
            dp[i+1][j]+= dp[i+1][j-1];
            dp[i+1][j]%=mod ;
        }
    }
    for (int j= 1 ; j<= n ; j++){
        ans += dp[k][j];
        ans %= mod ;
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    // freopen("lcm.in","r",stdin); 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}