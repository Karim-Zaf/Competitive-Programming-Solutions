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

const ll N = 1e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

void solve(){
    char t[3][3];
    map <char ,int> mp ;
    for (int i= 0;i<3 ;i++)
        for (int j= 0; j<3 ; j++)
            cin >> t[i][j];
    if (t[0][1]==t[0][2] && t[0][0]== t[0][2] && t[0][0]!='.'  ) mp[t[0][0]]++;
    if (t[1][1]==t[1][2] && t[1][0]== t[1][2]&& t[1][2]!='.') mp[t[1][0]]++;
    if (t[2][1]==t[2][2] && t[2][0]== t[2][2]&& t[2][2]!='.') mp[t[2][0]]++;
    if (t[1][0]==t[2][0] && t[1][0]== t[0][0]&& t[0][0]!='.') mp[t[1][0]]++;
    if (t[1][1]==t[2][1] && t[1][1]== t[0][1]&& t[1][1]!='.') mp[t[1][1]]++;
    if (t[1][2]==t[2][2] && t[1][2]== t[0][2]&& t[2][2]!='.') mp[t[1][2]]++;
    if (t[0][0]==t[1][1] && t[2][2]== t[1][1]&& t[1][1]!='.') mp[t[1][1]]++;
    if (t[0][2]==t[2][0] && t[0][2]== t[1][1]&& t[1][1]!='.') mp[t[1][1]]++;
    if (mp.size()!=1){ cout << "DRAW" << endl; return;}
    for (auto x : mp){
        cout << x.F << endl;
        return;
    }
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