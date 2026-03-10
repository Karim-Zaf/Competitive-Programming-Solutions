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
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define nop cout<<"-1"<<endl;
#define int ll

const ll N = 4e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

void solve() {
//    int n ;
//    cin >> n ;
//    int dp[n+1][2*n+2];
//    memset(dp,0,sizeof(dp));
//    for (int i= 0 ;i<=n; i++)
//        dp[1][i]=1 ;
//    for (int s = 1 ; s <=n ;s++) {
//        for (int x = 0; x <= 2 * n; x++) {
//            for (int j = 1; s+j <=n; j++) {
//                dp[s + j][x ^ j]+= dp[s][x];
//                dp[s][x] %= mod;
//            }
//        }
//    }
//    for (int s = 0 ; s <=n ;s++) {
//        for (int x = 0; x <= 2 * n; x++){
//            cout << dp[s][x] << " ";
//        }
//        cout << endl;
//    }
//    cout << dp[n][1] << endl;
    int n , xr= 0 ;
    cin >> n ;
    vector <int> v(n);
    for (auto &x : v) {
        cin >> x ;
        xr^= x ;
    }
    if (xr) cout << 0 << endl;
    else cout << 1 << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}


// Failure gives you two choices: You stay down or You get up ;)