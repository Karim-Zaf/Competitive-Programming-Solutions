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
#define endl '\n'

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> divisors[N], mp[N], lst(N, INF), prv(N, INF), ok(N, INF);

void Solve() {
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divisors[j].pb(i);

    int n;
    cin >> n;
    vector<int> v(n);
    set<int> ans;
    for (auto &x: v) cin >> x;

    int mx = 0;

    for (int i = 0; i < n; i++)
        for (auto d: divisors[v[i]]) {
            if (lst[d] != i - 1) {
                prv[d] = i;
                ok[d] = 0;
            }
            if (d == v[i]) ok[d] = 1;
            lst[d] = i;
            if (i - prv[d] > mx && ok[d]) {
                ans.clear();
                mx = i - prv[d];
            }
            if (i - prv[d] == mx && ok[d]) ans.insert(prv[d]);
        }

    cout << ans.size() << " " << mx << endl;
    for (auto x: ans) cout << ++x << " ";
    cout << endl;
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