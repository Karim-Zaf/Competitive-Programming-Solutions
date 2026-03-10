/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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
 
const ll N =1e6+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
void solve() {
    array <int,4> v ;
    for (int i= 0 ;i<4 ;i++) cin >> v[i];
    if (v[0]+ v[1]==v[2]+ v[3]) cout<< "YES\n";
    else if (v[0]+ v[2]==v[1]+ v[3]) cout <<"YES\n";
    else if (v[0]+ v[3]==v[2]+ v[1]) cout <<"YES\n";
    else if (v[1]+ v[2]==v[0]+ v[3]) cout <<"YES\n";
    else if (v[1]+ v[3]==v[0]+ v[2]) cout <<"YES\n";
    else if (v[2]+ v[3]==v[1]+ v[0]) cout <<"YES\n";
    else cout <<"NO\n";
 
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}