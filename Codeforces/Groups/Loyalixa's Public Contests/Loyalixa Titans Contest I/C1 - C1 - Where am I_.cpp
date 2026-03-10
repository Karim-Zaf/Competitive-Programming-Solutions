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

vector<int> sv[N], dv[N];
vector<pair<int, int>> queries[N];

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        dv[v[i]].pb(i + 1);
    }

    int q;
    cin >> q;

    vector<int> ans(q + 1, -1);

    for (int i = 1; i <= q; i++) {
        int x, k;
        cin >> x >> k;
        queries[x].pb({k, i});
    }

    for (int i = 1; i < N; i++) {
        vector<int> curr;
        if (queries[i].size() == 0) continue;
        for (int j = i; j < N; j += i) {
            for (auto x : dv[j]) curr.pb(x);
        }
        sort(all(curr));
        for (auto [k , indx] : queries[i]) {
            kar(curr);
            kar(k);
            if (k <= curr.size()) ans[indx] = curr[k - 1];
            kar(curr[k-1]);
            kar(indx);
            kar(ans);
        }

    }

    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
