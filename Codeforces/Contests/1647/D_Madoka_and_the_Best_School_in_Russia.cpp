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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve() {
    int x ,d, cnt = 0, curr =1;
    cin >> x >> d;
    int nw_x  = x;
    while (x%d==0) {
        x/=d ;
        cnt ++ ;
    }
    if (cnt==1){cout << "NO\n";return;}
    for (int i=2; i*i <= x; i++)
        if (x%i==0) {cout << "YES\n"; return;}
    if (cnt==2){cout << "NO\n"; return;}
    x*= d ;
    for (int i=2; i*i <= x; i++){
        if (x%i==0&& __gcd (i,d)!=d && __gcd (x/i,d)!=d) {
            cout << "YES\n"; return;}
    }
    if (cnt==3){cout << "NO\n"; return;}
    x = d ;
    for (int i=2; i*i <= x; i++){
        if (x%i==0&& __gcd (i,d)!=d && __gcd (x/i,d)!=d) {
            cout << "YES\n"; return;}
    }
    cout << "NO\n";
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}