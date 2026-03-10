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
 
const int N=105+30,mod=1e9+7,MOD=mod,INF=1e18+10;
 
int vis [N][N] ;
ll t[N][N] , n , m ;
ll dx[]={0,1,0,-1} ;
ll dy[]={1,0,-1,0} ;
int xa,ya,xb,yb,curr=1;
 
 
bool can_move (int i , int j ) {
    return  i>= 1 && i<=n && j>=1 && j<=m ;
}
 
bool dfs_maze (int i , int j ){
    if (i==xb&&j==yb)return true;
    vis[i][j]=1 ;
    bool ans = false ;
    for( ll pas = 0 ;pas< 4 ; pas++){
        int x = i + dx[pas];
        int y = j + dy[pas];
        if (!vis [x][y] && can_move ( x, y ) && ((1<<t[x][y])&curr))
            ans |= dfs_maze (x,y) ;
    }
    return ans ;
}
 
void Solve() {
    cin >> n >>m >> xa>> ya >> xb >> yb ;
    int ans = 20;
    for (int i= 1;i<=n ;i++){
        for (int j= 1;j<=m ;j++){
            cin >> t[i][j] ;
            t[i][j]--;
        }
    }
 
    for (;curr<(1<<10);curr++){
        memset(vis,0,sizeof(vis));
        if (dfs_maze(xa,ya)&& ((1<<t[xa][ya])&curr))
            ans = min (ans ,(int)__builtin_popcount(curr));
    }
    cout << ans << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}