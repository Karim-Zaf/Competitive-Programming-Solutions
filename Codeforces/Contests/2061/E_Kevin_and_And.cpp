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

void Solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    vector<int> ad((1 << m), (1ll << 31) - 1);
    for (int mask = 0; mask < (1 << m); mask++){
        for (int j = 0; j < m; j++){
            if ((1 << j) & mask)
                ad[mask] &= b[j];
        }
    }

    int t[n][m + 1];
    int ans = accumulate(all(a), 0ll);
    vector<int> values;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= m; j++) t[i][j] = a[i];
        for (int mask = 0; mask < (1 << m); mask++){
            int cnt = __builtin_popcount(mask);
            t[i][cnt] = min(t[i][cnt], ad[mask] & a[i]);
        }

        for (int j = 1; j <= m; j++){ values.pb(t[i][j - 1] - t[i][j]); }
    }
    sort(rall(values));

    for (int i = 0; i < k; i++) ans -= values[i];

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
