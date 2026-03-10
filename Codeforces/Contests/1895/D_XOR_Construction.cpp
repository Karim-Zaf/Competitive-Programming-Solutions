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

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve(){
    int n , res = 0;
    cin >> n ;
    vector <int> pref(n), bits(30) ;
    for (int i= 0 ; i<n-1; i++){
        cin >> pref[i];
        if (i) pref[i]^= pref[i-1] ;
        for (int j= 0 ;j<30;j++)
            if (pref[i]&(1<<j))
                bits[j]++;
    }
    for (int j= 0 ;j <30;j ++){
        int lezem = 0 ;
        for (int i= 0 ; i<n; i++)
            if (i&(1<<j))
                lezem++;
        if (lezem != bits[j]) res += (1<<j);
    }
    cout << res << " ";
    for (int i= 0 ;i<n-1; i++) cout << (res^pref[i]) << " ";
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}