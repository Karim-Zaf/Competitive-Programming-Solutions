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

const ll N = 1e5 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;

int n , p , k ; 
ll dp [1<<8][N];
vector <int> power , v  ;
vector <vector<int>> att;


ll work (int mask, int curr ){ 

    if (curr ==n ) return 0;

    ll & ret= dp[mask][curr];

    if (ret != -1 ) return ret ;

    // due to the sort
    ll s = curr - __builtin_popcount(mask);

    ret = work (mask,curr+1);

    if (s<k) ret = max (ret , power[v[curr]]+work (mask,curr+1)); 

    for (int i= 0 ; i < p ;i++)
        if (((1<<i) & mask) ==0 )
            ret = max (ret, att[v[curr]][i]+work (mask | (1<<i),curr+1));

    return ret ;
}

void solve (){
    cin >> n >> p >> k ; 
    power.resize(n);
    att.resize(n);
    memset (dp,-1 , sizeof(dp));

    for (int i= 0 ; i<n ;i++){
        cin >> power[i];
        v.pb(i);
    }

    sort (all(v),[](int x, int y ){return power[x]>power[y];});

    for (int i= 0 ; i<n ;i++)
        for (int j= 0 ;j<p ; j++){
            int x ; 
            cin >> x ; 
            att[i].pb(x) ;
        }

    cout << work(0,0)<< endl;
}   

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}