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

const int  N=2e5+40 ,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    int n ,k;
    cin >> n >> k ;
    vector<int> v(n), differences ;
    for (auto &x: v)cin >> x;

    sort (all(v));
    if (k>=3) {cout << 0 << endl; return ;}

    for (int i=0 ; i<n ; i++){
        for (int j= i+1 ; j<n ;j++)
            differences.pb(abs(v[i]-v[j]));
    }
    sort (all(differences));
    sort (all(v));
    int mn = min (v[0], differences[0]);
    if (k==1){cout << mn << endl;return;}

    for (auto curr: differences){
        int pos = lower_bound(all(v), curr) -  v.begin();
        if (pos <n ) mn = min (mn , abs(v[pos]-curr));
        if (pos >0 ) mn = min (mn , abs(v[pos-1]-curr));
    }
    cout << mn << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}