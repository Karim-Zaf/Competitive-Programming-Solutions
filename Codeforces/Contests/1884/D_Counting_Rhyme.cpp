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

const int  N=2e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+6;


void Solve() {
    int n , ans = 0 ;
    cin >> n;
    vector <int> mp(n+5),nb_divisors(n+5),res(n+5),vis(n+5);
    for (int i= 0 ; i<n; i++){
        int x ; cin>> x ; mp[x]++;
    }

    for (int i=1 ;i<n+5; i++){
        if(!mp[i])continue ;
        for (int j=i ; j<n+5 ;j+=i) vis[j]=1;
    }
    for (int i=n+4 ;i>=1 ; i--){
        for (int j=i ; j<n+5 ;j+=i) res[i]+=mp[j];
        res[i]= res[i]*(res[i]-1)/2;
        for (int j=i+i ; j<n+5 ;j+=i)
            res[i]-=res[j];
        if (vis[i])ans += res[i];
    }
    cout << n*(n-1)/2- ans << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
