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

const int  N=2e7+30,NN = 5e5, MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    int n;
    cin >> n ;

    vector <int> v(n+4) , pref(n+4);
    map <int,vector<pair <int,int>>> dp;
    for (int i= 1; i<=n ; i++){
        cin >> v[i] ;
        pref[i]= v[i];
        pref[i]+= pref[i-1];
    }
    for (int i= 1; i<=n; i++){
        for (int j= 0 ; j<i;j ++){
            if (dp[pref[i]-pref[j]].size()==0||
            j>= dp[pref[i]-pref[j]].back().S)dp[pref[i]-pref[j]].pb({j+1,i});
        }
    }
    int sz = -INF ;
    for (auto [val , vect] : dp){
        if (vect.size()>dp[sz].size())sz = val ;
    }
    cout << dp[sz].size() << endl;
    for (auto [one,two]: dp[sz])
        cout << one << " " << two << endl;

}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}