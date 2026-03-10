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

    int n, ans = 0;
    cin >> n;
    vector<int> v(n), divi;
    map<int, int> mp;
    for (auto &x: v) {
        cin >> x;
        mp[x]++;
    }
    sort(all(v));

    int lc = 1;
    for (int j = 0; j < n; j++) {
        if (lc>=1e9) break;
        lc = lc / __gcd(lc, v[j]) * v[j];
    }
    if (lc <= 0 || !mp[lc]) {
        cout << n << endl;
        return;
    }

    for (int d = 1; d * d <= lc; d++) {
        if (lc % d) continue;
        divi.pb(d);
        divi.pb(lc / d);
    }

    for (auto d: divi) {
        int cnt = 0;
        int nw_lc = 1;
        for (int i = 0; i < n; i++) {
            if (__gcd(d, v[i]) == v[i]) {
                cnt++;
                nw_lc = nw_lc / __gcd(nw_lc, v[i]) * v[i];
            }
        }
        if (!mp[nw_lc])ans = max(ans, cnt);
    }


    cout << ans << endl;

}

//coner case 2 3 12 --> 2

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}