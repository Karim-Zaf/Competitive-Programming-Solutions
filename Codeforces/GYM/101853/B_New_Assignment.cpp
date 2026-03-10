#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
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
         n = nn , s = ss , t = tt ;
         adj.clear() ; lvl.clear() ; nxt.clear() ;
         adj.resize(20*n+5) ;
         lvl.resize(20*n+5) ;
         nxt.resize(20*n+5) ;

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
     int maxFlow(){
         int ret=0;
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


flawlaw network ;

const int N = 1e6+5 ;
int a[N] ;
char tp[N] ;
vector<int> men[N] , wom[N] ;
vector<int> divi[N] ;

void prep(){
    for(int i = 2 ; i<=1e6 ; i++){
        for(int j = i ; j<=1e6 ; j+=i){
            divi[j].pb(i) ;
        }
    }
}

void solve() {
    int n ; cin>>n ;
    int source = n+1 , sink = n+2 ;
    network.init(n+5 , source , sink) ;
    for(int i = 1 ; i<=n ; i++){
        cin>>a[i] ;
    }
    for(int i = 1;  i<=n ; i++){
        cin>>tp[i] ;
        if(tp[i]=='F'){
            network.addEdge(source , i , 1) ;
        }
        else{
            network.addEdge(i , sink , 1) ;
            for(int j : divi[a[i]]){
                men[j].pb(i) ;
            }
        }
    }
    set<pair<int,int>> ed ;
    for(int i = 1 ; i<=n ; i++){
        if(tp[i]=='F'){
            for(int j : divi[a[i]]){
                for(int idx : men[j]){
                    ed.insert({i , idx}) ;
                }
            }
        }
    }
    for(int i = 1 ; i<=n ; i++){
        if(tp[i]=='F') continue;
        for(int j : divi[a[i]]){
            men[j].clear() ;
        }
    }
    for(auto p : ed){
        network.addEdge(p.F , p.S , 1) ;
    }
    cout<<n - network.maxFlow()<<endl;


}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    prep() ;
    io();
    ll tt = 1;
    cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}