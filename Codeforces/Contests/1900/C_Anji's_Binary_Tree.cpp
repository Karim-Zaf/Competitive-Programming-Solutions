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

const int  N=3e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int ans = 0 ;
pair <int,int>  graph[N] ;
string  vall  ;

void dfs ( int curr , int val = 0 ){
    if (curr==0) return ;
    if (graph[curr].F ==0 && graph[curr].S ==0) {
        ans = min (ans , val);
        return ;
    }
    dfs ( graph[curr].F , val + (vall[curr-1]!='L'));
    dfs ( graph[curr].S , val + (vall[curr-1]!='R'));
}

void Solve (){
    int n ;
    cin >> n >> vall ;
    for (int i= 1 ;i<= n;i++){
        cin >> graph[i].F >> graph[i].S ;
    }
    ans = INF ;
    dfs (1);
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}