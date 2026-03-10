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

const int  N=2e5+30,NN = 5e5, MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve() {
    int n ;
    cin >> n ;
    vector <array <int,3>> one , two , vp(n);
    vector <int> res (n ,- 1 ) ;
    set <pair <int,int>> pref [n], pref2[n];

    for (int i= 0 ; i<n ;i++){
        cin >> vp[i][0] >> vp[i][1] ;
        vp[i][2]=i;
        one.pb(vp[i]);
        two.pb({vp[i][1] , vp[i][0], vp[i][2] });
    }

    sort (all(one));
    sort (all(two));

    pref2[0].insert( {one[0][1],0});
    for (int i= 1; i<n;i++){
        pref2[i]= pref2[i-1] ;
        pref2[i].insert( {one[i][1],i});
        while (pref2[i].size()>=4 ) pref2[i].erase(*prev(pref2[i].end()));
    }

    for (int i= 1;i<n ;i++){
        array<int,3>  p = {one[i][0] , -INF , INF } ;
        int pos = lower_bound (all( one), p )-one.begin();
        pos-- ;
        if (pos <0 || res[one[i][2]]!=-1) continue;
        for (auto [val,pss] : pref2[pos]){
            if ( one[i][1] > one[pss][1] && one[i][2]!= one[pss][2]) res[one[i][2]] = one[pss][2]+1;
        }
    }

    pref[0].insert( {two[0][1],0});
    for (int i= 1; i<n;i++){
        pref[i]= pref[i-1] ;
        pref[i].insert( {two[i][1],i});
        while (pref[i].size()>=4 ) pref[i].erase(*prev(pref[i].end()));
    }

    for (int i= 0; i<n;i++) {
        array<int,3>  p = {one[i][0] , -INF , INF } ;
        int pos = lower_bound (all( two), p )-two.begin();
        pos-- ;
        if (pos <0 || res[one[i][2]]!=-1) continue;
        for (auto [val,pss] : pref[pos]){
            if ( one[i][1] > two[pss][1] && one[i][2]!= two[pss][2]) res[one[i][2]] = two[pss][2]+1;
        }
    }

    for (auto x: res ) cout << x << " " ; cout << endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}