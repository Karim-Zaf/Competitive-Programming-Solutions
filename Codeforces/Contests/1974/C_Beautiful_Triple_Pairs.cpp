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
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);

    for (auto &x: v) cin >> x;

    map<array<int, 3>, int> mp;
    for (int i = 2; i < n; i++) {
        array<int, 3> curr = {v[i - 2], v[i - 1], v[i]};

        for (int j = 0; j < 3; j++) {
            array<int, 3> nw = curr;
            nw[j] = -INF;

            ans += mp[nw];
        }

        ans -= (3 * mp[curr]);
        mp[curr]++;

        for (int j = 0; j < 3; j++) {
            array<int, 3> nw = curr;
            nw[j] = -INF;
            mp[nw]++;
        }
    }
    
    cout << ans << endl;

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