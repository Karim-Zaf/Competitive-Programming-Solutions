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

const int  N=2e4+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int query (vector<int> & v){
    cout << "? " ;
    for (auto x: v) cout << x << " " ; cout << endl;
    cout.flush() ;
    int x ;
    cin >> x ;
    return x ;
}

void Solve() {
    vector<int> a ,b ;
    int one = ((1<<14) -1)>>7 ,ans = 0;
    int two = one ; two<<= 7 ;

    for (int i= 0 ; i< 100 ; i++){
        a.pb(one+(i<<7)) ;
        b.pb(two+i) ;
    }
    one = query (a) ;
    two = query (b) ;
    for (int i= 0 ; i<7 ; i++) if (!((1ll<<i) & one))ans += (1ll<<i) ;
    for (int i= 7 ; i<14 ; i++) if (!((1ll<<i) &two))ans += (1ll<<i) ;
    cout << "! " <<ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}