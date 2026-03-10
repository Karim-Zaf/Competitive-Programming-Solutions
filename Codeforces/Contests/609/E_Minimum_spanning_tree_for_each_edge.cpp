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
vector <array<int,3>> graph[N] ;
vector<int> depth (N);
int up[N][30], mx[N][30],n, m, sum = 0,root;

void dfs( int parent ){
    for (int i= 1 ;i<28 ; i++){
        up[parent][i]= up [up[parent][i-1]][i-1] ;
        mx[parent][i]= max (mx[parent][i-1],mx [up[parent][i-1]][i-1]) ;
    }

    for (auto [child,val,id] : graph[parent]){
        if (up[parent][0]==child)continue;
        depth [child] = depth[parent]+1 ;
        up[child][0]= parent ;
        for (int i= 0 ; i<30; i++) mx[child][i]= val ;
        dfs(child);
    }
}

int Binary_Lifting (int a, int k){
    for (int i = 28;i>=0 ;i-- )
        if (k & (1<< i))
            a = up[a][i];
    return a ;
}

int get_mx (int a, int k){
    int ret = 0 ;
    for (int i = 28;i>=0 ;i-- )
        if (k & (1<< i)){
            ret = max (mx[a][i],ret) ;
            a = up[a][i];
        }
    return ret ;
}

int Lca ( int a , int b ){
    if (depth[b]> depth[a]) swap(a,b);

    int k = depth[a] - depth[b] ,ret = 0;
    ret = max (ret , get_mx (a,k));
    a = Binary_Lifting (a,k );
    if (a==b) return ret ;

    for (int i= 28 ;i>=0 ;i--){
        if ( up[a][i] == up[b][i]) continue;
        ret = max (ret , mx[a][i]);
        ret = max (ret , mx[b][i]);
        a= up[a][i];
        b = up[b][i];
    }

    return max({ret,mx[a][0],mx[b][0]});
}

struct DSU{
    vector<int>  sz , parent ;
    void init(int n){ for (int i = 0; i < n; i++){ parent.pb(i) ; sz.pb(1) ; } }
    int get(int a){return (parent[a] == a ? a : parent[a] = get(parent[a]));}
    bool unite(int a, int b){
        if ((a = get(a))==(b = get(b))) return false;
        if (sz[a]>sz[b]) swap (a,b) ;
        parent[b] = a;
        sz[a] += sz[b];
        return true ;
    }
    bool same_set(int a, int b){return get(a) == get(b);}
    int size(int a){ return sz[get(a)];}
};

vector<array<int,4>> edges ;
vector<int> ans ;

void SpanningTree(){
    sort (all(edges));
    DSU dsu ;
    dsu.init (n+2) ;
    kar (edges);
    for (auto [x,u,v,id] : edges){
        if (dsu.same_set(u,v))continue;
        root = u ;
        graph[u].pb({v,x,id});
        graph[v].pb({u,x,id}) ;
        dsu.unite(u,v);
        sum += x ;
        ans[id]= 1 ;
    }
}

void Solve() {
    cin >> n >> m ;
    ans.resize(m) ;
    for (int i=0, u , v,x; i<m ;i++){
        cin >>u >> v >> x ;
        edges.pb({x,u,v,i}) ;
    }
    SpanningTree() ;
    for (auto &x: ans) if (x) x= sum ;

    dfs(root);

    for (auto [x,u,v,id] : edges){
        if (ans[id])continue;
        int curr = Lca (u,v);
        ans [id]= sum +x - curr ;
    }
    for (auto x: ans) cout << x << endl ;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}