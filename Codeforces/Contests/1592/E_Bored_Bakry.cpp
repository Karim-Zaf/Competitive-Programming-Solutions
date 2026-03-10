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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

const int LG = 22;
int t[LG][N];

void Solve() {
    int n, ans = 0;
    cin >> n;

    vector<int> v(n + 1), pref(n + 1), lst(LG);
    memset(t, -1, sizeof(t));

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ v[i];

    auto bit = [](int x, int b) {
        return ((1 << b) & x) != 0;
    };

    for (int i = 0; i <= n; i++) {

        for (int j = 0; j < LG; j++) {
            if (!bit(v[i], j)) {
                lst[j] = i;
                t[j][pref[i] >> j] = i;
            } else {
                int& nw = t[j][pref[i] >> j];
                if (nw < lst[j]) nw = i;
            }
        }


        map<int, vector<int>> mp;
        for (int j = 0; j < LG; j++) mp[-lst[j]].pb(j);

        vector<pair<int, vector<int>>> vp(all(mp));
        int suff = v[i];
        for (auto& [poss , vect] : mp) {
            int pos = -poss;
            for (int b = 0; b < LG - 1; b++) {
                if (!bit(suff, b)) continue;
                int nw_suff = (suff >> (b + 1)) << 1;
                nw_suff ^= (pref[i] >> b);
                int p = t[b][nw_suff];
                if (p >= pos && suff > (pref[i] ^ pref[p])) ans = max(ans, i - p);
            }
            for (auto b : vect) {
                suff &= (1 << LG) - 1 - (1 << b);
            }
        }
    }

    cout << ans << endl;
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
