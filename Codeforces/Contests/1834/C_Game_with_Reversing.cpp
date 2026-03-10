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
    int n , one = 0 , two  = 0 ; 
    cin >> n; 
    string a , b ; 
    cin >> a >> b ; 
    for (int i= 0 ; i<n ; i++)
        one += a[i]!=b[i];
    string nwb  = b ; 
    reverse(all(nwb));
    for (int i= 0 ; i<n ; i++)
        two += a[i]!=nwb[i];
    int first = 2* one - one%2;
    if (nwb == a && first>2 ) {cout << 2 << endl; return;}
    two -- ;
    int second =  2 +2* two - two%2 ;
    // if (one %2 )
    cout << min (first , second) << endl;

}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}