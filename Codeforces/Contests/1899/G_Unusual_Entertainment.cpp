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

int n, m ;
vector <int>  graph[N] ;
set<int> s [N];
int perm[N], a[N], ans[N];
vector <array <int,3>> queries[N] ;

void merge (int c , int p ){
    if (s[c].size()>s[p].size()) s[c].swap(s[p]);
    for (auto x : s[c]) s[p].insert(x);
}

void dfs (int curr ,int parent ){
    s[curr].insert(a[curr]);
    for (auto child : graph[curr]){
        if (parent == child) continue;
        dfs (child,curr);
        merge (child,curr);
    }
    for (auto qr : queries[curr]){
        auto it = s[curr].lower_bound(qr[0]);
        if (it == s[curr].end() || (*it)>qr[1]) ans[qr[2]]=0;
        else ans[qr[2]]=1 ;
    }
}


void Solve() {
    cin >> n >> m ;
    for (int i= 1; i<=n; i++){
        graph[i].clear();
        s[i].clear();
        queries[i].clear();
    }
    for (int i= 0; i<n-1; i++){
        int u , v;
        cin >> u >> v ;
        graph[v].pb(u);
        graph[u].pb(v);
    }
    for (int i= 1; i<=n ; i++){
        cin >> perm[i];
        a[perm[i]]= i ;
    }
    for (int q = 0; q<m ; q++){
        int l ,r , x ;
        cin >> l >> r >> x ;
        queries[x].pb({l,r,q});
    }
    dfs(1,-1);
    for (int i = 0; i<m; i++){
        if (ans[i])cout << "YES\n";
        else cout << "NO\n";
    }
    cout << endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}