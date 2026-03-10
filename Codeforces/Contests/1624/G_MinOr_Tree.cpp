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

const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

int n , m ;
vector <array<int,3>> graph[N] ;
vector <int> vis(N) , vis2(N), visited(N);
vector <array <int,3>> stock[32] ;

void dfs (int parent ) {
    visited[parent]= 1 ;
    for (auto child : graph[parent]){
        if(visited[child[0]] || vis[child[2]]) continue ;
        dfs (child[0]) ;
    }
}

void solve() {
    cin >> n >> m ;
    int res = 0 , cnt = 0 , cnt2 =0 ;

    for (int i= 0 ;i<= max(n,m);i++){
        vis[i]= 0 ;
        graph[i].clear();
    }
    for (int i= 0 ; i<32 ; i++){stock[i].clear();}
    for (int i= 1 ; i<=m ; i++){
        int u , v , x ;
        cin >> u >> v >> x ;
        graph[u].pb({v, x,i});
        graph[v].pb({u,x,i});
        for (int j = 0 ; j<=30 ; j++)
            if (x & (1<<j))
                stock[j].pb({u,v,i});
    }
    for (int i= 30 ;i>=0 ; i--){
        for (int j= 1; j<=m ;j++)vis2[j]=vis[j];
        cnt2 = cnt ;
        for (auto [u, v , ind] : stock[i]) {
            if (vis[ind])continue;
            cnt ++ ;
            vis[ind] = 1;
        }
        for (int i= 1 ;i<=n;i++)visited[i]=0 ;
        int ok = 1 ;
        dfs (1) ;
        for (int j= 1 ; j<=n ;j++)ok &= visited[j];
        if (!ok ) {
            for (int j= 1; j<=m ;j++)vis[j]=vis2[j];
            cnt = cnt2;
            res += (1 << i);
        }
    }
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