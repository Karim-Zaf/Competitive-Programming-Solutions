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

    int n, m, k, res = 0;
    cin >> n >> m >> k;


    map<int, int> mp;
    map<int, vector<pair<int, int>>> vect;
    vector<int> ans(k + 3, 1);
    vector<pair<int, int>> vp(k + 3);
    for (int i = 1; i <= k; i++) cin >> vp[i].F >> vp[i].S;

    vp[k + 1] = {0, m + 1};
    k += 2;
    for (int i = 0; i < k; i++) {
        mp[vp[i].S] = max(mp[vp[i].S], vp[i].F);
        vect[vp[i].S].pb({vp[i].F, i});
    }
    int lst = 1;


    int suff = 0;
    for (auto [key, val]: mp) {
        int prv = suff;
        res += (key - lst) * (n - suff);
        suff = max(suff, val);
        lst = key;

        for (auto x: vect[key]) {
            if (x.F >= suff && suff > prv) {
                ans[x.S] = 1;
            } else ans[x.S] = 0;
        }

    }
    cout << res << endl;

    for (int i = 1; i < k - 1; i++)cout << ans[i] << " ";
    cout << endl;

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