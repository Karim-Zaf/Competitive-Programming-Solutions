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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

map<int,int> mp[N] ;
int n , ans = 0, sum = 0;
vector<int> graph[N], color(N) ;

void merge (map<int,int> &a , map<int,int> &b ,int col ){
    ans += (b[col]);
    if (a.size()<b.size()) {
        a.swap(b);
    }
    for (auto [key,val] :b) {
        if (key==col){a[key]+=val ;continue;}
        sum -= a[key]*a[key];
        sum -= b[key]*b[key];
        a[key]+= val ;
        sum += a[key]*a[key];
    }
}

void dfs (int curr , int parent = -1 ){
    for (auto child: graph[curr]){
        if (child== parent) continue;
        dfs (child,curr);
    }
    kar (curr);
    sum = 0 ;
    for (auto child : graph[curr]){
        if (child== parent) continue;
        merge (mp[curr], mp[child], color[curr]);
    }
    ans += sum / 2 ;
    mp[curr][color[curr]]=1;
}

void init() {
    ans = 0 ;
    for (int i= 1; i<=n ;i++){
        graph[i].clear();
        mp[i].clear();
    }
}

void Solve() {
    cin >> n ;
    for (int i=1 ; i<=n ;i++ ) cin >> color[i];
    init();
    for (int i= 0 , u , v; i<n-1 ;i++){
        cin >> u >> v ;
        graph[u].pb(v) ;
        graph[v].pb(u);
    }
    dfs(1) ;
    cout << ans << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}