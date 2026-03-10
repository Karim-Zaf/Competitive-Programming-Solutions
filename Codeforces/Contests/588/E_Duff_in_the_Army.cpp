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
 
const ll N = 1e5+ 7 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

vector <int> graph[N], depth (N), c(N);
int up[N][20] ; 
vector <int> fouk[N][20] , ans [N];


vector <int> merge (vector <int> a , vector<int> b ){
    vector <int> res ;
    map <int,int> mp ;  
    if (a.empty()) return b ;
    if (b.empty()) return a ; 
    int i = 0 , j = 0 ; 
    while (i<a.size() && j <b.size() && res.size()<10){
        if (a[i] >b[j]){
            if (mp[b[j]]){j++; continue;}
            mp[b[j]]++;
            res .pb(b[j++]); 
        }
        else {
            if (mp[a[i]]){i++;  continue;}
            mp[a[i]]++ ; 
            res .pb(a[i++]) ;
        }
    }
    while ((i<a.size()|| j <b.size()) && res.size()<10){
        if (i<a.size()){
            if (mp[a[i]]){i++;  continue;}
            mp[a[i]]++ ; 
            res .pb(a[i++]) ;
        }
        if (j<b.size()) {
            if (mp[b[j]]){j++ ; continue;}
            mp[b[j]]++;
            res .pb(b[j++]); 
        }
    }
    return res ;     
}


void dfs( int parent ){
    for (int i= 1 ;i<19 ; i++){
        up[parent][i]= up [up[parent][i-1]][i-1] ;
        fouk[parent][i] = merge(fouk[parent][i-1],fouk[up[parent][i-1]][i-1]);
    }
    for (auto child : graph[parent]){
        if (up[parent][0]==child)continue;
        depth [child] = depth[parent]+1 ;
        up[child][0]= parent ;
        fouk[child][0]= merge(ans[child],ans[parent]);
        dfs(child);
    }
}

vector <int> Lca_2 ( int a , int b ){
    if (depth[b]> depth[a]) swap(a,b);
    vector <int> res = merge(ans[a],ans[b]);
    int k =depth[a]-depth[b] ; 
    for (int i = 19;i>=0 ;i-- )
        if (k & (1<< i)){
            res = merge (res , fouk[a][i]);
            a = up[a][i];
        }
    if (a==b) return res ;
    for (int i= 19 ;i>=0 ;i--){
        if ( up[a][i] == up[b][i]) continue;
        res = merge(res ,fouk[b][i]);
        res = merge(res ,fouk[a][i]);
        a= up[a][i];
        b = up[b][i];
    }
    return merge( res , fouk[a][0]) ;
}

void solve(){
    int n ,m , q  ; 
    cin >> n>> m >> q ; 
    for (int i= 2 ;i<=n ;i++){
        int x , y  ;
        cin >> x >> y  ;
        graph[--y].pb(--x);
        graph[x].pb(y);
    }
    for (int i= 1  ; i<=m ;i++) {
        cin >> c[i] ;
        if (ans[--c[i]].size()<=10)
            ans[c[i]].pb(i);
    }
    dfs(0);
    while (q--){
        int u , v , a ; 
        cin >> u >> v >> a; 
        vector <int> s = Lca_2 (--u,--v);
        int k = min ((int)s.size(),a);
        cout << k << " ";
        auto it = s.begin();
        for (int i= 0; i<k ;i++) cout<< *(it++)<<" ";
        cout  << endl;
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