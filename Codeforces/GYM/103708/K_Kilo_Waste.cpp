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

const int  N=5e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

bool dp[N] ;

void Solve() {
    int n, k ;
    cin >> n >> k ;
    vector<int> v(k) ,ans;
    for (auto &x : v) cin >> x;
    dp[0]= true;
    for (int i=0 ;i<N;i++){
        for (int c : v){
            if (i-c<0) continue;
            dp[i]|= dp[i-c];
        }
        if (dp[i])ans.pb(i);
    }
    while (n--){
        int x ;
        cin >> x;
        int pos = lower_bound(all(ans),x)-ans.begin() ;
        cout << ans[pos]-x << endl;
    }

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
