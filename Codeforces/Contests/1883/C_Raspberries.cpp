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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+6;


void Solve() {
    int n , k , mx=1;
    cin >> n >> k ;
    vector <int> v(n) ;
    map <int,int> mp ;
    vector <int> other ;
    for (auto &x: v) {
        cin >> x ;
        x%= k;
        mp[x]++;
    }
    if (k==2){
        if (mp[0]) cout << 0 << endl;
        else cout << 1 << endl;
    }if (k==3){
        if(mp[0]) cout << 0 << endl;
        else if (mp[2]) cout << 1 << endl;
        else if (mp[1]) cout << 2 << endl;
    }if (k==4){
        if(mp[0]||mp[2]>=2) cout << 0 << endl;
        else if ((mp[2]&&mp[1])||mp[3]) cout << 1 << endl;
        else if (mp[2]||mp[1]>=2) cout << 2 << endl;
        else if (mp[1]) cout << 3 << endl;

    }
    if (k==5){
        if(mp[0]) cout << 0 << endl;
        else if (mp[4]) cout << 1 << endl;
        else if (mp[3]) cout << 2 << endl;
        else if (mp[2]) cout << 3 << endl;
        else if (mp[1]) cout << 4 << endl;
    }

}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}