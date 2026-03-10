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
#define endl '\n'
#define int ll
#define ld long double
const ll N = 1e6+ 5 ,  MOD =1e9+7, mod=1e9 +7, INF = 1e9+5;

void solve(){
    int d, r , t ;
    cin >> d >> r >> t ;
    int res1 = 0 , res2 = 3 ;
    int cnt1 = 4 , cnt2 =4 ;
    for (int i= 0 ; i< d ;i++) {
        res1+= cnt1++ ;
        if (res1>=r) {cout << 0 << endl; return;}
    }
    while (res1 + res2 < r + t){
        res1 += cnt1++ ;
        res2 += cnt2++ ;
    }
    cout << r-res1 << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}