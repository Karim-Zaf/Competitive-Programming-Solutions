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

const int N = 1e5 + 3;

vector<int> mp[N];

void Solve() {
    int n;
    ll ans = 0;
    cin >> n;

    vector<int> v(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        ans += max(0, v[i] - v[i - 1]);
    }
    int maxi = *max_element(all(v));

    for (int i = 1, j; i <= n; i++) {
        j = 1;
        while (j <= v[i]) {
            int xx = v[i] / j;
            int r = v[i] / xx;
            if (mp[r + 1].empty() || mp[r + 1].back() != i)mp[r + 1].pb(i);
            if (mp[r].empty() || mp[r].back() != i)mp[r].pb(i);
            j = r + 1;
        }
    }

    vector<int> a = v;
    cout << ans << " " ;
    for (int k = 2; k <= maxi; k++) {
        for (auto i: mp[k]) {
            ans -= max(0, v[i] - v[i - 1]);
            ans -= max(0, v[i + 1] - v[i]);
            v[i] = (a[i] + k - 1) / k;
            ans += max(0, v[i] - v[i - 1]);
            ans += max(0, v[i + 1] - v[i]);
        }
        cout << ans << " " ;
    }
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