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
 
const int  N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;
 
 
void Solve() {
    int d , c , r ,res = 0 ;
    cin >> d >> c >> r ;
    vector <int> one (c) , two (r);
    for (auto &x: one ) cin >> x;
    for (auto &x: two ) cin >> x;
 
    int i = 0 , j= 0 ;
    while (i<c && j<r){
        while (i<c && d>=one[i]){res ++; d-=one[i++];}
        d+= two[j++];
        res++ ;
    }
    while (j<r){j++;res++;}
    while (i<c && d>=one[i]){res++; d-=one[i++];}
    cout << res << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}