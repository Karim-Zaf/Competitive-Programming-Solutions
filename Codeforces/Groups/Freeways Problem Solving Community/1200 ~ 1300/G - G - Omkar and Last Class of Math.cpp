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
#define int long long
#define ld long double
const long long N=1e3+8,MOD=1e9+7,mod=1e9+7,INF=1e18;


int dp[N][N] ;

void Solve(){
    int n ; cin >> n ;
    int l ,r;
    int mx = INF ;
    for (int i=1 ; i*i <=n; i++){
        if (n%i) continue;
        int d=i ;
        int res =  d*(n-d)/__gcd(d,n-d);
        if (res<=mx){
            l = d ; r= n-d ;
            mx = res ;
        }
        d =n/i;
        res = d*(n-d)/__gcd(d,n-d);
        if (d==n) continue;
        if (res<=mx){
            l = d ; r= n-d ;
            mx = res ;
        }
    }
    cout << l <<" " << r<<  endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}