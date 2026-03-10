/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

const int N=1e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int n ,q;
vector<int> graph[N] ,color(N), ans(N) , sz(N);
map<int,int> mp[N] ;
vector<pair<int,int>> queries[N];

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
indexed_set s[N] ;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

void merge (int parent , int child){
    if (mp[parent].size()<mp[child].size()){
        mp[child].swap(mp[parent]);
        s[child].swap(s[parent]);
    }

    for (auto x: mp[child]){
        int &cnt = mp[parent][x.F] ;
        if (cnt) s[parent].erase({cnt,x.F});
        cnt+=x.S ;
        s[parent].insert({cnt,x.F});
    }
}

void dfs (int curr , int parent =-1) {

    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs (child,curr);
    }

    mp[curr][color[curr]]++;
    s[curr].insert({1,color[curr]});

    for (auto child : graph[curr]){
        if (child == parent) continue;
        merge (curr, child);
    }

    for (auto [k,pos]: queries[curr]){
        pair<int,int> p ={k,-INF};
        ans[pos]= s[curr].size() - s[curr].order_of_key(p) ;
    }
}

void Solve() {
    cin >> n >> q;
    for (int i= 1 ; i<=n ;i++) cin >> color[i] ;
    for (int i= 1 , u , v; i<n ;i++){
        cin >> u >>  v;
        graph[v].pb(u) ;
        graph[u].pb(v) ;
    }
    for (int i= 1, v, k; i<=q ; i++){
        cin >> v >> k ;
        queries[v].pb({k,i});
    }
    dfs (1) ;
    for (int i= 1; i<=q ;i++) cout << ans[i] << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}