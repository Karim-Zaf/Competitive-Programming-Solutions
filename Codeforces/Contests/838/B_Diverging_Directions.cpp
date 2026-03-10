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

const int  N=4e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int n, q ;
vector<pair<int,int>> graph[N] ;
vector<array<int,3>>edges;
vector<int> beg,en , lazy(4*N)  ,upd(4*N),Tree(4*N);
int a[4*N], timer  = 0 ;

void unlazy (int id , int ns , int ne){
    int l= 2*id +1 , r =2*id +2 ;
    Tree[id]+= lazy[id];
    if (ns!=ne){
        lazy[l]+= lazy[id];
        lazy[r]+= lazy[id];
        upd[l]=upd[r]= 1 ;
    }
    lazy[id]=upd[id]=0;
}

void update (int qs , int qe,int x , int ns = 1, int ne = n , int id =0 ){
    unlazy (id,ns,ne);
    if (ns >qe || ne <qs)return ;
    if (qs <= ns && ne <= qe){
        lazy[id]+= x;
        upd[id]= 1;
        unlazy (id,ns,ne);
        return ;
    }
    int l = 2*id +1, r= 2*id +2 , md = ns + (ne-ns)/2 ;
    update (qs,qe,x,ns,md,l);update(qs,qe,x,md+1,ne,r);
    Tree[id]=min(Tree[l],Tree[r]);
}

int query (int qs , int qe , int ns = 1, int ne = n , int id =0 ){
    unlazy (id,ns,ne);
    if (ns >qe || ne <qs)return INF;
    if (qs <= ns && ne <= qe)return Tree[id];
    int l = 2*id +1, r= 2*id +2 , md = ns + (ne-ns)/2 ;
    return min(query(qs,qe,ns,md,l),query(qs,qe,md+1,ne,r));
}


void dfs (int curr , int val=0 ,int parent = -1){
    beg[curr] = ++timer;
    for (auto [child,weight] : graph[curr]) {
        if (child == parent) continue;
        dfs(child, weight,curr);
    }
    en[curr]= timer ;
    update (beg[curr],en[curr],val);
    update (beg[curr],beg[curr],a[curr]);
}

void init(){
    edges.resize(2*n) ;
    beg.resize(n+4);
    en.resize(n+4);
}

void Solve() {
    cin >> n >>q;
    init();
    for (int i= 1,w, u, v;i<=2*n-2;i++){
        cin >> u >> v >> w ;
        edges[i]={u,v,w};
        if (i<=n-1) graph[u].pb({v,w});
        else a[u]=w ;
    }
    dfs (1) ;
    while (q--){
        int x;
        cin >> x ;
        if (x==1){
            int i, w ;
            cin >> i >> w ;
            if (i<=n-1) {
                int node = edges[i][1];
                int val = -edges[i][2]+ w;
                update (beg[node],en[node],val);
                edges[i][2]= w;
            }
            else{
                int node = edges[i][0] ;
                int val = -a[node]+ w;
                update (beg[node],beg[node],val);
                a[node]=w;
            }
        }else {
            int u ,v ;
            cin >> u >> v ;
            if (beg[u]<= beg[v] && beg[v]<= en[u] ){
                int mn = query (beg[v],beg[v]);
                mn -= query (beg[u],beg[u]);
                mn += a[u] ;
                mn -= a[v];
                cout <<mn << endl;
                continue;
            }
            int mn = query (beg[u],en[u]);
            mn -= query (beg[u],beg[u]);
            mn += query( beg[v],beg[v]);
            mn += a[u];
            mn -= a[v];
            cout << mn << endl;
        }
    }
}

int32_t main(){
     #ifndef ONLINE_JUDGE
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}