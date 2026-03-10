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

vector<int> v{15,10,6,3,1};
vector<pair<int,int>> vp ;

void Solve() {
    int n , cnt = 0;
    cin>> n ;
    vector<int> dp(105,INF);
    dp[0]=0 ;
    for (int i= 1 ; i<=100 ; i++){
        for (auto x: v){
            if (i-x>=0){
                dp[i]= min (dp[i],dp[i-x]+1);
            }
        }
    }
    int ans = n/15 ;
    kar (ans);
    ans-= 4 ;
    ans = max(0ll,ans);
    n-= ans*15 ;
    ans += dp[n] ;
    cout << ans << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;

    for (int i= 1; i<(1ll<<5);i++){
        int cnt = 0,nb= 0;
        for (int j= 0 ;j<5; j++){
            if ((1ll<<j)&i){
                cnt += v[j];
                nb++;
            }
        }
        vp.pb({cnt,nb});
    }
    sort (rall(vp));
    kar (vp)
    while (Test_case--) Solve();
}