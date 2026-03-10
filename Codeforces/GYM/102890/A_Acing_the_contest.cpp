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
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 1e8 + 1 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

int t , p , dp[101][1030][101];
vector <int> energy, difficulty, coins;

int work ( int prob ,int masque, int ener ){
    if (prob==p) return 0 ;
    int &ret = dp[prob][masque][ener]; 
    if (ret !=-1 ) return ret ;
    ret = work(prob+1 , masque , ener);
    if (ener>= difficulty[prob]) 
        ret = max (ret , work(prob+1 , masque, ener-difficulty[prob])+ coins[prob]);
    for (int i= 0 ; i<t ; i++)
        if ( !(masque & (1<<i)) )
            ret = max (ret, work( prob , masque|(1<<i) , energy[i] ));
    return ret ;
}


void solve(){
    cin >> t >> p ;
    energy.resize(t);
    difficulty.resize(p);
    coins.resize(p);
    memset(dp,-1 ,sizeof(dp));
    for ( auto &x: energy ) cin >> x;
    for ( auto &x: difficulty ) cin >> x;
    for ( auto &x: coins ) cin >> x;
    cout << work(0,0,0) << endl;      
}

int32_t main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
   #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;

}