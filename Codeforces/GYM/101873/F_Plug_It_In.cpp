#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(all(v))));
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
 
void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
 
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
 
void nop() {
    cout << -1 << endl;
    return;
}
 
struct edge{
    int to,ind,flow,cap;
};
 
struct flawlaw{
 
 
    int n , s , t , mif ;
    vector<int> lvl , nxt ;
    vector<vector<edge>> adj ;
 
    void init(int nn , int ss , int tt)
    {
        lvl.clear() ; nxt.clear() ; adj.clear() ;
        n = nn , s = ss , t = tt , mif = 0 ;
        adj.resize(3*n+5) ;
        lvl.resize(3*n+5) ;
        nxt.resize(3*n+5) ;
 
    }
    bool bfs(){
        for(int i = 0 ; i<3*n+5 ; i++){
            lvl[i] = -1 ;
            nxt[i] = 0 ;
        }
        queue<int> q ;
        q.push(s);
        lvl[s]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
 
            for(auto i : adj[node])
                if(lvl[i.to] == -1 && i.flow <= i.cap-mif){
                    q.push(i.to) ;
                    lvl[i.to] = lvl[node]+1 ;
                }
        }
        return (lvl[t] >=0) ;
    }
    int dfs(int node, int flow){
 
        if(node == t) return flow;
 
        for( ; nxt[node]<adj[node].size() ; nxt[node]++){
 
            auto &i=adj[node][nxt[node]] ;
            if(lvl[i.to]!=lvl[node]+1 || i.flow==i.cap) continue ;
            int f = dfs(i.to , min(flow, i.cap-i.flow)) ;
            if(f){
                i.flow += f ;
                adj[i.to][i.ind].flow -= f ;
                return f ;
            }
        }
        return 0;
    }
    ll maxFlow(){
        ll ret=0;
        mif=1;//for(mif=P2(30);mif;mif/=2) //!adjust to max edge cap
        while(bfs())
            for(int f=dfs(s,INT_MAX);f;f=dfs(s,INT_MAX)) ret+=f;
        return ret;
    }
    void addEdge(int u,int v,int w){
        int a = adj[u].size() ;
        int b = adj[v].size() ;
        adj[u].pb({v,b,0,w}) ;
        adj[v].pb({u,a,0,0}) ;
    }
 
};
 
const int N = 1505 ;
vector<int> adj[N] ;
 
flawlaw flo ;
int m , n , k ;
 
int work(int node)
{
    int srs = 1 , sink = n+m+2 ;
    flo.init(n + m + 2 , srs , sink) ;
    for(int i = 1 ; i<=n ; i++){
        if(i==node){
            flo.addEdge(srs , i+1 , 1) ;
            flo.addEdge(srs , i+1 , 1) ;
            flo.addEdge(srs , i+1 , 1) ;
        }
        else flo.addEdge(srs , i+1 , 1) ;
        for(int to : adj[i]){
            flo.addEdge(i+1 , n+1+to , 1) ;
        }
    }
    for(int i = 1 ; i<=m ; i++){
        flo.addEdge(n+1+i , sink , 1) ;
    }
 
    return flo.maxFlow() ;
 
}
 
void solve() {
    cin>>n>>m>>k ;
    for(int i = 1 ; i<=k ; i++){
        int u , v ; cin>>u>>v ;
        adj[u].pb(v) ;
    }
    int ans = 0 ;
    for(int i = 1 ; i<=100 ; i++){
        int ii = rng()%n + 1 ; 
        ckmax(ans , work(ii)) ;
    }
    cout<<ans<<endl;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }
 
    return 0;
}