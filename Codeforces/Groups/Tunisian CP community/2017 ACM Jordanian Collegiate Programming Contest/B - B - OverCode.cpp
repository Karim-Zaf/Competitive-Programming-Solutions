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

void Solve() {
    int n ;
    cin >> n ;
    vector<int >v (n) ;
    for (int i= 0 ; i<n ;i++)cin >> v[i] ;
    sort (all(v)) ;
    int cnt = 0 , i= 5 ;
    while (i<n){
        int x = v[i-5] ;
        if (abs (v[i]-x)<=1000){
            cnt ++ ;
            i+= 6 ;
        }else i++ ;
    }
    cout << cnt << endl;
}

int32_t main(){
    freopen("overcode.in","r",stdin);
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}