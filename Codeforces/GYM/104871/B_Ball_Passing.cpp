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
#define ld long double
#define endl '\n'

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

ld dist (pair<int,int> x, pair<int,int> y ){
    return sqrtl((x.F -y.F)*(x.F-y.F)+ (x.S-y.S) *(x.S-y.S)) ;
}


void Solve() {
    int n;
    ld ans = 0 ;
    string s ;
    cin >> n >> s;
    vector<int> v[2] ;
    for (int i=0; i<n ; i++){
        if(s[i]=='B') v[0].pb(i) ;
        else v[1].pb(i);
    }

    vector<pair<int,int>> vp (n) ;

    for (int j= 0; j<n ;j++){
        cin >> vp[j].F >> vp[j].S ;
    }


    int b = v[0].size() , g = v[1].size();
    for (int i = 0 ; i<b/2 ; i++){
       ans += dist(vp[v[0][i]],vp[v[0][i+b/2]]);
    }
    for (int i = 0 ; i<g/2 ; i++){
        ans += dist(vp[v[1][i]],vp[v[1][i+g/2]]);
    }
    cout <<fixed << setprecision(7) << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}