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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {
    int n;
    cin >> n;
    int ans = INF;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    if (v[1]!=v[n]){cout << 0 << endl; return ;}
    vector<int> nw = v ;
    sort (all(nw)) ;
    if (nw==v){cout << -1 << endl; return;}

    vector<int> pos;
    pos.pb(0) ;
    pos.pb(n+1) ;

    for (int i = 1; i <= n; i++) {
        if (v[i]!=v[1])pos.pb(i) ;
    }
    sort (all(pos)) ;
    for(int i= 1 ;i< pos.size(); i++) ans = min( ans , pos[i]-pos[i-1]-1) ;
//    for (int i = n; i >= 1; i--) {
//        if (i - 2 >= 1 && v[i] != v[i - 2]) {
//            ans = min(ans, n - i);
//        }
//
//    }
    cout << (ans == INF ? -1 : ans) << endl;

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}