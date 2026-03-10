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

const int  N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;


void Solve() {
    int n , k , gmara= 1 , cherche = 1, cnt = 0;
    cin >> n >> k ;
    vector <pair <int,int>> t[2] ;
    vector <int> v(n) ;
    for (auto &x: v) cin >> x ;


    if (v[0]!=1) {
        t[0].pb({1, v[0]-1});
        t[1].pb({1, v[0]-1});
        gmara = v[0] ;
    }
    for (int i= 1 ; i<v.size() ; i++){
        if (v[i-1]< v[i]-1) {
            t[0].pb({v[i-1]+1,v[i]-1});
            int sz = v[i]- v[i-1]-1 ;
            t[1].pb({gmara , gmara + sz-1});
            gmara += sz ;
        }
    }

    t[0].pb({v.back()+1,INF});
    t[1].pb({gmara, INF}) ;
    while (k--){
        pair <int,int> p =make_pair ( cherche ,  INF+1) ;
        int pos = lower_bound(all(t[1]),p) - t[1].begin()-1 ;
        cherche = t[0][pos].F + cherche - t[1][pos].F ;
    }

    cout << cherche << endl;



}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--)Solve();
}