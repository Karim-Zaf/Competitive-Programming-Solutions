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

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve(){
    int n , res = 0 ;
    cin >> n ;
    vector <int> v(2*n) ;
    vector <pair<int,int>> vp(n) ;
    for (auto &x: v) cin>> x ;
    sort (all(v));

    for (int i= 0 ; i<n ;i++) {
        vp[i].F = v[i];
        if (i)res += (v[i]-v[i-1]);
    }
    for (int i= n ; i<2*n ;i++) {
        vp[i-n].S = v[i];
        if (i>n)res += (v[i]-v[i-1]);
    }
    cout << res << endl;
    for (auto [one,two] : vp) cout << one << " " << two << endl;



}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
