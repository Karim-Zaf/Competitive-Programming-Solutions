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

const int N=1e6+5,mod=1e9+7,MOD=mod,INF=1e18+10;

vector <int> graph[N] , query[N];
int up[N][20], ans[N], value[N],mp[N],Node =1 , nb_query=0 ,cnt =0;
vector<int> track;

void dfs (int curr, int parent = -1) {
    if (!mp[value[curr]])cnt++ ;
    mp[value[curr]]++ ;
    for (auto x: query[curr])ans [x]= cnt ;
    for (auto child : graph[curr]){
        if (child== parent) continue;
        dfs (child,curr);
    }
    mp[value[curr]]-- ;
    if (!mp[value[curr]])cnt--;
}

void add_node (int parent, int child){
    graph[parent].pb(child) ;
    up[child][0]= parent ;
    for (int i= 1 ;i<20 ; i++) up[child][i]= up [up[child][i-1]][i-1] ;
}


int Binary_Lifting (int a, int k){
    for (int i = 19;i>=0 ;i-- )
        if (k & (1<< i))
            a = up[a][i];
    return a ;
}

int curr(){
    if (track.empty()) return 0 ;
    return track.back();
}

void Solve() {
    int q ;
    cin >> q ;
    while(q--){
        char c ;
        int x;
        cin >> c ;
        if (c=='+'){
            cin >> x;
            add_node (curr(),++Node);
            value[Node]= x;
            track.pb(Node);
        }else if (c=='-'){
            cin >> x ;
            track.pb(Binary_Lifting(curr(),x)) ;
        }else if (c=='?') {
            query[curr()].pb(++nb_query);
        }else if (!track.empty()){
            track.pop_back();
        }
    }
    dfs (0) ;
    for (int i= 1; i<=nb_query; i++) cout << --ans[i]<<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}