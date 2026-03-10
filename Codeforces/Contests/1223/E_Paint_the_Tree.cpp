/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define nop cout<<"-1"<<endl;

#define int ll 

const ll N = 5e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
int n , k , dp[N][2] ;
vector <int> graph[N] ;
map <pair<int,int>, int> mp ;
multiset <int,greater<>> stock[N];

void dfs( int curr = 1, int parent = 0 ){
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs(child,curr);
    }
    int sum = 0;
    for (auto child : graph[curr])
        sum += dp[child][0];
    int sum2 = sum ;
    dp[curr][0] = dp[curr][1]=sum;
    auto it = stock[curr].begin();
    for (int i= 0 ; i<min(k,(int)(stock[curr].size())); i++){
        sum2 += (*(it++));
        dp[curr][0]= max (dp[curr][0] ,sum2);
        if (i == k-1) continue;
        dp[curr][1]= max (dp[curr][1] ,sum2);
    }
    int hesba = dp[curr][1]+ mp[{min(parent,curr),max(parent,curr)}] - dp[curr][0];
    stock[parent].insert(hesba);
}

void solve(){
    cin >> n >> k ;
    mp.clear();
    for (int i= 1 ; i<=n ;i++) {
        graph[i].clear();
        dp[i][1]=dp[i][0]= 0 ;
        stock [i].clear();
    }
    for (int i= 0 ;i<n -1 ;i++){
        int u , v , val ;
        cin >> u >> v >> val;
        graph[u].pb(v);
        graph[v].pb(u);
        mp[{min(u,v),max(u,v)}]= val ;
    }
    dfs();
    cout << dp[1][0] << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}



// Failure gives you two choices: You stay down or You get up ;)