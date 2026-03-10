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
    int n , k , g = -1, ans = 0;
    int one = 0  , two = 0 ;
    cin >> n >> k ;
    vector<int> v(n);
    for (auto &x: v) {
        cin >> x;
        if (g==-1) g=x-k;
        if (x-k<0)one ++ ;
        else if (x-k>0) two ++ ;

        g = __gcd (g,x-k);
    }
    sort(all(v));
    if (v[0]==v.back()){cout << 0 << endl ; return;}
    if (one && two || g==0) {cout << -1 << endl;return;}
    for (auto x: v) {
        if ((x-k)==0){cout << -1 << endl; return;}
        int haja = abs ((x-k) / g) ;
        int f = g + k ;
        if (x==f) continue;
        ans += --haja ;
    }
    cout << max( -1ll,ans) << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}