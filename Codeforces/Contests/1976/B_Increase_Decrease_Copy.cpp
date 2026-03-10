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
    vector<int> a(n), b(n + 1);

    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    int ans = 1, add = INF;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }
    kar (b[n]);
    for (int i = 0; i < n; i++) {
        int l = min(a[i], b[i]), r = max(a[i], b[i]);
        if (l <= b[n] && b[n]<= r) add = 0;
        if (b[n] < l) add = min(add, abs(l - b[n]));
        if (b[n] > r) add = min(add, abs(r - b[n]));
    }
    cout << ans + add << endl;
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