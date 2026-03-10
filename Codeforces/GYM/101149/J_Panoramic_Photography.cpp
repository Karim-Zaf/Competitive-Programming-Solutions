/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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

const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;


void solve (){
    ll n ;
    ll res = 0 ; 
    cin >> n; 
    vector <ll> v(n+1) ;
    map <ll,vector <ll>> pos ; 
    set < array<ll ,3> > t ;
    // pos[0].pb(0);
    for (ll i= 1 ;i<=n ;i++) {
        cin >> v[i];
        pos[v[i]].pb( i ) ; 
    }

    t.insert({1,n,0});
    // kar (t);

    for (auto [key,val] : pos ){
        for (auto x : val){
            array <ll,3> p ={x+1,0,0};
            auto it = t.lower_bound(p) ;
            auto it_ekher = it ;
            if (it == t.begin()|| t.empty() )continue;
            it--;
            if (x>(*it)[1]|| x<(*it)[0]) continue;
            array <ll,3> curr = *it;
            res += key - curr[2] ;
            if (t.begin()!=it_ekher)
                t.erase(curr);
            if (curr[0]<x)   
                t.insert({curr[0],x-1,key});
            if (curr[1]>x)   
                t.insert({x+1,curr[1],key});
        }
        // kar (t);
    }
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}