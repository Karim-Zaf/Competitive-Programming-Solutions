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

const int N=1e6+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int mp[N] ;

void Solve() {
    int n , ans = 0;
    cin >> n ;
    vector<int> v(n) ;
    for (auto &x: v) cin >> x;
    for (int i= 0 ; i<n ;i++){
        int cnt = 0 ;
        for (int j=i ;j>=0 ; j--){
            mp[v[j]]++ ;
            if (mp[v[j]]%2) cnt ++ ;
            else cnt--;
            ans += (cnt ==1) ;
        }
        for (int j=i ;j>=0 ; j--) mp[v[j]]--;
    }
    cout << ans << endl;
}

int32_t main(){
    freopen("cases.in","r",stdin);
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}