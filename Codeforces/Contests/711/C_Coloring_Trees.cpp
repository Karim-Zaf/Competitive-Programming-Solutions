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


ll dp[105][105][105] , v[105] , p[105][105];
int n , m , k ;
ll res=INF ; 

// dp (position chojra ,  ekher couleur , kadech staamelet mn subseg )
ll work (int pos , int coul , int sub ){
    if (pos ==n &&  sub !=k) return INF ;
    if (pos ==n) return 0 ;
    ll &ret = dp[pos][coul][sub];

    if (ret != -1 ) return ret ;
    if (v[pos]){
        ret = work (pos+1,v[pos],sub + (coul == v[pos]? 0:1));
        return ret ;
    }
    ret = INF ;
    ret = min (ret , work(pos+1,coul,sub) + p[pos][coul]);
    for (int i= 1 ;i<=m ;i++){
        if (i==coul)continue;
        ret = min(ret , work (pos+1 ,i , sub+1)+ p[pos][i]);
    }
    return ret ;
}


void solve(){

    cin >> n >> m >> k ; 
    for (int i= 0 ; i<n ;i++) cin >> v[i];
    for (int i= 0 ;i<n ;i++)
        for (int j= 1  ; j<=m ;j++)
            cin >> p[i][j];
    memset (dp,-1 ,sizeof(dp));
    if (v[0]) res = work (0,v[0],1); 
    else 
        for (int i=1 ;i<=m ;i++)
            res = min (res , work (1,i,1) + p[0][i]);

    cout << (res ==INF? -1 : res)<< endl;
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