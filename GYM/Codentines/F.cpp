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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int n, m , c , k ;

char grid[105][105] ;
int dp[105][105][200] ;

vector<pair<int,int>> graph[10][10] , mp[10];

bool on (int mask , int bit ){
    return ((1ll<<bit) &mask)!=0 ;
}

int dist (pair<int,int> a, pair<int,int> b ){
    return abs (a.F -b.F) + abs(a.S - b.S );
}

int work (int x, int y , int mask){
    if (mask == (1ll<<c) -1) return dist ({x,y}, {n,m});
    int &ret = dp[x][y][mask];
    if (ret != -1) return ret ;
    ret = INF ;
    for (int i= 0 ; i<c ; i++){
        if (on(mask,i)) continue;
        for (auto[nwx,nwy] : mp[i]){
            ret = min( ret, work( nwx,nwy,(1<<i)+mask)+dist({x,y},{nwx,nwy}));
        }
    }
    for (int i= 1 ; i<c ;i++){
        for (int j = 0; j<i; j++){
            if (!on(mask,i) || !on(mask,j))continue;
            for (auto [child,time]: graph[i][j]){
                if (on(mask,child)) continue;
                ret = min (ret , work(x,y,(1<<child)+mask)+time);
            }
        }
    }
    return ret ;
}

void Solve() {
    cin >> n >> m >> c >> k ;
    for (int i= 1; i<=n ;i++){
        for (int j= 1; j<=m ;j++){
            cin >> grid[i][j] ;
            int curr = grid[i][j]-'1';
            if (curr>=0)mp[curr].pb({i,j});
        }
    }
    memset (dp,-1,sizeof(dp));
    for (int i= 1; i<=k ;i++){
        int u ,v , nw , t ;
        cin >> u >> v >> nw >> t ;
        u--; v--; nw--;
        graph[u][v].pb({nw,t});
        graph[v][u].pb({nw,t});
    }
    int one = grid[1][1]-'1', curr =0 ;
    if (one>=0) curr += (1<<one) ;
    int ans = work (1,1,curr) ;
    cout << (ans >= INF ?-1: ans ) << endl ;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
