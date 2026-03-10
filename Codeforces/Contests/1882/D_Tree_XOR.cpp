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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int n , cnt = 0;
vector<int> graph[N] ,value(N), sz(N), ans(N);

void dfs (int curr =1 , int parent = 0){
    for (auto child : graph[curr]){
        if (child == parent ) continue;
        dfs (child,curr);
        sz[curr]+= sz[child] ;
    }
    cnt += (value[curr]^value[parent]) * sz[curr] ;
}

void work (int curr =1 , int parent = 0){
    ans[curr]= ans[parent] ;
    ans[curr]-= (value[curr]^value[parent]) * sz[curr] ;
    ans[curr]+= (value[curr]^value[parent])*(sz[1]-sz[curr]);
    for (auto child : graph[curr]){
        if (child == parent ) continue;
        work (child,curr);
    }
}

void tandhif(){
    cnt = 0;
    for (int i= 0 ;i<=n ;i++) {
        graph[i].clear();
        sz[i]=1 ;
        value[i]= ans[i]=0;
    }
}

void Solve() {
    cin >> n;
    tandhif() ;
    for (int i= 1 ; i<=n; i++)cin >> value[i] ;
    for (int i= 1 ; i<n; i++){
        int u , v ;
        cin >> u >> v ;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    value[0]=value[1];
    dfs();
    ans[0]=cnt;
    work() ;
    for (int i= 1;i<=n ; i++) cout << ans[i] << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}