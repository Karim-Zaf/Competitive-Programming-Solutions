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
    int a=0 , b = 0 , sum = 0 , res = 0 , n ; 
    cin >> n; 
    vector <int> v(n) ; 
    for (auto &x: v){
        cin >> x ; 
        if (x==1) a++;
        else b++ ;
        sum+= x ;  
    }
    if (sum <=0 ) { res += (abs(sum)+1)/2; b-=(abs(sum)+1)/2; }
    if (b%2) res++ ;
    cout << res << endl;


}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}