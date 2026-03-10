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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

void Solve() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> a(n), d(m), f(k);
    for (auto &x: a) cin >> x;
    for (auto &x: d) cin >> x;
    for (auto &x: f) cin >> x;
    sort(all(d));
    sort(all(f));

    for (int i = 1; i < n; i++)ans = max(ans, a[i] - a[i - 1]);

    int cnt = 0, pos = -1;
    set<int> s;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == ans) {
            cnt++;
            pos = i;
        }
        s.insert(a[i] - a[i - 1]);
    }
    if (cnt >= 2) {
        cout << ans << endl;
        return;
    }
    int rodbelek = 0;
    if (s.size() >= 2) rodbelek = *prev(prev(s.end()));
    int l = a[pos - 1], r = a[pos];
    for (auto x: d) {
        if (x > r)continue;
        int lzem = r - (r - l) / 2;
        int nekes = lzem - x;
        int p = upper_bound(all(f), nekes) - f.begin();
        for (int j = max(0ll, p - 10); j < min(p + 10, k); j++) {
            int curr = f[j] + x;
            if (curr >= l && curr <= r) {
                int mx = max({abs(curr - l), abs(curr - r), rodbelek});
                ans = min(ans, mx);
            }
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
    cin >> Test_case;
    while (Test_case--) Solve();
}