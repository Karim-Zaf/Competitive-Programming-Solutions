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
 
const int  N=5e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;
 
int n , timer = 0,q;
string letter;
vector<int> graph[N], depth(N) ,beg(N), finish(N);
vector<pair <int,int>> query[N];
 
void dfs (int curr , int parent = 0 ){
    depth[curr]= depth[parent]+1 ;
    beg[curr]= ++timer ;
    query[depth[curr]].pb({timer,1<<(letter[curr-1]-'a')});
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs (child,curr);
    }
    finish[curr]= timer;
}
 
void Solve() {
    cin >> n >>q;
    for (int i= 2; i<=n ;i++){
        int u ; cin >> u ;
        graph[u].pb(i);
        graph[i].pb(u);
    }cin >> letter;
    for (int i= 1; i<=n ;i++)query[i].pb({0,0});
    dfs (1) ;
    for (int i= 1; i<=n ;i++)
        for (int j= 1; j<query[i].size() ; j++)
            query[i][j].S ^=query[i][j-1].S ;
 
 
    while (q--){
        int u ,dep ; cin >> u >> dep ;
        int r = upper_bound(all(query[dep]),make_pair(finish[u],INF))-query[dep].begin()-1;
        int l = lower_bound(all(query[dep]),make_pair(beg[u],-1ll))-query[dep].begin()-1;
        int curr = query[dep][r].S^query[dep][l].S;
        if (__builtin_popcountll(curr)>=2) cout << "No\n";
        else cout << "Yes\n";
    }
 
 
 
 
}
 
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}