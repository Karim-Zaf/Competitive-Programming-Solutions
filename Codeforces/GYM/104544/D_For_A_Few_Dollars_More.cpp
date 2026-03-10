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
#define in ll;
 
const long long N=2e5+47,MOD=1e9+7,mod=1e9+7,INF=1e18;
 
 
void Solve(){
    double  y , x ;
    cin >> x>> y ;
 
    if (y==100){
        if (x) cout << -1 << endl;
        else cout << 0 << endl;
    }else cout << x+ (int)(ceil((x*y)/(100.0 -y))) << endl;
 
 
}
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}