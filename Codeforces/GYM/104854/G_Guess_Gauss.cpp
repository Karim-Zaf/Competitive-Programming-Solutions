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
    int d ;
    cin>> d ;
    d*=2;
    vector <int> divisors ;
    vector< pair <int,int>> vp ;
    for (int i=1 ;i*i <= d ; i++){
        if (d%i)continue;
        divisors.pb(i);
        int j= d/i ;
        int m =  j+i -1 ;
        if (m%2||m<=0)continue;
        m/=2 ;
        int n = m-i ;
        if (n<=0||n>m) continue;
        int one = m*(m+1)/2 , two = n*(n+1)/2 ;
        if (one-two==d/2)vp.pb({n,m});
    }
    cout << vp.size()<< endl;
    for (auto x : vp )cout << x.F << " " << x.S << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}