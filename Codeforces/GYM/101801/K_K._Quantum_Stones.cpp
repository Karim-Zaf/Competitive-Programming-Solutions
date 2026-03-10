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
 
const ll N = 1e4 + 8 , N_max = 1e6+4,  MOD =1e9+7, mod=1e18+7, INF = 1e18 ;
 
vector <pair <int,int>> graph[N];
int n , m ,k , s , e ;
int spf[N_max],sv[N_max];
int dist[10005][105], good[1000005];
 
void solve(){
    cin >> n >> m >> k ;
    for (int i= 1 ;i<= n ;i++) {
        graph[i].clear();
        for (int j = 0; j <= k; j++) dist[i][j] = INF;
    }
    for (int i= 0 ;i<m ;i++){
        int u , v, x ;
        cin >> u>> v >> x;
        graph[u].pb({v,x});
        graph[v].pb({u,x});
    }
    cin >> s >> e ;
    priority_queue<array <int,3> , vector<array<int,3>>, greater<>> pq;
    dist[s][0]= 0 ;
    pq .push({0,s,0});
    while (!pq.empty()){
        auto [d,parent ,i]= pq.top() ;
        pq.pop();
        if ( dist[parent][i]<d) continue;
        for (auto [child,value] : graph[parent]){
            if (dist[child][i]> dist[parent][i]+ value){
                dist[child][i]= dist[parent][i]+value;
                pq.push({dist[child][i],child,i});
            }
            if (i+1<=k && dist[child][i+1]> dist[parent][i]+good[value]){
                dist[child][i+1]= dist[parent][i]+good[value];
                pq.push({dist[child][i+1],child,i+1});
            }
        }
    }
    int mn = INF ;
    for (int i= 0 ;i<= k;i++) mn = min (mn , dist[e][i]);
    cout << (mn==INF ? -1 : mn) << endl;
}
 
void preprocess(){
    for (int i= 0 ; i<N_max ;i++) good[i]=i;
    for (int i= 2 ; i<N_max ;i++){
        if (sv[i]) continue;
        for (int j= i+i ;j<N_max ;j+=i){
            sv[j]= 1 ;
            good[j]=min( good[j] , j/i + 2*i);
        }
    }
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    preprocess();
    while (test_case--)  solve() ;
}
 
// Failure gives you two choices: You stay down or You get up ;)