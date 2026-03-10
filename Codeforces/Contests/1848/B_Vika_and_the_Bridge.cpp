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

const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

void solve() {
    int n, m , res = INF ;
    cin >> n >> m ;
    vector <vector<int>> v (m+1);
    for (int i= 1 ;i<= m ; i++) {v[i].pb(0);}
    for (int i= 1 ;i<= n ;i++){
        int x ;
        cin >> x;
        v[x].pb(i);
    }
    for (int i= 1 ;i<= m ; i++) {v[i].pb(n+1);}
    for (int i= 1 ;i<=m ;i++){
        int mx = v[i][1] -v[i][0] -1, ind = 1 ;
        for (int j= 1 ; j<v[i].size() ; j++){
            int dist = v[i][j] - v[i][j-1] ;
            if (dist > mx ){
                mx =dist ;
                ind = j ;
            }
        }
        int nw =0;
        for (int j= 1 ; j<v[i].size() ; j++){
            int dist = v[i][j] - v[i][j-1]-1 ;
            if (j== ind )dist = dist /2 ;
            nw = max (nw , dist );
        }
        res = min (res , nw ) ;
    }
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}