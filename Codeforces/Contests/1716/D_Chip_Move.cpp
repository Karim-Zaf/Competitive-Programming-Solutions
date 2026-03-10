/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
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
#define int ll
#define endl '\n'

const int N=3e5+30,mod=998244353,MOD=mod,INF=1e18+10;

int arith (int x ) {
    return x*(x+1)/2 ;
}

void Solve() {
    int n, k ,cnt = 0;
    cin >> n >> k ;
    vector<int> ans(n+1), dp(n+1);
    dp[0]=1 ;
    for (int i= k ;; i++){
        int start = arith(i-1)-arith(k-1);
        if (start>n) break;
        vector<int> stock (i);
        for (int j= start; j<=n ; j++){
            int x= dp[j];
            (dp[j]= stock[j%i])%=mod;
            (stock[j%i]+=x)%=mod;
            (ans[j] += dp[j])%=mod;
        }
    }
    for (int i= 1; i<=n ;i++) cout<<ans[i]<< " " ;cout <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}