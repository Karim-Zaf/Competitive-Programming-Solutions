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
    vector<int> v(n);

    int ans = 0;
    for (auto &x: v) cin >> x;

    // when you make a subarray of size >= 2  equal x then you can make the hole array = x;

    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0)ans = max(ans, min(v[i], v[i - 1]));
        if (i - 2 >= 0 && v[i] >= v[i - 1] && v[i] <= v[i - 2])
            ans = max(ans, v[i]);
        if (i - 2 >= 0 && v[i] <= v[i - 1] && v[i] >= v[i - 2])
            ans = max(ans, v[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n) ans = max(ans, min(v[i], v[i + 1]));
        if (i + 2 < n && v[i] >= v[i + 1] && v[i] <= v[i + 2])
            ans = max(ans, v[i]);
        if (i + 2 < n && v[i] <= v[i + 1] && v[i] >= v[i + 2])
            ans = max(ans, v[i]);
    }
    sort(all(v));
    ans = max(ans, v[(n + 1) / 2 - 1]);

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