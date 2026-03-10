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
    int n , k , d , cnt = 0;
    cin >> n >> k >> d ;
    vector<int> a(n+1) , v(k+1) ;
    for (int i= 1; i<=n ;i++) {
        cin >> a[i] ;
        cnt+= (a[i]==i) ;
    }
    for(int i=0 ; i< k ; i++) cin >> v[i] ;
    int ans = cnt + (d-1)/2 ;
    for (int i= 1 ; i<=min(5*n+4,d-1) ;i++){
        cnt = 0  ;
        for (int j=1; j<=v[(i-1)%k] ;j++)a[j]++;
        for (int j=1; j<= n ;j++) cnt += (a[j]==j) ;
        ans = max (ans , cnt + (d-i-1)/2) ;
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
