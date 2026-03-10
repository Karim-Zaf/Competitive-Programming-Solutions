/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
// #ifndef ONLINE_JUDGE
// #include "debug.cpp"
// #else
// #define kar(...)
// #endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'

const ll N = 1e12+ 7 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

void solve (){
    int n ; 
    cin >> n; 
    long long res = 0 ;
    vector <int> a(n) , b(n) ;
    for (auto &x : a) cin >> x; 
    for (auto &x : b) cin >> x; 
    for (int i= 1 ;i< n ;i++ ){
        for (int j = 0 ; j<i ; j++){
            ll one = a[i]-a[j];
            ll two = b[i]-b[j];
            one *=one ;
            two *= two ; 
            res = max (res , one + two);
        }
    }
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}