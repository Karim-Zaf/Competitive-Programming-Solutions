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

const int  N=5e6+8,MOD=1e9+7,mod=1e9+7,INF=1e17;

void Solve(){
    int n , f ;
    cin >> n>> f ;
    vector <pair <int,int>>vp(n) ;
    for (int i= 0;i<n;i++)cin>>vp[i].F >> vp[i].S ;
    for (int i= 0 ;i<n ;i++){
        if (f>=vp[i].F && f>=vp[i].S){
            f+= max(vp[i].F , vp[i].S ) ;
        }else if (f>=vp[i].F)f+= vp[i].F ;
        else if (f>=vp[i].S) f+= vp[i].S ;
        else {cout << "N\n"; return;}
    }
    cout << "S\n";
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while(Test_case--)Solve();
}