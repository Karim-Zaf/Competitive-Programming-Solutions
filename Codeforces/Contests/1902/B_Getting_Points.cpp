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

const int  N=2e5,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    int n ,p , l , t;
    cin >> n >> p >> l >> t ;
    int lef =0 , righ= n ,res = 0 ;
//        int tasks = (n+6)/7 ;
//        int done = 2*(tasks /2)  ;
//        kar (done);
//        int md= 0;
//        if (tasks/2 <md)done +=tasks%2 ;
//        int cnt = md * l + done*t;
//        kar (cnt);
    while (lef<=righ ){
        int md = lef + (righ-lef)/2 ;
        int tasks = (n+6)/7 ;
        int done = 2*min (md, (tasks /2))  ;
        if (tasks/2 <md)done +=tasks%2 ;
        int cnt = md * l + done*t;
        if (cnt >= p ){
            righ = md -1 ;
            res = md ;
        }else lef = md +1;
    }
    kar (res);
    cout << n - res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}