/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
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
 
const ll N = 3e5+ 7 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
#define int ll
void solve(){
    int n , res = 0 ; 
    cin >> n ; 
    vector <int> v(2*n+1);
    for (int i= 1 ;i<=2*n ; i++)cin >> v[i];
    for (int i= n+1 ;i<=2*n ; i++){
        res = max (res, v[i]+ v[2*n-i+1]);
    }
    cout << res << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}
 
 
 
 
// Failure gives you two choices: You stay down or You get up ;)