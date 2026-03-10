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

const int  N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;

void Solve(){
    int n , k ;
    string s ;
    cin >> n >> k >>s ;
    vector<int> l(k) , r(k), pref(n+343) ;
    for (auto &x: l) cin >> x ;
    for (auto &x: r) cin >> x ;
    vector <pair <int,int>> vp(k) ;
    for (int i= 0;i<k ;i++) vp[i]= {--l[i],--r[i]};
    int q ;cin >> q ;
    for (int i= 0;i<q ;i++){
        int curr ; cin>> curr ; curr--;
        pair <int,int> p = {curr,INF};
        int pos = upper_bound(all(vp),p)-vp.begin() ;
        pos--;
        int left = vp[pos].F + vp[pos].S - curr ;
        pref [min (curr,left)]++;
        pref [max (curr,left)+1]--;
    }
    for (int i= 1 ;i<=n+1; i++) pref[i]+= pref[i-1];
    for (int i= 0;i<n;i++){
        if (pref[i]%2==0) continue;
        pair <int,int> p = {i,INF};
        int pos = upper_bound(all(vp),p)-vp.begin() ;
        pos--;
        int opp =  vp[pos].S - (i -vp[pos].F ) ;
        pref[opp]=0 ;
        swap (s[opp],s[i]);
    }
    cout << s << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while(Test_case--)Solve();
}