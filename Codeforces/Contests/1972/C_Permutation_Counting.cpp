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
    int n, k, ans = 0, perm = 0;
    cin >> n >> k;

    vector<int> v(n + 1), prefix(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];

    vector<int> vp = v;
    sort(all(vp));

    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + vp[i];

    int l = 0, r = 7e12, beki = 0;
    while (l <= r) {
        int md = l + (r - l) / 2;
        int pos = lower_bound(all(vp), md) - vp.begin() - 1;

        if (pos * md - prefix[pos] <= k) {
            l = md + 1;
            perm = md;
            beki = k - (pos * md - prefix[pos]);
        } else r = md - 1;
    }


    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += (perm < v[i]);
    }

    cout << perm * n - n + 1 + cnt + min(n - cnt, beki) << endl;

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