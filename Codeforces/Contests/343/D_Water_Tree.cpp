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

const int N=6e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int Tree[4*N][2] , upd[4*N][2], lazy[4*N][2],n;

void unlazy(int id,int indx){
    if (upd[id][indx]==0) return;
    int l = 2*id +1 , r = 2*id +2 ;
    Tree[id][indx]=lazy[id][indx];
    upd[l][indx]= upd[r][indx]= 1,upd[id][indx]=0;
    lazy[l][indx]= lazy[r][indx]= lazy[id][indx];
}


void update (int qs , int qe ,int indx, int val , int ns=1 , int ne=n , int id =0){
    unlazy(id,0),unlazy(id,1);
    if (qs >ne|| qe <ns) return ;
    if (qs <= ns && ne <= qe ){
        upd[id][indx]=1;
        lazy[id][indx]=val;
        unlazy(id,0),unlazy(id,1);
        return ;
    }
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    update (qs , qe , indx,val , ns , md, l);
    update (qs ,qe, indx,val , md+1 , ne ,r);
    Tree[id][0]=max(Tree[l][0],Tree[r][0]);
    Tree[id][1]=max(Tree[l][1],Tree[r][1]);
}

int query (int qs , int qe ,int indx, int ns=1 , int ne=n , int id =0){
    unlazy(id,0),unlazy(id,1);
    if (qs >ne|| qe <ns) return 0 ;
    if (qs <= ns && ne <= qe )return Tree[id][indx] ;
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    return max(query (qs , qe , indx,ns , md, l) ,query (qs ,qe,indx, md+1 , ne ,r));
}

int timer = 0 , start[N], endd[N];
vector<int> graph[N] ;

void Euler_Tour (int curr , int parent=-1){
    start[curr]= ++timer;
    for (auto child  : graph[curr])
        if (child != parent )
            Euler_Tour(child,curr);
    endd[curr]=timer ;
}

void Solve() {
    cin >> n ;
    for (int i= 1, u , v; i<n ;i++){
        cin >> u >> v ;
        graph[v].pb(u) ;
        graph[u].pb(v) ;
    }
    Euler_Tour(1) ;
    int q ; cin >> q ;

    for (int t = 1; t<= q; t++){
        int x, u ;
        cin >> x >> u ;
        if (x==1) update (start[u],endd[u],1,t);
        else if (x==2) update (start[u],start[u],0,t);
        else {
            int one = query(start[u],endd[u],0);
            int two = query(start[u],start[u],1);
            cout << (one>=two? 0:1) << endl;
        }
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