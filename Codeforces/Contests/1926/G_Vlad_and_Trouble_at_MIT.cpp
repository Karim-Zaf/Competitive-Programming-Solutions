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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

vector<int> graph[N] ;
map<char,int> dp[N];
string s;
int ans , n;

void dfs (int curr, int parent=-1){
    for (auto child : graph[curr]){
        if (parent== child) continue;
        dfs (child,curr);
        dp[curr]['P']+= min(dp[child]['P'],dp[child]['S']+1);
        dp[curr]['S']+= min(dp[child]['S'],dp[child]['P']+1);
    }
    if (s[curr-1]=='P'){
        dp[curr]['S']=INF;
    }else if (s[curr-1]=='S'){
        dp[curr]['P']=INF;
    }

}

void init(){
    ans = 0 ;
    for (int i= 1 ;i<=n ;i++){
        graph[i].clear();
        dp[i].clear();
    }
}

void Solve() {
    cin >> n ;

    init();
    for (int i=2, u; i<=n ;i++){
        cin >> u ;
        graph[i].pb(u);
        graph[u].pb(i);
    }
    cin >> s;
    dfs (1);
    cout << min(dp[1]['P'],dp[1]['S']) << endl ;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}