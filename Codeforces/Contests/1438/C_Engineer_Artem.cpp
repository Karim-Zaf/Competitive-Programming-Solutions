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

int t[110][110];

void Solve() {
    int n , m ;
    cin >> n >> m ;
    for (int i= 0 ; i<= n+4; i++)
        for (int j= 0 ;j <= m +5 ;j ++)
            t[i][j]=-INF ;
    map <int,int> mp ;
    for (int i= 1 ;i<= n; i++)
        for (int j= 1 ;j<=m ;j++)
            cin >> t[i][j];

    for (int i= 1 ;i<= n; i++)
        for (int j= 1+(i%2) ;j<=m ;j+=2)
            if (t[i][j]%2) t[i][j]++;

    for (int i= 1 ;i<= n; i++)
        for (int j= 1+(i%2==0) ;j<=m ;j+=2)
            if (t[i][j]%2==0) t[i][j]++;


    for (int i= 1; i<=n ; i++){
        for (int j=1 ; j<= m ;j++)
            cout << t[i][j] << " " ;
        cout << endl;
    }
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}