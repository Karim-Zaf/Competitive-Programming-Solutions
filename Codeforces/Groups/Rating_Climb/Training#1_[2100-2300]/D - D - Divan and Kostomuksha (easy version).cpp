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

int mp[N] , dp[N], v[N], cnt[N];

void Solve() {
    int  n , res;
    cin >> n ;
    for (int i = 1; i<= n ; i++){
        cin>> v[i];
        mp[v[i]]++;
    }
    res = n ;
    for (int i= 1; i<N ; i++)
        for (int j= i; j<N ;  j+=i)
            cnt[i]+= mp[j];

    for (int i= N-1; i>=1 ; i--){
        dp[i]=cnt[i]*i ;
        for (int j= i+i; j<N ;  j+=i)
            dp[i]= max(dp[i],dp[j]+(cnt[i]- cnt[j])*i);
        res = max (res, dp[i]);
    }
    cout << res << endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}