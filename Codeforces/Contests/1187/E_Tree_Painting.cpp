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

const int N=2e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

vector<int> graph[N] , sz, dp;
int ans=0 , n ;

void dfs (int  curr = 1, int parent = 0 ){
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs (child,curr) ;
        sz[curr]+= sz[child];
        dp[curr]+= dp[child] ;
    }
    dp[curr]+=sz[curr];
}

void work (int  curr = 1, int parent = 0 ){
    int ancp = dp[parent], ansc= dp[curr];

    dp[parent] -= dp[curr]+sz[curr];
    dp[curr]= 0 ;
    for (auto child : graph[curr]){
        dp[curr]+= dp[child] ;
    }
    dp[curr]+= n;
    ans = max (ans,dp[curr]);

    for (auto child : graph[curr]){
        if (child == parent) continue;
        work (child,curr) ;
    }

    dp[parent]= ancp, dp[curr]= ansc ;
}

void init(){
    sz.resize(n+1);
    dp.resize(n+1);
    fill(all(sz),1);
}

void Solve() {
    cin >> n ;
    init();
    for (int i= 0, u, v ; i<n-1 ; i++){
        cin >> u >> v;
        graph[u].pb(v) ;
        graph[v].pb(u);
    }
    dfs();
    work();
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}