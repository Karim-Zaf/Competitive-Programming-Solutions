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

deque<pair<int, int>> Convex_Hull;

long double intersect(pair<int, int> a, pair<int, int> b) {
    return (long double) (a.S - b.S) / (long double) (a.F - b.F);
}

int sz() { return Convex_Hull.size(); }

void add(pair<int, int> Line) {
    while (Convex_Hull.size() >= 2
           && intersect(Convex_Hull[sz() - 1], Convex_Hull[sz()-2]) <=
              intersect(Convex_Hull[sz() - 1], Line))
        Convex_Hull.pop_back();
    Convex_Hull.push_back(Line);
}

int get(int x) {
    while (Convex_Hull.size() >= 2
           && intersect(Convex_Hull[0], Convex_Hull[1]) >= x)
        Convex_Hull.pop_front();

    pair<int, int> Line = Convex_Hull[0];

    return -Line.F * x + Line.S;
}

void Solve() {
    // the formula of the problem is
    // dp[i]= x[i]*y[i] - a[i] + max (-x[j]* y[i] + dp[j])  // as the y are increasing

    int n;
    cin >> n;
    vector<array<int, 3>> v(n + 1);
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];
    sort(v.begin() + 1, v.end());

    Convex_Hull.push_back({0, 0});

    for (int i = 1; i <= n; i++) {
        auto [x, y, a] = v[i];
        dp[i] = get(y);

        dp[i] += x * y - a;

        dp[i] = max(dp[i], dp[i - 1]);

        add({x, dp[i]});
    }

    cout << dp[n] << endl;
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