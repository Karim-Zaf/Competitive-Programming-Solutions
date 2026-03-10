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
int n, x;
vector<int> v;

int verif(int md) {
    priority_queue<pair<int, int>> q;
    vector<int> time(n);
    for (int i = 0; i < min(n, md); i++) {
        time[i] = v[i];
        q.push({-v[i], i});
    }

    for (int i = md; i < n; i++) {
        auto [t, person] = q.top();
        q.pop();

        time[person] = -t + v[i];
        q.push({-time[person], person});

    }
    return *max_element(all(time));
}

void Solve() {
    cin >> n >> x;
    v.resize(n);
    for (auto &x: v) cin >> x;
    int l = 1, r = 1e5 + 10, ans = -1;
    while (l <= r) {
        int md = l + (r - l) / 2;

        if (verif(md) <= x) {
            ans = md;
            r = md - 1;
        } else l = md + 1;
    }
    cout << ans << endl;
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