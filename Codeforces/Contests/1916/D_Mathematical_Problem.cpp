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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve() {
    int n ;
    cin >> n ;
    if (n==1){
        cout << 1 << endl;
        return;
    }

    string s ="";
    for (int i= 0 ; i<n ;i++) s+= '0';
    map <string , vector<int>> mp ;
    for (int j = 1; j<=n/2 ; j++){
        string curr = s ;
        curr[j]= '6' ;
        int other_pos = j +j ;
        curr[other_pos]= '1' ;
        curr[0]='9' ;
        cout << curr << endl;
        curr[other_pos]= '9' ;
        curr[0]='1' ;
        cout << curr << endl;
    }
    s[0]='1';
    s[1]='9';
    s[2]='6';
    cout << s<< endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}