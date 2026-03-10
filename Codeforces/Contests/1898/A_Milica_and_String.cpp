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
    int n , k;
    string s ;
    cin >> n >> k >> s ;
    map <char ,int> mp ,mp2;
    for (auto x: s ) mp[x]++;
    if (mp['B']==k){cout <<0 << endl; return;}
    int i= 0;

    for (auto x: s ) {
        mp2[x]++;
        mp[x]--;
        i++;
        if (mp['B']==k){
            cout << "1\n"<< i << " " << 'A' << endl;
            return ;
        }
        if (mp['A']==n-k) {
            cout << "1\n" << i << " " << 'B' << endl;
            return;
        }
    }cout << "2\n"<< n <<  " A\n" << k << " B\n" ;


    reverse (all(s));
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}