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
 
const int  N=2e5,MOD=1e9+7,mod=1e9+7,INF=1e18+10;
 
void Solve() {
    int n ,res1 = INF , res2 = INF ;
    cin >> n ;
    vector <int> v(n) , other;
    for (auto &x: v) {
        cin >> x;
        other.pb(x);
    }
    sort(all(other));
    bool verif = true ;
    for (int i= 0; i<n ; i++)if (v[i]!=other[i]) verif = false ;
    if (verif) {cout << 0 << endl ; return ;}
 
    sort(rall(other));
    verif = true ;
    for (int i= 0; i<n ; i++)if (v[i]!=other[i]) verif = false ;
    if (verif) {cout << 1 << endl ; return ;}
 
    //////////////////////////////////////////////////////////
    int flag1  = 0 ;
    while (flag1+1 <n && v[flag1]>=v[flag1+1])flag1 ++ ;
    int flag2= flag1 +1 ;
    while (flag2+1 <n && v[flag2]>=v[flag2+1])flag2 ++ ;
    if (flag2>=n-1  && v[n-1] >= v[0]){
        int cnt  =n -flag1 -1 ;
        res2 = min (cnt +1  , n -cnt +1  ) ;
    }
    ///////////////////////////////////////////////
    flag1  = 0 ;
    while (flag1+1 <n && v[flag1]<=v[flag1+1])flag1 ++ ;
    flag2= flag1 +1 ;
    while (flag2+1 <n && v[flag2]<=v[flag2+1])flag2 ++ ;
    if (flag2>=n-1 && v[n-1] <= v[0]){
        int cnt  =n -flag1-1  ;
        res1 = min (cnt , n -cnt +2  ) ;
    }
    int ans = min (res1 , res2 ) ;
    cout << (ans == INF ? -1 : ans) << endl;
}
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}