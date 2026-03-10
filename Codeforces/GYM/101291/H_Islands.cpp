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
#define int ll
#define ld long double

const ll N =100+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

int vis [N][N] ;
int  n , m ;
char t[N][N] ;
int dx[]={0,1,0,-1} ;
int dy[]={1,0,-1,0} ;

bool can_move (int i , int j ) { return  i>= 0 && i<n && j>=0 && j<m ;}

void dfs_maze (int i , int j ){
    vis[i][j]=1 ;
    for( ll pas = 0 ;pas< 4 ; pas++){
        int x = i + dx[pas];
        int y = j + dy[pas];
        if (!vis [x][y] && can_move ( x, y )&& t[x][y]!='W')
            dfs_maze (x,y) ;
    }
}

void solve(){
    int res = 0 ;
    cin >> n >> m ;
    for (int i= 0  ; i<n ;i++ )
        for (int j=0 ; j<m ; j++)
            cin >> t[i][j] ;

    for (int i= 0  ; i<n ;i++ )
        for (int j=0 ; j<m ; j++)
            if (!vis[i][j]&& t[i][j]=='L') {
                res++;
                dfs_maze(i, j);
            }
    cout << res << endl;
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}