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

const ll N = 5e5+ 7 , MOD =998244353, mod=998244353, Q =2e5+4 , INF = 1e18 ;

long long  dp[2][N];

void solve (){
    int n ; 
    cin >> n; 
    ll ans =0 ; 
    
    for (int i= 0 ;i<=n+20 ;i++ ) 
        dp[0][i]=dp[1][i]=0;

    vector <int> v(n) ; 
    for (auto &x : v ) cin >> x;

    for (int i= 0 ;i<n ;i++ ){
        dp[0][v[i]]*=2;
        dp[0][v[i]]%= mod ; 

        if (v[i]==0) dp[0][0]++;
        dp[0][v[i]]%= mod ; 

        if (v[i]) dp[0][v[i]]+= dp[0][v[i]-1];
        dp[0][v[i]]%= mod ; 

        if (v[i]>=1) dp[1][v[i]] *=2;
        dp[1][v[i]]%= mod ; 

        if (v[i]==1) dp[1][1]++ ; 
        dp[1][v[i]]%= mod ; 

        if (v[i]>=2) dp[1][v[i]] += dp[0][v[i]-2];
        dp[1][v[i]]%= mod ; 

        dp[1][v[i]+2]*=2;
        dp[1][v[i]+2]%= mod ; 
    }


    for (int i= 0 ;i<=n ;i++ ){
        ans += dp[0][i];
        ans%= mod ;
        ans += dp[1][i];
        ans%= mod ;
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}