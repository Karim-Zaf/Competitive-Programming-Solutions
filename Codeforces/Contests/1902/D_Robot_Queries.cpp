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

const int  N=1e6 + 5 ,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    map<pair <int,int>, vector<int>> pref, suff;
    int n , q , currx=0 , curry= 0;
    string s;
    cin >> n >> q >> s;
    s= '#'+s ;
    vector <pair <int,int>> vp (n+1), vekh(n+4);
    pref[{0,0}].pb(0);
    suff[{0,0}].pb(n+1);
    for (int i= 1 ; i<=n ;i++){
        if (s[i]=='R') currx++;
        if (s[i]=='L') currx--;
        if (s[i]=='U') curry ++;
        if (s[i]=='D') curry --;
        pref[{currx,curry}].pb(i);
        vp[i]= {currx,curry};
    }
    currx=curry=0;
    for (int i= n ; i>=1 ;i--){
        if (s[i]=='R') currx++;
        if (s[i]=='L') currx--;
        if (s[i]=='U') curry ++;
        if (s[i]=='D') curry --;
        suff[{currx,curry}].pb(i);
        vekh[i]= {currx,curry};
    }
    for (auto x : suff)sort(all(suff[x.F]));

    while (q--){
        int x, y , l ,r  ;
        cin >> x >> y >> l >> r ;
        if (!pref[{x,y}].empty()){
            int deb = pref[{x,y}][0];
            int fin = pref[{x,y}].back();
            if (deb < l || fin >r ) {cout << "YES\n"; continue;}
        }
        currx= vp[l-1].F , curry = vp[l-1].S ;
        int findx = x - currx+vekh[r+1].F, findy = y - curry +vekh[r+1].S;
        vector<int> &vect = suff[{findx,findy}];
        int pos = lower_bound(all(vect),l)-vect.begin();
        if (pos<vect.size()&& vect[pos]<=r)cout << "YES\n";
        else cout << "NO\n";
    }


}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}