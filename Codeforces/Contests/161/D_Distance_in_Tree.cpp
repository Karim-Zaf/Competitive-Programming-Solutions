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

const int  N=5e4+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

vector<int> graph[N] ;
int n, k ,ans = 0;
int dp[N], sum[N][505] ;

void dfs(int curr=1 , int parent =-1){
    for (auto child: graph[curr]){
        if (child == parent) continue;
        dfs (child,curr);
    }


    sum[curr][0]= 1 ;
    for (int i= 1;i<=k ;i++){
        for (auto child : graph[curr]){
            if (child == parent) continue;
            sum [curr][i]+= sum[child][i-1];
        }
    }

    for (int i= 1 ;i<k ; i++){
        int cnt = 0 ;
        for (auto child : graph[curr]){
            if (child == parent) continue;
            int one = 1 ;
            if (i>=1) one =sum[child][i-1];
            int two = sum[curr][k-i];
            if (k-i-1>=0) two-=sum[child][k-i-1];
            cnt += one*two;
        }
        dp[curr]+=cnt;
    }

    dp[curr]/=2;
    dp[curr]+=sum[curr][k];
    ans +=dp[curr];
}


void Solve() {
    cin >> n >> k ;
    for (int i= 0, u , v ; i<n-1 ;i++){
        cin >> u >> v  ;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs () ;
    cout << ans << endl;
}

int32_t main(){
     #ifndef ONLINE_JUDGE
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}