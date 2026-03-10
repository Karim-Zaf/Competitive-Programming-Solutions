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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

void Solve() {
    int n , c , ans = 0;
    cin >> n >> c ;
    vector<int> v(n+3) , suff(n+5) , pref(n+5) ;
    map<int,vector<int>> mp ;
    for (int i=1 ;i<= n ;i++){
        cin>> v[i] ;
        pref[i]=suff[i]=v[i]==c ;
        mp[v[i]].pb(i);
    }
    for (int i= 1 ;i<=n;i++) pref[i]+= pref[i-1] ;
    for (int i=n ;i>=1 ;i--) suff[i]+= suff[i+1] ;

    for (auto [x, vec] : mp){
        int mx = 0 , cnt = 0;
        for (auto pos : vec){
            mx = max (mx, pref[pos-1]-cnt);
            cnt ++ ;
            ans = max (ans, cnt+ mx+ suff[pos+1]);
        }
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}