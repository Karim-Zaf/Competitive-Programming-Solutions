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
#define int __int128
#define endl '\n'

const int N=3e7+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int arith (int x){
    return x*(x+1)/2 ;
}

int work (int x ){
    int curr = x , ans = 0 ;
    while (curr >=1 ){
        int value = x/curr ;
        int next = x/(value+1)+1 ;
        int sum = arith(curr) -arith(next-1);
        ans += sum*value;
        curr = next -1;
    }
    return ans ;
}

void Solve() {
    ll a , b ;
    cin >> a >> b ;
    int ans = work(b) -work(a-1);
    cout << (ll)ans;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}