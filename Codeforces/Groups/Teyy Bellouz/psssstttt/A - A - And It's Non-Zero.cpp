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

int aa[N][22];

void Solve() {
    int cnt=0 , a, b ;
    cin >> a >> b ;
    for (int i= 0 ; i<22 ; i++){
        cnt = max (cnt , aa[b][i]-aa[a-1][i]) ;
    }
    cout << b-a+1 - cnt <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    for (int j= 0 ; j<21 ; j++){
        for (int i= 1 ; i<N ; i++){
            aa[i][j]=aa[i-1][j]+((i&(1ll<<j))!=0);
        }
    }
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}