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

int beg[N], finish[N] , n , q, timer = 0, Tree[8*N] ;
vector<int> graph[N], color(N), upd(8*N), value (8*N);

void dfs (int curr , int parent =- 1) {
    beg[curr]= ++ timer ;
    for (auto child : graph[curr]){
        if (child== parent) continue;
        dfs (child , curr) ;
    }
    finish[curr]= timer ;
}

void unlazy(int id){
    if (upd[id]==0) return;
    int l = 2*id +1 , r = 2*id +2 ;
    Tree[id]=(1ll<<value[id]);
    upd[l]= upd[r]= 1 , upd[id]=0;
    value[l]= value[r]= value[id];
}


void update (int qs , int qe , int val , int ns=1 , int ne=n , int id =0){
    unlazy(id);
    if (qs >ne|| qe <ns) return ;
    if (qs <= ns && ne <= qe ){
        Tree[id]=(1ll<<val);
        upd[id]=1; value[id]=val;
        unlazy(id);
        return ;
    }
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    update (qs , qe , val , ns , md, l);
    update (qs ,qe, val , md+1 , ne ,r);
    Tree[id]=Tree[l]|Tree[r];
}

int query (int qs , int qe , int ns=1 , int ne=n , int id =0){
    unlazy(id);
    if (qs >ne|| qe <ns) return 0;
    if (qs <= ns && ne <= qe ) return Tree[id];
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    return query(qs , qe , ns , md, l)|query(qs ,qe, md+1 , ne ,r);
}


void Solve() {
    cin >> n >>q;
    for (int i=1 ; i<=n; i++) cin >> color[i] ;
    for (int i= 1;i<=n-1;i++){
        int u , v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs (1);
    for (int i=1 ; i<=n; i++) update(beg[i],beg[i],color[i]);
    while (q--){
        int x , u , c; cin>> x ;
        if (x==2){
            cin >> u ;
            cout <<__builtin_popcountll(query(beg[u],finish[u]))<< endl;
        }else {
            cin >> u>> c;
            update(beg[u],finish[u],c);
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