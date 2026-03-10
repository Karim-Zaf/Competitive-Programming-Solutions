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
#include "debug.h"
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

const int  N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e17;


void Solve() {
    int  n , d , res = 0 ;
    cin >> n >> d ;
    vector <int> v(n) , vis(n);
    for (auto &x: v) cin>> x;
    for (int i= 0 ; i<n ;i++){
        if (vis[i]) continue;
        vector <int> nw_v, s ; set <int> verif ;
        for (int j= i ; !vis[j]; j=(j+d)%n) {
            nw_v.pb(v[j]);
            verif.insert(v[j]);
            vis[j]=1 ;
        }
        if (verif.size()==1 && *verif.begin()){cout << -1 << endl;return ;}
        for (auto x: nw_v) s.pb(x);
        for (auto x: nw_v) s.pb(x);
        for (auto x: nw_v) s.pb(x);
        int j=0 , sz = s.size();
        while (j<sz){
            while (j<sz && !s[j])j++;
            int cnt = j ;
            while (j<sz && s[j])j++;
            res = max (res,j-cnt);
        }
    }
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}