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

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+6;





void Solve(){
    int n , q;
    cin >> n>> q ;
    vector <int> v(n), x(q), next (q) ;
    vector <pair <int,int> > mp[40] ;


    for (auto & e : v) cin >> e ;
    kar (v);
    for (int i= 0 ; i<q; i++){
        int z ; cin >> z ;
        for (int j= 30 ; j>= z ;j--)
            mp[j].pb({i,z});
    }

//    for (int i= 0 ;i<30 ; i++){
//        kar (mp[i])
//    }
    for (auto &e : v) {
        int bit ;
//        kar (e);
        for (int i= 30 ; i>=0; i--)
            if ( e & (1<<i))
                bit = i ;
        int curr = -1 ;
//        kar (bit);
        while (true){
            pair <int,int> p = {curr,INF};
            int pos = upper_bound (all(mp[bit]),p ) -mp[bit].begin() ;
            if (pos == mp[bit].size()) break;
//            kar (mp[bit][pos]);
            curr= mp[bit][pos].F ;
//            kar (curr);
//            kar (pos);
//            kar (bit)
//            kar (mp[bit]);
//            kar (e);
            e += (1<<(mp[bit][pos].S-1));
            bit = mp[bit][pos].S-1;
        }
//
//
    }


    for (auto e: v) cout << e << " " ; cout << endl;

}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}