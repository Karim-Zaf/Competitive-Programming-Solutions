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

const ll N = 1e5+ 8 ,  MOD =1e9+7, mod=1e18+7, INF = 1e18 ;

vector <pair <int,int>> graph[N];
int n , m ;
int dist[N], ans[N];

void dijkstra (int start=1){
    for (int i= 1 ;i<= n; i++) dist[i]= INF ;
    priority_queue<pair <int,int> , vector <pair<int,int>> , greater<>> pq ;
    dist[start]=0;
    pq .push({0 , start});
    ans[1]=-1;
    while(!pq.empty()){
        auto [d , parent]= pq.top();
        pq.pop();
        if (dist[parent]<d) continue;
        for (auto [child,value] : graph[parent])
            if ( dist[child] >dist[parent]+ value){
                dist[child]= dist[parent]+value;
                ans[child]= parent;
                pq.push({dist[child], child});
            }
    }
}

void solve(){
    cin >> n >> m ;
    for (int i= 0; i<m ;i++){
        int u , v , x ;
        cin >>u >> v >> x;
        graph[u].pb({v,x});
        graph[v].pb({u,x});
    }
    dijkstra ();
    if (dist[n]==INF){ cout << -1 << endl; return;}
    vector <int> res ;
    int i= n ;
    while (i!=-1){
        res.pb(i);
        i= ans[i];
    }
    reverse(all(res));
    for (auto x: res) cout << x << " " ; cout << endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}

// Failure gives you two choices: You stay down or You get up ;)