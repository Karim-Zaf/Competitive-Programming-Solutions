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

void solve (){
    int n ; 
    cin >> n ; 
    vector <int> v(n) , dp(n);
    vector <vector<int>> pos (n+1);

    for (auto &x: v ) cin >> x; 
    for (int i = 0 ; i<n ;i++){
        if (pos[v[i]].empty()){
            pos[v[i]].pb(i);
            if (i)dp[i]=dp[i-1];
            continue;
        }
        for (int j= pos[v[i]].size()-1, k =0  ; j>=0 && k <=1000 ; j--, k++){
            int currpos = pos[v[i]][j] ;
            dp[i]=max (dp[i],(i-currpos+1) + (currpos>0 ? dp[currpos-1] :0)) ;
        }
        dp[i]=max (dp[i],dp[i-1]);
        pos[v[i]].pb(i);
    }
    cout << dp[--n] << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}