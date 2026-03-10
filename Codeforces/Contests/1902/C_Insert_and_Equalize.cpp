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

const int  N=2e5,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    int n , x, sum = 0 ;
    cin >> n;
    vector <int> v(n), dist(n),lef(n),righ(n);
    for (auto &e: v) cin>> e;
    sort (all(v));
    if (n==1){cout << 1 << endl; return ;}

    x= abs (v[1]-v[0]) ;
    for (int i= 1 ;i<n ; i++){
        x = __gcd (x , abs(v[i]-v[i-1]));
    }
    for (int i= 0 ;i<n ; i++) sum += (v[n-1] - v[i])/x;

    int i=0 ;
    while (i<n&& v[n-1]-x *i== v[n-i-1]) i++;

    cout << sum +i  <<endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}