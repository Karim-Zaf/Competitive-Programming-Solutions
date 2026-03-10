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
const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

void solve(){
    int n ;
    cin >> n;
    for (int i= 0 ; i<= 1000 ;i++) {
        if (i*3> n) break;
        for (int j = 0; j <= 1000; j++) {
            if (i*3 + j*5> n) {break;}
            for (int k = 0; k <= 1000; k++) {
                if (i * 3 + j * 5 + k * 7 > n) { break; }
                if (i * 3 + j * 5 + k * 7 == n) {
                    cout << i << " " << j << " " << k << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl ;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}