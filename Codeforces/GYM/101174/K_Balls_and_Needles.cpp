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
#define int ll
#define ld long double
const ll N = 2e5+ 5 ,  MOD =1e9+7, mod=1e9 +7, INF = 1e9+5;

set <int> graph[2][N] ;
int vis[2][N];

bool dfs (int curr , int parent , int ind){
    vis[ind][curr]=1 ;
    for (auto child : graph[ind][curr]){
        if (vis[ind][child] && child != parent) return true;
        if (vis[ind][child]) continue;
        dfs (child , curr , ind) ;
    }
    return false ;
}


void solve(){
    int k , id1 = 0 , id2 = 0 ;
    cin >> k ;
    map <array <int,3>, int> mp ;
    map <array<int,2>, int> mp2 ;
    for (int i= 0 ; i< k ; i++){
        array <int,3> ar1 , ar2 ;
        array <int,2> ar3 , ar4 ;
        cin >> ar1[0] >> ar1[1] >> ar1[2] >> ar2[0] >> ar2[1] >> ar2[2];
        ar3={ar1[0],ar1[1]}; ar4={ar2[0],ar2[1]};
        if (!mp[ar1]) mp[ar1]= ++id1;
        if (!mp[ar2]) mp[ar2]= ++id1;
        if (!mp2[ar3]) mp2[ar3]= ++id2;
        if (!mp2[ar4]) mp2[ar4]= ++id2;
        if (mp[ar1]!=mp[ar2])graph[0][mp[ar1]].insert(mp[ar2]);
        if (mp[ar1]!=mp[ar2])graph[0][mp[ar2]].insert(mp[ar1]);
        if (mp2[ar3]!=mp2[ar4])graph[1][mp2[ar3]].insert(mp2[ar4]);
        if (mp2[ar3]!=mp2[ar4])graph[1][mp2[ar4]].insert(mp2[ar3]);
    }
    int ok = 0 ;
    for (int i= 1 ; i<=id1 ; i++)
        if (!vis[0][i] && dfs (i, -1 , 0 )) ok = 1 ;

    if(ok) cout << "True closed chains\n" ;
    else  cout << "No true closed chains\n" ;
    ok = 0 ;
    for (int i= 1 ; i<=id2 ; i++)
        if (!vis[1][i] && dfs (i, -1 , 1 )) ok = 1 ;
    if (ok) cout << "Floor closed chains\n" ;
    else  cout << "No floor closed chains\n" ;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}