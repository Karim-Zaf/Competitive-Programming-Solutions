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

const ll N = 2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 3e18 +87;

void solve(){
    int n , res = -INF ;
    cin >> n ;
    vector <ll> v(n);
    for (int i= 0 ;i<n ; i++) cin >> v[i];
    int dp[n][2];
    for (int i= 0 ;i<n ;i++){
        if(i==0|| i==1){
            dp[i][0]=v[i];
            dp[i][1]= max (v[i],0ll);
            continue;
        }
        dp[i][0]= v[i]+ dp[i-2][1];
        dp[i][1]= max (dp[i-2][1],dp[i][0]);
    }
    for (int i= 0;i<n ;i++) res = max (res , dp[i][0]);
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}

// Failure gives you two choices: You stay down or You get up ;)