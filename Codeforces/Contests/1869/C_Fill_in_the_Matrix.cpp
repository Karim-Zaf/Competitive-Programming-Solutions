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
#define endl '\n'
#define int ll



const long long N=2e5+8,MOD=1e9+7,mod=1e12+7,INF=1e18;



void Solve(){
    int n ,m  ;
    cin >> n >>m ;
    int res = min( m , n+1 );
    if (m==1) {
        for (int i= 0; i<n+1; i++) cout << 0 << endl;
        return;
    }
    int t [n][m] ;
    for (int i= 0 ; i<res-1;i++){
        int k= 0 ;
        for (int j=i;j<i+res ;j ++)
            t[i][j%res]=k++ ;
        for (int j=res; j< m ;j++)
            t[i][j]= j;
    }
    for (int k= res-1 ; k<n;k++)
        for (int j=0 ;j<m;j++) {
            t[k][j] = t[k - 1][j];
        }
    cout << res << endl;
    for (int i= 0 ;i<n;i++){
        for (int j= 0; j<m;j++)
            cout << t[i][j]<< " " ;
        cout << endl;
    }
}

int32_t main(){
    
//    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}