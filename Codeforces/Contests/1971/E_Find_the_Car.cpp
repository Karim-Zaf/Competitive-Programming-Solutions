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
    int n, k, q;
    cin >> n >> k >> q;
    vector<pair<int, int>> v(k);
    for (auto &x: v)cin >> x.F;
    for (auto &x: v)cin >> x.S;
    v.pb({0, 0});
    sort(all(v));


    kar (v);

    while (q--) {
        int d;
        cin >> d;
        pair<int, int> p = {d, INF};

        int pos = lower_bound(all(v), p) - v.begin();

        if (v[pos - 1].F == d) {
            cout << v[pos-1].S << " ";
            continue;
        }

        auto [a1, b1] = v[pos - 1];
        auto [a2, b2] = v[pos];

        int dist1 = a2 - a1;
        int time1 = b2 - b1;
        int dist2 = d - a1;
        int time2 = time1 * dist2 / dist1;
        cout << b1 + time2 << " ";
    }
    cout << endl;
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