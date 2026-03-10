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


int t[100][100] ;

void Solve() {
    int n, m, ans=INF;
    cin >> n >> m ;

    vector<pair<int,int>> vp (m) ;

    for (int i =1 ;i<=n ;i++)
        for (int j= 1; j<= n ; j++)
            t[i][j]=0;

    for(int i=0 ; i< m ; i++){
        cin >> vp[i].F >> vp[i].S;
        t[vp[i].F][vp[i].S]=1;
    }

    for (int i=1 ;i<=n ;i++)
        for (int j= 1; j<= n ; j++){
            int cnt = 0 ;
            for (int k= 1; k<=n;k++) {
                if (k==j)continue;
                cnt += t[i][k];
            }
            for (int k= 1; k<=n;k++) {
                if (k==i)continue;
                cnt += t[k][j];
            }
            cnt += t[i][j];
            ans = min(ans,cnt);
        }

    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}