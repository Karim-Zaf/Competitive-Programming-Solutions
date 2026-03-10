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


void Solve(){
    int n , res= 0;
    cin >>n ;
    vector<int> v(n+1) ;
    for (int i= 1; i<=n ; i++) cin >> v[i];
    for (int i= 1 ; i*i <= n; i++){
        if (n%i) continue;
        int d = i ;
        int mx = -INF, mn = INF , sum =0;
        for (int j =1 ; j<=n ;j++){
            sum += v[j];
            if (j%d==0) {
                mn = min(sum , mn) ;
                mx= max (sum, mx);
                sum= 0 ;
            }
        }
        d= n/i ;
        res = max (res , mx -mn);
        mx = -INF , mn = INF , sum = 0 ;
        for (int j =1 ; j<=n ;j++){
            sum += v[j];
            if (j%d==0) {
                mn = min(sum , mn) ;
                mx= max (sum, mx);
                sum= 0 ;
            }
        }
        res = max (res , mx -mn);
    }
    cout << res << endl ;


}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
        freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}