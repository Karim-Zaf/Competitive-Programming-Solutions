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
#define int ll
#define ld long double
const ll N = 2e5+ 5 ,  MOD =1e9+7, mod=1e9 +7, INF = 1e9+5;
 
set<__int128> dp[35][35] , output ;
vector <__int128> fact (35) ;
 
void solve(){
    int n , h ;
    cin >>n >> h ;
    h-- ;
    fact [0]=1 ;
    for (int i=1 ; i<=31 ; i++) fact[i]= i * fact[i-1] ;
    for (int i=0 ; i<= 34 ; i++) dp[i][0].insert(1) ;
 
    for (int i= 1 ; i<= n ;i++)
        for (int sum = 0 ; sum<= h ; sum ++ )
            for (int j= 0 ; j<= sum ;j ++)
                for (auto x: dp[i-1][sum -j])
                    dp[i][sum].insert(fact[j]*x) ;
 
    for (auto x : dp[n][h]) output.insert(fact[h]/x);
    for (auto x: output) cout << (ll)x<< endl;
 
 
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}