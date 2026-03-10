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
 
void Solve() {
    int n , fin= 0;
    cin >> n ;
    vector<int> v[2] ;
    array<int,2> flag{0,0};
    for (int i= 0,x, b  ;i<n;i++){
        cin >> x >> b;
        v[b].pb(x);
    }
    sort (all(v[0]));sort (all(v[1]));
 
    auto kadem=[&](int indx){
        int curr = v[indx][flag[indx]] ;
        fin = max(curr,fin)+10 ;
        while(flag[indx] < v[indx].size() && v[indx][flag[indx]]<=fin){
            fin = max(fin,v[indx][flag[indx]]+10) ;
            flag[indx]++ ;
        }
    };
 
    while(flag[0] <v[0].size()||flag[1]<v[1].size()){
        if (flag[0] ==v[0].size())kadem(1);
        else if (flag[1]==v[1].size())kadem(0);
        else if (v[0][flag[0]] < v[1][flag[1]])kadem(0) ;
        else kadem(1);
    }
 
    cout << fin << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}