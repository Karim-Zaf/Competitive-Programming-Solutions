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

const int  N=2e3+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


vector <pair <int,int>> graph[N];
vector <pair <int,int>> graph2[N];
int bike[N];
int dist[N][N] , n ,m,ans[N], dist2[N];


void Dijkstra (int start=1){
    for (int i= 1 ;i<= n; i++) dist[start][i]= INF ;
    priority_queue<pair <int,int> , vector <pair<int,int>> , greater<>> pq ;
    dist[start][start]=0;
    pq .push({0 , start});
    while(!pq.empty()){
        auto [d , parent]= pq.top();
        pq.pop();
        if (dist[start][parent]<d) continue;
        for (auto [child,value] : graph[parent])
            if ( dist[start][child] >dist[start][parent]+ value*bike[start]){
                dist[start][child]= dist[start][parent]+value*bike[start];
                pq.push({dist[start][child], child});
            }
    }
}
void Dijkstra2 (int start=1){
    for (int i= 1 ;i<= n; i++) dist2[i]= INF ;
    priority_queue<pair <int,int> , vector <pair<int,int>> , greater<>> pq ;
    dist2[start]=0;
    pq.push({0 , start});
    while(!pq.empty()){
        auto [d , parent]= pq.top();
        pq.pop();
        if (dist2[parent]<d) continue;
        for (auto [child,value] : graph2[parent])
            if ( dist2[child] >dist2[parent]+ value){
                dist2[child]= dist2[parent]+value;
                pq.push({dist2[child], child});
            }
    }
}

void Solve() {
    cin >> n >> m ;
    for (int i= 0 ; i<m ;i++){
        int u , v, w ;
        cin >> u >> v >> w ;
        graph[u].pb({v,w});
        graph[v].pb({u,w});
    }
    for (int i=1 ; i<=n ;i++) cin >> bike[i] ;
    for (int i=1 ;i<=n ;i++)Dijkstra (i) ;

    for (int i= 1 ;i<=n ;i++){
        for (int j= 1 ;j<=n ;j++){
            graph2[i].pb({j, dist[i][j]});
        }
    }
    Dijkstra2() ;
    cout << dist2[n] << endl;

    for (int i= 1 ; i<=n ;i++) {
        graph[i].clear() ;
        graph2[i].clear() ;
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