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

const int N=1e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

vector <int> graph[N] ,depth (N);
int up[N][30] ;

void dfs( int parent ){
    for (int i= 1 ;i<28 ; i++)
        up[parent][i]= up [up[parent][i-1]][i-1] ;

    for (auto child : graph[parent]){
        if (up[parent][0]==child)continue;
        depth [child] = depth[parent]+1 ;
        up[child][0]= parent ;
        dfs(child);
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

    int k = depth[a] - depth[b] ;
    a = Binary_Lifting (a,k );
    if (a==b) return a ;
    for (int i= 28 ;i>=0 ;i--){
        if ( up[a][i] == up[b][i]) continue;
        a= up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}

int dist (int u , int v){
    return depth[u]+ depth[v]-2*depth[Lca(u,v)];
}

void Solve() {
    int n , q;
    cin >> n;
    for (int i= 0, u , v ;i<n-1 ;i++){
        cin >> u >> v;
        graph [u].pb(v);
        graph[v].pb(u) ;
    }

    dfs(1);
    cin >>q;

    while(q--){
        int x , y , a, b , k;
        cin >>x >> y >> a >> b >> k ;

        int ab = dist(a,b);
        int one = dist (a,x)+1+dist(y,b);
        int two = dist(a,y)+1+dist(x,b);
        if (ab%2==k%2 && k>=ab)cout << "YES\n";
        else if (one%2==k%2 && one<=k)cout <<"YES\n";
        else if (two%2==k%2 && two<=k)cout <<"YES\n";
        else cout << "NO\n";
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