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

const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;

vector <ll> v , dp(N), divisors[N];
void solve (){
    int n ;
    cin >> n; 
    v.resize(n);
    for (int i = 1 ; i<N  ; i++)
        for (int j=i ; j<N ; j+=i)
            divisors[j].pb(i);

    for (auto &x : v) cin >> x ;
    dp[0]= 1 ; 
    for (auto x : v){
        for (int i= (int)(divisors[x].size())-1 ; i>=0 ; i--){
            dp[divisors[x][i]]+= dp[divisors[x][i]-1];
            dp[divisors[x][i]]%=MOD ;
        }
    }

    for (int i= 2 ;i<N ;i++){
        dp[i]+=dp[i-1];
        dp[i]%=MOD ;
    }
    cout << dp[1000*1000] << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}