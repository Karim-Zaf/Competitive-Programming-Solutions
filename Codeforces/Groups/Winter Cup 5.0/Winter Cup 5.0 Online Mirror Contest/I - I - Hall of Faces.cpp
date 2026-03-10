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
    int n , ans = INF;
    string s;
    cin >> n >> s;
    map<string,vector<int>> mp ;
    for (int i= 0 ; i<n ;i++){
        string nw ;
        cin >> nw ;
        mp[nw].pb(i);
    }

    int pos = mp["Jaqen"].back();

    if (mp[s].empty()){cout<<-1<<endl;return;}

    for (auto x: mp[s]){
        int diff = x -pos;
        ans = min({ans , abs(diff) , n-abs(diff)});
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}