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
 
const int  N=5e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;
 
void Solve() {
    int n ;
    cin >> n ;
    vector <int> c(n ) , p(n);
 
    for (auto &x: c) cin >> x;
    for (auto &x: p) cin >> x;
 
    int l =0, r = MOD , res = -1;
 
    auto ok=[&] (int x )-> bool {
        int curr = 0;
        for (int i= 0 ; i<n ; i++){
            curr += p[i];
            if (c[i]*x> curr) return false ;
            else curr -= c[i]*x ;
        }
        return true ;
    };
 
    while (l<=r){
        int md= l + (r-l)/2 ;
        if (ok(md)){
            res = md ;
            l = md+1 ;
        }else r = md -1;
    }
 
 
    cout << res << endl;
}
 
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}