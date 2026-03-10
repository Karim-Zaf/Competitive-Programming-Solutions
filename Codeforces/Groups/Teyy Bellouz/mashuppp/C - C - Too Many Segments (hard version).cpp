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


void Solve(){
    int n ,k , curr = 0 ;
    cin >> n >> k ;
    vector <pair<int,int>> vp (n) ;
    map<int,int>mp ;
    map <int, vector <pair<int,int>>> mpv ;
    map <int, vector <pair<int,int>>> mpo ;
    multiset<pair<int,int>> s ;
    set<int> res ;
    int i =0 ;
    for (auto &x: vp) {
        i++;
        cin >> x.F >> x.S;
        mp[x.F]++;
        mp[x.S+1]--;
        mpv[x.F].pb({x.S + 1, i});
        mpo[x.S+1].pb({x.S + 1, i});
    }
    for (auto [x,val]: mp){
        curr += val ;
        for (auto nw :mpv[x]) s.insert(nw);
        while  (curr>k){
            int rass = (*prev(s.end())).F ;
            res.insert((*prev(s.end())).S);
            s.erase(*prev(s.end()));
            mp[rass]++;
            curr--;
        }
        while (!s.empty() && (*s.begin()).F<=x) s.erase(*s.begin());
    }
    cout<< res.size() << endl;
    for (auto x: res) cout << x << " " ; cout << endl;
}


int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
    freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
#endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}