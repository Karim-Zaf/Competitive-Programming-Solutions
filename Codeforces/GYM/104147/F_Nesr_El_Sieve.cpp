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
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
 
const ll N = 1e5 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

void solve(){ 
    string a , b , cmp = "" ; 
    int res = 0 ;
    cin >> a >> b ; 
    if ( a.size()<= b.size()) swap (a,b);

    for (int i= 0 ; i<b.size() ; i++){
        cmp += b[i]; 
        string nw = "" , nw2="" ;
        while (nw.size()< a.size()) nw += cmp ; 
        while (nw2.size()< b.size()) nw2 += cmp ; 
        if ( nw== a && nw2== b) res = max (res , (int)(cmp.size()) );
    }
    cout << res << endl;
}
 
int32_t main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    // #endif
    freopen("sieve.in", "r",stdin);
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}