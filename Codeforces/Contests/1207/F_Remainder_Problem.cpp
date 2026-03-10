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

const int  N=5e5+30, sq= 750, MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int t[N] ;
int fadhel[sq][sq] ;

void Solve() {
    int  q ;
    cin >> q ;
    while (q--){
        int ind , x , y ;
        cin >> ind >> x >> y ;
        if (ind ==1){
            t[x]+= y ;
            for (int i= 1 ; i< sq ; i++) fadhel[i][x%i]+= y ;
        }else {
            if (x<sq){cout << fadhel[x][y] << endl;continue;}
            int ans = 0 ;
            for (int i= y ; i<N; i+= x) ans += t[i] ;
            cout << ans << endl;
        }
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}