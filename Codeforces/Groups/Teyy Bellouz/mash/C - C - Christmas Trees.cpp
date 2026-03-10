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


void Solve() {
    int n , m ;
    cin >> n >>m ;
    vector <int> Trees, droite(n+3), gauche (n+4) ;
    set <array <int,3>> vp ;
    set <int> ans ;


    Trees.pb(-INF) ;
    for (int i= 1 ; i<=n; i++){
        int x ; cin >> x; Trees.pb(x);
    }
    Trees.pb(INF) ;


    sort(all(Trees));
    for (int i= 1 ;i<= n ; i++){
        droite [i] = (Trees[i+1] -Trees[i]-1)/2 ;
        gauche[i]= (Trees[i] -Trees[i-1]-1) - droite[i-1];
        vp.insert({gauche[i],Trees[i],-1});
        vp.insert({droite[i],Trees[i],1});
    }


    while ((*vp.begin())[0]<=0)vp.erase(*vp.begin());
    int sz = 1 ,res = 0;
    auto it = vp.begin() ;
    while (true){
        array <int,3> rass = *it ;
        ans.insert(rass[1]+sz*rass[2]);
        res += sz ;
        if (ans.size()>=m) break;
        it++;
        if (it!= vp.end())continue;
        while ((*vp.begin())[0]<=sz)vp.erase(*vp.begin());
        sz++ ;
        it = vp.begin();
    }
    cout << res << endl;
    for (auto x: ans ) cout << x << " " ; cout << endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}