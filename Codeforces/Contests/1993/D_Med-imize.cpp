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

vector<int> v;
int n, k, nb = 0;

bool work(int md) {
    vector<int> dp(k + 5);

    for (int i = 0; i < n; i++) {
        if (i % k == 0) dp[0] = max(dp[0], 1ll * (v[i] >= md));
        else dp[i % k] = max(dp[i % k], dp[i % k - 1] + (v[i] >= md));
    }

    int need = dp[nb - 1];
    return need >= (nb + 2) / 2;
}

void Solve() {
    cin >> n >> k;


    nb = n % k;
    if (nb == 0) nb = k;

    v.resize(n);
    for (auto& x : v) cin >> x;
    
    if (k >= n) {
        sort(all(v));
        cout << v[(n + 1) / 2 - 1] << endl;
        return;
    }

    int l = 0, r = 1e9, ans = -1;

    while (l <= r) {
        int md = l + (r - l) / 2;
        if (work(md)) {
            ans = md;
            l = md + 1;
        } else r = md - 1;
    }

    assert(ans!=-1);
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
