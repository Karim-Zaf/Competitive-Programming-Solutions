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
#define int ll

const long long N=21,MOD=1e9+7,mod=1e12+7,INF=1e18;


void Solve(){
    int n, m , res= 0;
    cin >> n >> m ;
    vector<int> v[3] ;
    set<int> meet_in_the_middle[2] ;
    v[0].resize(n);
    for (auto &x:v[0]) cin>> x;
    for (int i= 0 ;i<n/2 ;i++)v[1].pb(v[0][i]);
    for (int i= n/2 ;i<n ;i++)v[2].pb(v[0][i]);
    for (int i= 0 ;i<(1<<v[1].size());i++){
        int cnt= 0;
        for (int j= 0; j<v[1].size(); j++)
            if (i&(1<<j))cnt+=v[1][j];
        meet_in_the_middle[0].insert(cnt%m);
    }
    for (int i= 0 ;i<(1<<v[2].size());i++){
        int cnt= 0;
        for (int j= 0; j<v[2].size(); j++)
            if (i&(1<<j))cnt+=v[2][j];
        meet_in_the_middle[1].insert(cnt%m);
    }

    for (auto &x: meet_in_the_middle[0]){
        auto it = meet_in_the_middle[1].lower_bound(m-x);
        if (it==meet_in_the_middle[1].begin())continue;
        else res = max (res , x+ *prev(it));
    }
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}