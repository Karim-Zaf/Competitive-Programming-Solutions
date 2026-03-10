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
    int n, k, ans = 0;
    cin >> n >> k;
    vector<array<int, 3>> v(n);
    set<array<int, 5>> s, res;
    map<int, set<array<int, 5>>> x, y;
    for (auto& e : v) cin >> e[0] >> e[1] >> e[2];

    for (int i = 0; i < n; i++) x[v[i][0]].insert({v[i][1], v[i][0], v[i][1], v[i][2], i});
    for (int i = 0; i < n; i++) y[v[i][1]].insert({v[i][0], v[i][0], v[i][1], v[i][2], i});
    for (int i = 0; i < n; i++) s.insert({v[i][2], v[i][0], v[i][1], v[i][2], i});

    auto er = [&](int xx, int yy,int t,int i) {
        if (s.find({t, xx, yy, t, i}) == s.end()) return;
        s.erase({t, xx, yy, t, i});
        x[xx].erase({yy, xx, yy, t, i});
        y[yy].erase({xx, xx, yy, t, i});
    };

    function<void(int,int,int,int,int)> explode = [&](int xx, int yy, int t, int i, int indx)-> void {
        er(xx, yy, t, i);
        auto it = y[yy].lower_bound({xx - k, -INF, -INF, -INF});
        set<array<int, 5>> err;
        while (it != y[yy].end() && (*it)[0] <= xx + k) err.insert(*it++);
        for (auto x : err) er(x[1], x[2], x[3], x[4]);
        for (auto x : err) explode(x[1], x[2], x[3], x[4], indx);

        err.clear();
        it = x[xx].lower_bound({yy - k, -INF, -INF, -INF});

        while (it != x[xx].end() && (*it)[0] <= yy + k) err.insert(*it++);
        for (auto x : err) er(x[1], x[2], x[3], x[4]);
        for (auto x : err) explode(x[1], x[2], x[3], x[4], indx);
    };


    while (!s.empty()) {
        res.insert(*s.begin());
        auto [time , xx, yy , time2,i] = *s.begin();
        explode(xx, yy, time, i, i);
    }


    while (true) {
        while (!res.empty() && ans == (*res.begin())[0]) res.erase(*res.begin());
        if (res.empty()) break ;
        res.erase(*prev(res.end()));
        if (res.empty()) break ;
        ans++;
    }
    cout << ans << endl;
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
