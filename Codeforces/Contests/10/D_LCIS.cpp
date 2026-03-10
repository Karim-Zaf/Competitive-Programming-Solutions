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

const int  N=3e5+30,MOD=998244353,mod=998244353,INF=1e18+10;

vector<int> dp[2][505] ;

void Solve() {

    int n , m ;
    cin >> n ;
    vector<int> a(n+1);
    for (int i=1 ; i<=n ; i++) cin >> a[i];
    cin >> m ;
    vector<int> b(m+1), ans ;
    for (int i=1;i<=m;i++) cin >> b[i];

    auto mrg=[&] (vector<int> & one , vector<int> &two){
        if (one.size() >two.size())  return ;
        if (one.size() <two.size()) {one = two ; return ;}
        if (one.empty()) return ;
        if (one.back()>two.back()) one = two ;
    };


    for (int i=1 ; i<=n;i++){
        for (int j=1 ; j<=m ;j++){
            dp[1][j]= dp[0][j-1];
            dp[0][j-1].clear();
            if (a[i]==b[j]){
                if (dp[1][j].empty()||a[i]>dp[1][j].back()) dp[1][j].pb(a[i]);
                vector<int> nw ;
                nw.pb(a[i]);
                mrg (dp[1][j],nw);
            }
            mrg (dp[1][j], dp[0][j]);
            mrg (dp[1][j], dp[1][j-1]);
            mrg (ans , dp[1][j]);
        }
        for (int j=1; j<=m ; j++) dp[0][j]= dp[1][j], dp[1][j].clear();
    }


    cout << ans.size() << endl;
    for (auto x: ans ) cout << x << " " ; cout << endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}