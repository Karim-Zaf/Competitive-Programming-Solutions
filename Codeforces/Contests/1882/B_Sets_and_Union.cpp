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

const int  N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;


void Solve(){
    int n , res= -1 ;
    cin >> n ;
    map <int,set <int>> mp ;
    vector <int> v[n];
    set <int> s ;
    for (int i= 0 ;i<n;i++){
        int x ;
        cin >> x;
        for (int j= 0;j<x;j++){
            int nw ;
            cin >> nw ;
            v[i].pb(nw);
            mp[nw].insert(i);
            s.insert(nw);
        }

    }
    for (auto x : s){
        kar (mp[x]);
        set <int> nw_s ;
        for (int i= 0 ;i<n;i++){
            if (mp[x].find(i)!=mp[x].end())continue;
            for (auto jdid : v[i]) nw_s.insert(jdid);
        }
        res = max (res , (ll)nw_s.size());
    }
    cout <<res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while(Test_case--)Solve();
}