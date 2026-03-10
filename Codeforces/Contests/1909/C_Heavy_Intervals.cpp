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
    int n ;
    cin >> n ;
    vector<int> l(n),  r(n), c(n) , inter;
    multiset<int> lll ;
    for (auto &x: l){
        cin >> x;
        lll.insert(x);
    }
    for (auto &x: r) cin >> x ;
    for (auto &x: c) cin >> x ;
    sort (all(l));
    sort (all(r));
    sort (rall(c));

    int ans = 0 ;

    for (int i= 0  ; i<n;i++){
        int lef = *(prev(lll.upper_bound(r[i])));
        lll.erase( lll.find(lef));
        inter.pb(r[i]-lef);
    }
    sort (all(inter));
    for (int i= 0  ; i<n;i++) ans += inter[i]*c[i] ;
    assert (ans>0);
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}