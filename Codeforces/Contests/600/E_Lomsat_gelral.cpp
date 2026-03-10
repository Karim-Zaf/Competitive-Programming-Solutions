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

const ll N = 1e5 + 8 , MOD =1e9+7, mod=1e18+7, INF = 1e18 ;

int colors[N], ans[N],id[N] , sum[N] , mx[N];
map<int,int> freq[N] ;
vector <int> graph[N];

void mrg (int child ,int parent){
    if (freq[id[child]].size()>freq[id[parent]].size())
        swap (id[child], id[parent]);
    for (auto x : freq[id[child]]) {
        int &cnt = freq[id[parent]][x.F] ;
        cnt += x.S;
        if (cnt == mx[id[parent]])
            sum[id[parent]]+= x.F ;
        if (cnt > mx[id[parent]]){
            sum[id[parent]]= x.F ;
            mx [id[parent]]= cnt ;
        }
    }
}

void dfs (int curr = 1 , int parent = -1){
    freq[curr][colors[curr]]=mx[curr]=1 ;
    sum[curr]= colors[curr];
    for (auto child : graph[curr]){
        if (child == parent ) continue;
        dfs(child, curr);
        mrg(child,curr);
    }
    ans[curr] = sum[id[curr]];
}


void solve(){
    int n ;
    cin >> n ;
    for (int i= 1 ; i<=n ; i++) cin >> colors[i];
    for (int i= 1 ; i<=n ; i++) id[i]= i ;

    for (int i= 0 ; i<n-1 ; i++){
        int u , v ;
        cin >> u >> v ;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs();
    for (int i= 1 ; i<=n ; i++) cout << ans[i]<< " ";
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