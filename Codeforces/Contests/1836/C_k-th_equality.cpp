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
 
const ll N = 1e7 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;


void solve(){ 
    long long  a , b , c , k , cnt = 0  ; 
    cin >> a >> b >> c >> k ; 

    long long la = pow (10, a-1) , ra = pow(10,a) - 1 ;
    long long lb = pow(10,b-1), rb = pow(10,b)-1; 
    long long lc = pow(10,c-1), rc = pow(10,c)-1; 

    for (long long curr = la ; curr <= ra ; curr ++){

        long long left = max (lb , lc- curr ) ; 
        long long right = min (rb , rc - curr ) ;
        long long intervalle = right -left +1 ;

        if (intervalle <0 ) continue;


        if (cnt+ intervalle >= k ){
            long long nw =  left + k- cnt  - 1 ; 
            cout << curr << " + " << nw << " = " << nw + curr  << endl;
            return;
        }

        cnt += intervalle ;

    }
    cout << -1 << endl;
    
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}