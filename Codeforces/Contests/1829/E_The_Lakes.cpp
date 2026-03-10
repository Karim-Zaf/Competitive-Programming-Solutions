

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
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)

const ll N = 1000 +5 , MOD =1e9+7, Q =2e5+3 ;

int vis [N][N] ; 
ll t[N][N] , n , m , res ;
ll dx[]={0,1,0,-1} ;  
ll dy[]={1,0,-1,0} ; 

bool can_move (int i , int j ) {
    return  i>= 0 && i<n && j>=0 && j<m ; 
}

void dfs_maze (int i , int j ){ 
    res += t[i][j] ; 
    vis[i][j]=1 ;
    for( ll pas = 0 ;pas< 4 ; pas++){
        int x = i + dx[pas];
        int y = j + dy[pas];
        if (!vis [x][y] && can_move ( x, y ) && t[x][y])
            dfs_maze (x,y) ;
    }
} 

void solve (){   
    cin >> n >> m;
    ll fin = 0; 
    memset(vis,0,sizeof(vis)) ;
    for (ll i=  0 ;i<n ; i++ )
        for (ll j= 0 ;j <m ; j++)
            cin >> t[i][j] ;
    for (ll i=  0 ;i<n ; i++ ){
        for (ll j= 0 ;j <m ; j++){ 
            if (!t[i][j] || vis[i][j]) continue ; 
            res = 0 ; 
            dfs_maze ( i , j )  ;
            fin = max ( fin , res );
        }
    }
    cout << fin <<endl;
}
    

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}