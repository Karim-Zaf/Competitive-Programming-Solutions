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
#define endl '\n'
#define int ll



const long long N=2e5+8,MOD=1e9+7,mod=1e12+7,INF=1e18;



void Solve(){
    int n ;
    cin >> n;
    vector <int> v(n) ;
    for (auto &x: v) cin>> x;
    if (n%2==0){
        cout <<  2 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
        return ;
    }
    cout <<  4 << endl;
    cout << 1 << " " << n << endl;
    cout << 1 << " " << n-1 << endl;
    cout << n-1 << " " << n << endl;
    cout << n-1 << " " << n << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}