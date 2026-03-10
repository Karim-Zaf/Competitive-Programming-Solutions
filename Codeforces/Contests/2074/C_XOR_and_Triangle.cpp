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

void Solve(){
    int n;
    cin >> n;
    int pos = -1, pos2 = -1;
    for (int i = 0; i <= 30; i++){ if ((1 << i) & n)pos = i; }
    for (int i = 0; i <= pos; i++){
        if ((1 << i) & n);
        else pos2 = i;
    }
    if (pos2 == -1) return void(cout << -1 << endl);

    int nw_pos = 0;
    for (int i = pos; i >= 0; i--){ if ((1 << i) & n)nw_pos = i; }

    int ans = (1 << pos2) + (1 << nw_pos);
    if (ans < n && n + ans > (ans ^ n) && (ans ^ n) + n > ans && (ans ^ n) + ans > n) cout << ans << endl;
    else cout << -1 << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
