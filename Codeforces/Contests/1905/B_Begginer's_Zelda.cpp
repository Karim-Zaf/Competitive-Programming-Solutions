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

const int  N=1e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

vector <int> graph[N] ;

void Solve() {
    int n;
    cin>> n;
    for (int i= 0 ;i<n-1 ;i++){
        int u , v;
        cin >> u >> v ;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int cnt = 0 ;
    for (int i=1 ;i<=n;i++) cnt += (graph[i].size()==1) ;
    cout << ++cnt/2 << endl;
    for (int i=1 ;i<=n;i++){
        graph[i].clear();
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}