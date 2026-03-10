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

const int  N=2e5+30,NN = 5e5, MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve() {
    int n , alice = 0 ,bob =0;
    cin >> n ;
    vector <int> v(n) ;
    for (auto &x: v)  cin >> x;

    sort (rall(v));
    for (int i= 0 ;i<n ;i++){
        if (i%2==0 && v[i]%2==0) alice += v[i];
        if (i%2 && v[i]%2)bob += v[i];
    }

    if (bob == alice ) cout << "Tie\n";
    else if (bob>alice) cout  << "Bob\n";
    else cout << "Alice\n";

}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}