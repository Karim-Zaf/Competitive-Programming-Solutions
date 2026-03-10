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

vector <int> graph[N] ,depth (N) , v ;
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

bool work (){
    int rass=0, all=v[0];
    sort (all(v),[](int u , int v) {return depth[u]>depth[v];});
    vector <int> one , two ;
    for (auto x: v){
        if (one.empty())one.pb(x);
        else if (Lca(x,one.back())==x)one.pb(x);
        else if (two.empty()){
            two.pb(x);
            rass= Lca (one.back(),two.back());
        }else if (Lca(x,two.back())==x)two.pb(x);
        else return false ;
        all=Lca(all,x);
    }
    if (all!=rass&&rass) return false ;
    return true ;
}

void Solve() {
    int n ,q , sz;
    cin >> n ;
    for (int i=1 ; i<n ; i++){
        int u , v ;
        cin >> u>> v ;
        graph[v].pb(u);
        graph[u].pb(v);
    }dfs(1);
    cin >> q ;
    while (q--){
        cin >> sz ;
        v.clear();
        while (sz--){int x; cin >> x; v.pb(x);}
        cout << (work()? "YES": "NO") << endl;
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