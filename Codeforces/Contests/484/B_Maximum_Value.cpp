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

const int N = 2e6 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

int p[N];

void Solve() {
    int n, ans = 0;
    cin >> n;
    set<int> s;
    vector<int> v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    for (auto x: s) v.pb(x);

    sort(all(v));

    for (int i = 0; i < N; i++) {
        int pos = lower_bound(all(v), i) - v.begin() - 1;
        if (pos >= 0) p[i] = v[pos];
    }

    for (auto x: v) {
        for (int j = 2 * x; j < N; j += x) {
            ans = max(ans, p[j] % x);
        }
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