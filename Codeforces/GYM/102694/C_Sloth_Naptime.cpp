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
const ll N = 3e5+ 7 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

vector <int> graph[N] ,depth (N), vis(N);
int up[N][30] ; 

void dfs( int parent ){
    for (int i= 1 ;i<28 ; i++)
        up[parent][i]= up [up[parent][i-1]][i-1] ;
    vis[parent]=1 ;
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

void solve(){
    int n ; 
    cin >> n ;
    for (int i= 0 ; i<n-1 ;i++){
        int x ,y ;
        cin >> x >>y ; 
        graph[--x].pb(--y);
        graph[y].pb(x);
    }
    int q ;
    cin >> q;
    dfs (0);
    while (q--){
        int a , b , c ; 
        cin >> a >> b >> c ;
        a--; b--; 
        int Ancestor = Lca(a,b);
        if (depth[a]-depth[Ancestor]>=c){
            cout << Binary_Lifting(a,c)+1 << endl;continue;
        }
        if (depth[a]+depth[b]-2*depth[Ancestor]>=c){
            cout << Binary_Lifting(b,depth[b]-depth[Ancestor]-(c-( depth[a]-depth[Ancestor])))+1 << endl;continue;
        }
        cout << ++b << endl;
    }
}
 


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}




// Failure gives you two choices: You stay down or You get up ;)