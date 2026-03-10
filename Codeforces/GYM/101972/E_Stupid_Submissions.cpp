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
 
const ll N = 1e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
void solve(){
    int n , m , k , res= 0 ;
    cin >> n >> m >> k ;
    vector<char> v(n);
    for (auto &x: v) cin>> x;
    while (m--){
        char c ; int curr ;
        cin >> c  ;
        if (c == 'A') {
            k = n+1; continue;
        }
        cin >> curr;
        if (curr <= k && v[curr-1]=='S') res ++;
        k = max (k , curr);
    } cout << res << endl;
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