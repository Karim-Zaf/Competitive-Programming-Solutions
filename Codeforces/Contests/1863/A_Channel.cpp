/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
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
#define int long long
 
const long long N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;


void Solve() {
    int n , a , q , cnt = 0;
    string s ;
    
    cin >> n >> a >> q >> s;
    int mx = a ;
    cnt = a ;
    for (auto c :s ) {
        cnt += (c=='+');
        a += (c=='+');
        a -= (c=='-');
        mx = max (a,mx);
    }
    if (mx>=n){cout << "YES\n";return;}
    if (cnt>=n){cout << "MAYBE\n";return;}
    cout << "NO\n";
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}