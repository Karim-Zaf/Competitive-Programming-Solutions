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
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);

    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    cin >> m;
    vector<int> d(m);
    for (auto &x: d) cin >> x;

    map<int, vector<int>> mp;

    set<int> s, pres;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            mp[b[i]].pb(i);
            s.insert(b[i]);
        }
        pres.insert(b[i]);
    }

    int pos = INF;
    for (int i = 0; i < m; i++) {


        if (!mp[d[i]].empty()) {
            mp[d[i]].pop_back();
            if (mp[d[i]].empty())s.erase(d[i]);
        }
        if (s.empty()) pos = i;
    }

    if (s.empty() && pres.find(d.back()) != pres.end()) return void(cout << "YES\n");
    cout << "NO\n";
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