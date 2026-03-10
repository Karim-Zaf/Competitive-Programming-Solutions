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
 
int t[N];
 
void Solve() {
    int n, m, curr = 0;
    cin >> n >> m;
    int ans = 0;
 
    int sz;
    cin >> sz;
    for (int i = 0, x; i < sz; i++) {
        cin >> x;
        t[x] = 1;
        curr++;
    }
    vector<vector<int>> v(n);
    for (int i = 0, x; i < n; i++) {
        cin >> sz;
        while (sz--) {
            cin >> x;
            v[i].pb(x);
        }
    }
    for (int i = 0; i < n; i++) v.pb(v[i]);
    for (int i = 0; i < n; i++) v.pb(v[i]);
 
    if (curr == 0) {
        cout << 0 << endl;
        return;
    }
    while (ans < v.size()) {
        for (auto x: v[ans]) {
            if (t[x]) {
                t[x] = 0;
                curr--;
            } else {
                t[x] = 1;
                curr++;
            }
        }
        ans++;
        if (curr == 0) {
            cout << ans << endl;
            return;
        }
    }
 
    cout << -1 << endl;
}
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}