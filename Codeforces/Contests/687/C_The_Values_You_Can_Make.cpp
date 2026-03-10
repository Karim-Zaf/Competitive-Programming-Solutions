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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

const int M=505 ;
bool dp[M][M][M] ;
bool vis[M][M];

void Solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for (int i= 1; i<=n ;i++)cin >> v[i] ;
    for (int i= 0 ; i<505;i++)
        for (int j= 0 ;j<505; j++)
            dp[i][j][0]=1;
    for (int i= 1; i<=n ; i++){
        for (int sum =0 ; sum <= k ; sum ++){
            if (sum - v[i]<0||!vis[i-1][sum-v[i]]) continue;
            for (int j= 0 ;j<=k; j++)
                if (j+ v[i]<=k)
                    dp[i][sum][j+v[i]]|= dp[i-1][sum-v[i]][j];
            for (int j= 0 ;j<=k; j++)
                dp[i][sum][j]|= dp[i-1][sum-v[i]][j];
            dp[i][sum][v[i]]=1 ;
            dp[i][sum][sum]=1 ;
            vis[i][sum]=1;
        }
        for (int sum = 0 ; sum <= k ; sum++){
            vis[i][sum]|= vis[i-1][sum] ;
            for (int j= 0;j<=k ;j++)
                dp[i][sum][j]|=dp[i-1][sum][j];
        }
        vis[i][v[i]]=1 ;
        dp[i][v[i]][v[i]]= 1 ;
    }

    vector<int> ans ;
    for (int i= 0 ; i<=k ;i++){
        bool &x = dp[n][k][i];
        if (!x) continue;
        ans.pb(i);
    }
    cout << ans.size()<< endl;
    for (auto x : ans ) cout << x << " " ;cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}