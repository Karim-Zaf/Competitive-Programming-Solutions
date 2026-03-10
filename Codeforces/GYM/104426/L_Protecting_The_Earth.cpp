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
 
const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
 
ll count (int x){
    int res =0;
    for (int i= 1 ;i<x ; i++){
        int hauteur = sqrt (x*x - i*i);
        int curr = hauteur *4 ;
        res += curr ;
    }
    return res +4*x+1;
}
 
void solve() {
    int K;
    cin >> K;
    ll l = 1, r = 1e5, ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll cnt = count(mid);
        if (cnt >= K) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    assert(ans > 0);
    cout << ans << endl;
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}