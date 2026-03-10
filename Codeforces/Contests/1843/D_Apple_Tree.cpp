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
 
const ll N = 2e5 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;

vector <ll> graph[N], vis (N), kbal(N);

void dfs (ll parent){
    if (graph[parent].size()==1 && parent !=1){kbal[parent]=1;}
    vis [parent]= 1;
    for (auto child: graph[parent]){
        if (! vis[child]){
            dfs(child);
            kbal[parent]+= kbal[child];
        }
    }
}

void solve(){ 
    ll n ; 
    cin >> n; 
    set <ll> s ;
    for (ll i= 0 ;i<n-1 ;i++ ){
        ll u , v  ;
        cin >> u >> v ; 
        s.insert(u);
        s.insert(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);
    ll q ;
    cin>> q ; 
    for (ll i=0 ;i<q ; i++){
        ll u , v ; 
        cin >> u >>  v; 
        cout << kbal[u]*kbal[v] << endl;
    }
    for (auto x : s ){
        vis[x]=0;
        graph[x].clear();
        kbal[x]=0;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}