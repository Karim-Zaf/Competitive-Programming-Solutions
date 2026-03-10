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

    vector<int> p(n + 1), q(n + 1), sum(n + 1);
    vector<pair<int, int>> vp;
    for (int i = 1; i <= n; i++) cin >> p[i];

    // first

    for (int i = 2; i < n; i += 2) {
        vp.pb({p[i], i});
    }

    sort(all(vp));
    for (int i = 0; i < vp.size(); i++) {
        auto [value, pos] = vp[i];
        q[pos] = n - i;
    }


    vp.clear();
    for (int i = 1; i <= n; i += 2) {
        vp.pb({p[i], i});
    }

    sort(rall(vp));
    for (int i = 0; i < vp.size(); i++) {
        auto [value, pos] = vp[i];
        q[pos] = i + 1;
    }

    q[n] = n / 2 + 1;

    // verfiying first

    bool ok = 1;
    for (int i = 1; i <= n; i++)sum[i] = p[i] + q[i];
    for (int i = 2; i < n; i += 2) {
        if (sum[i - 1] >= sum[i] || sum[i] <= sum[i + 1]) ok = false;
    }

    if (ok) {
        for (int i = 1; i <= n; i++)
            cout << q[i] << " ";
        cout << endl;
        return;
    }


    // second
    fill(all(q), 0ll);
    vp.clear();
    for (int i = 3; i < n; i += 2) {
        vp.pb({p[i], i});
    }

    sort(all(vp));
    for (int i = 0; i < vp.size(); i++) {
        auto [value, pos] = vp[i];
        q[pos] = n - i;
    }


    vp.clear();
    for (int i = 2; i <= n; i += 2) {
        vp.pb({p[i], i});
    }

    sort(rall(vp));
    for (int i = 0; i < vp.size(); i++) {
        auto [value, pos] = vp[i];
        q[pos] = i + 1;
    }

    q[1] = n / 2 + 1;
    kar (q);

    ok = 1;
    for (int i = 1; i <= n; i++)sum[i] = p[i] + q[i];
    for (int i = 3; i < n; i += 2) {
        if (sum[i - 1] >= sum[i] || sum[i] <= sum[i + 1]) ok = false;
    }

    // verifying second
    if (ok) {
        for (int i = 1; i <= n; i++)
            cout << q[i] << " ";
        cout << endl;
        return;
    }

    assert (true);
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