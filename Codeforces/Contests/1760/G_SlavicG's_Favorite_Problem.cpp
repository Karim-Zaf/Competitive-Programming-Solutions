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

int x , a, b , n;
vector<pair<int,int>> graph[N] ;
map <int,int> mp ;

bool dfs (int curr , int parent , int flag ){

    for (auto [child, value]: graph[curr]){
        if (child == parent )continue;
        x^=value ;

        if (flag == 0 && child == b && x ==0 ) return true ;
        else if (flag == 0 && child == b) {
            x^=value ;
            continue;
        }

        if (flag ==0) mp[x]= 1 ;

        if (flag && mp[x])return true ;

        int ans = dfs (child,curr,flag);
        if (ans) return true;
        x^=value ;
    }
    return false ;
}

void Solve() {
    cin >> n >> a >> b ;
    for (int i= 1 ; i<=n ; i++)graph[i].clear();
    for (int i= 0 ; i<n-1 ; i++){
        int u , v , w ;
        cin >> u >> v >> w ;
        graph[u].pb({v,w});
        graph[v].pb({u,w});
    }
    mp.clear(); x= 0;
    int ans = dfs (a, -1 , 0 ) ;
    mp[0]=1 ;
    x = 0;
    ans|= dfs (b , -1 , 1 );
    cout << (ans? "YES": "NO") << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}