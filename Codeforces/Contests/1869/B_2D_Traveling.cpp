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



const long long N=2e5+8,MOD=1e9+7,mod=1e12+7,INF=1e18;



void Solve(){
   int n , k , a , b;
   cin >> n >> k >> a >> b;
   vector<pair <int,int>> vp (n) ;
   vector <int> v [2];
   a-- ; b-- ;
   for (int i= 0; i<n ;i++) cin >>vp[i].F >> vp[i].S ;
   for (int i= 0 ;i<k ; i++){
       v[0].pb(abs(vp[i].F-vp[a].F)+abs(vp[i].S-vp[a].S));
       v[1].pb(abs(vp[i].F-vp[b].F)+abs(vp[i].S-vp[b].S));
   }

   sort (all(v[0]));
   sort (all(v[1]));
   int res = abs(vp[a].F-vp[b].F)+abs(vp[a].S-vp[b].S);
   if (v[0].empty()) {
        cout << res << endl;
        return;
   }
   cout << min( res ,v[0][0]+ v[1][0]) << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}