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
    int n ;
    cin >> n ;
    vector <int> v(3*n+1) ;
    for (int i= 1; i<=3*n ;i++) cin >> v[i] ;
    sort (rall(v));
    for (int i= 1; i<= 3*n ; i+=3) {
        if (v[i]!=v[i+1]){cout << "Y\n";return;}
    }
    cout <<"N\n";

}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
