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
    vector<int> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    int twoones = 0, twominusones = 0, aa = 0, bb = 0;


    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && a[i] == 1)twoones++;
        else if (a[i] == b[i] && a[i] == -1) twominusones++;
        else if (a[i] == b[i] && a[i] == 0) continue;
        else if (a[i] == 1 && b[i] == -1) aa++;
        else if (a[i] == -1 && b[i] == 1) bb++;
        else if (a[i] == 1) aa++;
        else if (b[i] == 1)bb++;
    }

    while (twominusones) {
        if (aa > bb) aa--;
        else bb--;
        twominusones--;
    }
    while (twoones) {
        if (aa > bb) bb++;
        else aa++;
        twoones--;
    }
    cout << min(aa, bb) << endl;
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