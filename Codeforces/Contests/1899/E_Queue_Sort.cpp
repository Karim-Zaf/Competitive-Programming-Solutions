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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve(){
    int n , indx = 0 ;
    cin >> n;
    int fin = n-1;
    vector <int> v(n) ;
    for (auto &x: v) cin >> x;
    while (fin >=1 && v[fin] >=v[fin-1]) fin -- ;
    for (int i = n-1 ; i>= 0 ; i--){
        if (v[indx] >= v[i] ) indx = i ;
    }

    for (int i= indx +1 ; i<n ; i++){
        if (v[i] <v[i-1]) {cout << -1 << endl; return; }
    }

    cout << fin<< endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
        freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}