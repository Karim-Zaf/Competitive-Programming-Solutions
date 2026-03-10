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

const ll N = 5e5+ 7 , MOD =998244353, mod=998244353, Q =2e5+4 , INF = 1e18 ;

void solve (){
    int n ;
    ll x , res =0 ; 
    cin >> n >> x ; 
    ll t [3][n] ;
    for (int i= 0 ;i<3 ; i++)
        for (int j= 0 ;j<n ;j++)
            cin >> t[i][j];

    auto verif =[&] (ll a ){
        for (int i= 0 ;i<50 ;i++){
            ll one = x & (1ll<<i);
            ll two = a & (1ll<<i) ; 
            if (one==0 && two ) return false ;
        }
        return true ;
    };
        
    for (int i= 0 ;i<3 ; i++)
        for (int j= 0 ;j<n ;j++){
            if (!verif(t[i][j]|res)) break;
            res |= t[i][j];
        }

    if (res == x) cout << "YES" << endl;
    else cout << "NO" << endl;



}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}