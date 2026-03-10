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

const int  N=1e5+8,MOD=998244353,mod=998244353,INF=1e17;

int dp[2][N] ;

void Solve() {
    int n ;
    cin >> n ;
    vector <pair<int,int>> v(n+1);
    vector<int> indx(n+1) ;

    for (int i= 1;i<=n;i++){
        cin >> v[i].F ;
    }
    for (int i= 1 ;i<=n ;i++){
        for (int j= i ; j<=n ;j+=i)
            v[i].F = max (v[i].F,v[j].F);
    }
    sort (v.begin()+1,v.end());
    for (int i= 1;i<=n;i++)indx[v[i].S]=i ;
    int sum = 0;
    kar (v);
        kar (v);
    for (int i= 1;i<=n;i++){
        dp[0][i]= 1+sum  ;
        dp[0][i]%= mod ;
        sum += dp[0][i];
        sum %= mod ;
        for (int d= 1; d*d <=v[i].S ;d++){
            if (v[i].S%d) continue;
            dp[1][i]+= dp[0][indx[d]];
            dp[1][i]%= mod ;
            int nw_d = v[i].S/d ;
            if (nw_d ==d||nw_d==v[i].S) continue;
            dp[1][i]+= dp[0][indx[nw_d]];
            dp[1][i]%= mod ;
        }
    }
    int res = 0 ;
//    for (int i= 1;i<=n ;i++)cout << dp[0][i] << " " ; cout << endl;
//    for (int i= 1;i<=n ;i++)cout << dp[1][i] << " " ; cout << endl;
    for (int i= 1 ;i<=n;i++){
        res += (dp[0][i]+dp[1][i])%mod*v[i].F%mod ;
        res %= mod ;
    }
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}