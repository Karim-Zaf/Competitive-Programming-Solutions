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
#define endl '\n'
#define int ll

const long long N=21,MOD=1e9+7,mod=1e12+7,INF=1e18;

int t[N][N], n , m , k;
map <int,int> middle[2][N][N] ;

int dx[]={0,1, 0, -1};
int dy[]={1,0 ,-1 ,0};


bool can_move (int i, int j){
    return i>=1 && i<=n && j>=1 && j<=m ;
}

void work (int i , int j ,int ind, int val = 0){
    if (i+j==m+1){middle[ind][i][j][val^(ind*t[i][j])]++; return ;}
    for (int pas=2*ind; pas<2*ind+2;pas++){
        int x = i+dx[pas], y= j+dy[pas];
        if (can_move(x,y)) work(x,y,ind,val^t[i][j]);
    }
}

void Solve(){
    int res =0;
    cin >> n>> m>> k ;
    for (int i= 1;i<=n;i++)
        for (int j= 1;j<=m;j++)
            cin >> t[i][j];
    work (1, 1, 0);
    work (n, m, 1);
    for (int j= 1;j<=m ;j++){
        int i = m+1-j;
        if (!can_move(i,j))continue;
        for (auto[val,occ] :middle[0][i][j]) {
            res += occ * middle[1][i][j][val ^ k];
        }
    }
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}