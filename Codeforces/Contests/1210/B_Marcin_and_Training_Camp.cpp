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
    int n , sum = 0 ;
    cin >> n;
    vector <int> a(n) , b(n) ;
    map <int,int> mp ;
    set<int>s ;
    for (int i= 0;i<n;i++){
        cin >> a[i];
        mp[a[i]]++ ;
    }
    for (auto &x: b) cin >> x;
    for (int i= 0 ;i<n ;i++){
        if (mp[a[i]]<=1) continue;
        s.insert(i);
        for (int j= 0; j<n;j++)
            if ((a[i]|a[j])==a[i])s.insert(j);
    }
    for (auto x: s) sum += b[x];
    cout << sum << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}