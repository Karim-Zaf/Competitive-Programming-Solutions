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
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

#define endl '\n'

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {

    int n, m, r, c;
    int k, w;
    cin >> n >> m >> r >> c;
    cin >> k >> w;
    int mn = 1, mx = k;

    vector<array<int, 3>> v(w);
    for (auto& [ri, ci, ki] : v) cin >> ri >> ci >> ki;
    for (auto [ri, ci, ki] : v) {
        if (ri < r) {
            mn = max(mn, ki);
        } else if (ri == r && ci * c >= 0 && abs(ci) <= abs(c)) {
            mn = max(mn, ki);
        }
        if (ri == r && ci * c >= 0 && abs(ci) >= abs(c)) {
            mx = min(mx, ki);
        } else if (ri > r) mx = min(mx, ki);

    }
    cout << mn << " " << mx << endl;


}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
