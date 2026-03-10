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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

void Solve() {
    map<int,int> give, recieve ;
    int n;
    cin>> n ;
    vector<int> v(n) ;
    for (auto &x: v) cin >> x ;
    int sum = accumulate(all(v),0ll);
    if (sum%n) {cout << "NO\n";return;}
    sum/= n;
    for (auto x: v) {
        int flag = false ;
        if (x==sum) continue;
        for (int i= 0 ;i<31; i++){
            for (int j= 0; j<31 ; j++){
                if (((1ll<<i) -(1ll<<j))==sum-x){
                    recieve[1ll<<i]++;
                    give [1ll<<j]++;
                    flag = true ;
                }
            }
        }
        if (!flag) {cout << "NO\n"; return;}
    }
    for (auto x: give){
        if (give[x.F]!=recieve[x.F]){cout << "NO\n";return;}
    }
    cout << "YES\n";
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}