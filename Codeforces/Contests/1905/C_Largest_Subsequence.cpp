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

const int  N=1e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    int n ;
    string s , nw="", verif;
    cin >> n >> s ;
    vector<int> blayes ,pos [27];
    int curr = 0;
    int prev= 0;
    for (int j=0; j<n ;j++)pos[s[j]-'a'].pb(j);
    for (int c = 26 ; c>=0 ; c--){
        int ps = lower_bound(all(pos[c]),prev)-pos[c].begin();
        for (int j=ps ; j<pos[c].size();j++){
            blayes.pb(pos[c][j]);
            nw+= char (c+'a');
            prev = pos[c][j] ;
        }
    }

    reverse(all(nw));
    verif = s;
    for (int i= 0;i<blayes.size();i++){
        verif[blayes[i]]= nw[i];
    }
    string srt = s ;
    sort(all(srt));
    if (srt != verif){cout << -1 << endl; return;}
    char c = nw.back();
    int res = nw.size();
    for (auto x : nw) res-= (x==c) ;
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