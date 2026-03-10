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
    int n, k;
    cin >> n >> k;
    map<int, multiset<int>> mp;
    vector<int> a(n), b(n), res;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int j = 0; j < n; j++) {
        cin >> b[j];
        mp[a[j]].insert(b[j]);
    }
    for (auto x: mp) {
        int curr = *mp[x.F].rbegin();
        mp[x.F].erase(mp[x.F].find(curr));
        for (auto z: mp[x.F])
            res.pb(z);
    }
    int ans = 0;
    sort(all(res));
    for (int i = 0; i < k - mp.size(); i++) ans += res[i];
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