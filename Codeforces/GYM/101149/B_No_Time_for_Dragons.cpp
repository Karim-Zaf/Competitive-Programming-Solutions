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
 
const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;
 
int q , dp[5001][5001] ; 
 
void solve (){
    ll n , t , res = 1 ; 
    cin >> n; 
    vector <array<ll,3>> v (n);
    for (int i= 0 ;i<n ;i++){
        ll l , r ; 
        cin >> l >> r ; 
        v[i]= {l-r,l,r}; 
    }
    sort (rall(v));
    ll curr = 0 , soliders=0 ;
    for (int i= 0 ;i<n;i++){
        if (curr <v[i][1]) {
            soliders+= abs(curr-v[i][1]);
            curr += abs(curr -v[i][1]);
        }
        curr -= v[i][2];
    }
    cout << soliders << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}