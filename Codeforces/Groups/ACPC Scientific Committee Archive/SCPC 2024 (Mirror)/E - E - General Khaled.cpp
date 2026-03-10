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
 
int LG = 60;
 
void Solve() {
 
 
    array<int, 4> a, b;
    for (int i = 0; i < 4; i++) cin >> a[i];
    int xr = 0;
    for (int i = 0; i < 4; i++) b[i] = a[i] % 2;
 
    if (b[3]) a[3]--;
    int ans = 0;
    if (b[1] && b[2] && b[0]) {
        ans++;
    }
    if (b[0]) a[0]--;
    if (b[1]) a[1]--;
    if (b[2]) a[2]--;
 
 
    int nw = 0;
    for (int i = 0; i < 4; i++) nw += a[i];
    cout << ans + nw / 2 << endl;
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