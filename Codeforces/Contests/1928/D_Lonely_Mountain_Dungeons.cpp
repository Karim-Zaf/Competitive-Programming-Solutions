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

int pairs (int kwer, int blasa){
    int ans = kwer*(kwer-1) /2 ;
    if (kwer<=blasa) return ans ;
    int init = kwer/blasa;
    ans -= blasa*init * (init-1)/2 ;
    int reste = kwer%blasa ;
    ans += reste* init* (init-1)/2 ;
    ans -= reste* init*(init+1)/2 ;
    return ans ;
}

void Solve() {
    int n , b , x ;
    cin >> n >> b >> x;
    vector<int> res, v(n) ;
    for (auto &xx: v) cin >> xx;
    int mx = *max_element(all(v));
    res.resize(mx+2) ;


    for (auto xx : v ) res[xx]+= pairs (xx,xx)*b ;
    for (int i= 1; i<= mx+1 ; i++) res[i]+= res[i-1] ;
    for (int i= 1; i<= mx+1 ; i++) res[i]-= (i-1)*x ;

    for (auto xx: v )
        for (int i= 1 ; i< xx; i++ )
            res[i]+= pairs (xx,i)*b ;

    cout << *max_element(all(res))<< endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}