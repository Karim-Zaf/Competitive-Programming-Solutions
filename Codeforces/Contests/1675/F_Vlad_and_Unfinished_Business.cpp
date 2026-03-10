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

const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

int n , k, x , y  ;
vector <int> v (N), indice (N), hachti(N), depth(N);
vector <int> graph[N] ;
int up[N][30] ;

void dfs( int parent, int other = -1 ){
    up[parent][0]= other ;
    if (other == -1 ) up[parent][0]= parent ;
    for (int i= 1 ;i<28 ; i++)
        up[parent][i]= up [up[parent][i-1]][i-1] ;
    for (auto child : graph[parent]){
        if (up[parent][0]==child)continue;
        depth [child] = depth[parent]+1 ;
        up[child][0]= parent ;
        dfs(child, parent);
    }
}

int Binary_Lifting (int a, int k){
    for (int i = 28;i>=0 ;i-- )
        if (k & (1<< i))
            a = up[a][i];
    return a ;
}

int Lca ( int a , int b ){
    if (depth[b]> depth[a]) swap(a,b);

    int nw = depth[a] - depth[b] ;
    a = Binary_Lifting (a,nw );
    if (a==b) return a ;

    for (int i= 28 ;i>=0 ;i--){
        if ( up[a][i] == up[b][i]) continue;
        a= up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}

int dfs1 (int curr , int parent = -1 ) {
    if (hachti[curr])indice[curr]=1 ;
    for (auto child : graph[curr]){
        if (child== parent)continue;
        indice[curr] |= dfs1 (child, curr) ;
    }
    return indice[curr] ;
}

int dfs2 (int curr , int parent = -1 ) {
    int res =0 ;
    for (auto child : graph[curr]){
        if (child== parent)continue;
        if (indice[child])
            res += 2 + dfs2 (child, curr) ;
    }
    return res ;
}

void solve(){
    cin >> n >> k >> x >> y ;
    x-- , y-- ;
    for (int i= 0 ; i<k ; i++) {
        cin >> v[i];
        hachti[--v[i]]=1 ;
    }
    for (int i= 0 ; i<n-1 ; i++){
        int u , vv ;
        cin >> u >> vv ;
        graph[--u].pb(--vv) ;
        graph[vv].pb(u) ;
    }
    dfs (x);
    dfs1 (x);
    int cnt = dfs2 (x);
    int mx = INF ;
    for (int i= 0 ; i<k ; i++) {
        int e = v[i];
        if (Lca(e,y)==x) mx = min(mx, depth[y]);
        else if (Lca(e,y)==y) mx =  min(mx,  - depth[y]);
        else if (Lca(e,y)==e) mx =  min(mx,  - 2*depth[e]+depth[y]);
        else  mx = min(mx,   depth[y]- 2*depth[ Lca(e,y)]);
    }
    cout << cnt + mx << endl;
    for (int i= 0 ;i<=n; i++) {
        depth[i]= hachti[i]= indice[i]=0;
        graph[i].clear() ;
        for (int j= 0 ; j<30 ;j++) up[i][j]=0 ;
    }
    for (int i= 0 ; i<= k ;i++ ) {hachti[v[k]]=0 ;v[k]=0 ;}
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}