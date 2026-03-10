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

vector <int> graph[N] ,depth (N),depth2(N), vis(N);
int up[N][30] ; 

void dfs_2( int parent ){
    vis[parent]=1 ;
    for (auto child : graph[parent]){
        if (vis[child])continue;
        depth2 [child] = depth2[parent]+1 ;
        dfs_2(child);
    }
}
void dfs( int parent ){
    for (int i= 1 ;i<28 ; i++)
        up[parent][i]= up [up[parent][i-1]][i-1] ;
    vis[parent]=1 ;
    for (auto child : graph[parent]){
        if (vis[child])continue;
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
    int n , mx = 1 ; 
    cin >>n; 
    vector <int> dist(n+1),ans(n);
    map<int,vector<int>> mp ;
    for (int i= 0 ;i<n-1 ;i++){
        int a , b; 
        cin >> a >> b; 
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1);
    for (int i= 1 ;i<=n ;i++)
        if (depth[i]>=depth[mx])
            mx = i;

    fill(all(vis),0);
    dfs_2(mx);
    for (int i= 1 ;i<= n;i++){
        int Ancestor = Lca(mx,i);
        dist[i]= depth[mx]+depth[i]-2*depth[Ancestor];
        mp[dist[i]].pb(i);
    }
    for (int i= 1 ;i<=n ;i++)
        if (depth2[i]>=depth2[mx])
            mx = i;
    fill(all(vis),0);
    dfs_2(mx);
    set <int> s ;
    for (int i= 1 ;i<= n;i++){
        int Ancestor = Lca(mx,i);
        dist[i]= depth[mx]+depth[i]-2*depth[Ancestor];
        mp[dist[i]].pb(i);
        s.insert(i);
    }
    s.erase(mx);
    for (int i = n-1 ;i>=0 ;i--){
        for (auto x : mp[i+1]){
            if (s.find(mx)!=s.end()) s.erase(mx);
            if (s.find(x)==s.end()) continue;
            s.erase(x);
        }
        ans[i]= 1+s.size();
        kar (s);
    }
    for (auto x: ans) cout << x << " " ; cout << endl;

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