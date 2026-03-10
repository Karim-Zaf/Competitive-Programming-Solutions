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

const ll N =2e6+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

int dp[100][2] ;

void solve(){
    int n , res= 1;
    cin >> n;
    vector <int> v(n ) ;
    for (auto &x : v) cin >> x;
    for (int i= 0 ;i<n;i++){
        dp[i][0]=dp[i][1]= 1 ;
        for (int j= 0 ;j<i ; j++){
            if (v[j] <v[i])
                dp[i][1]= max (dp[i][1],dp[j][0]+1 ) ;
            if (v[j] >v[i])
                dp[i][0]= max (dp[i][0],dp[j][1]+1 ) ;
        }
        res = max ({res, dp[i][0],dp[i][1]});
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