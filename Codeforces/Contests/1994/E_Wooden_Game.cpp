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

const int N = 1e6 + 2;

const int LG = 22;


void Solve() {
    int k, ans = 0;
    cin >> k;
    vector<int> mp(LG + 5);
    vector<pair<int, int>> vp[LG + 4];

    for (int i = 0, n; i < k; i++) {
        cin >> n;

        vector<int> graph[n + 1];

        for (int j = 2, u; j <= n; j++) {
            cin >> u;
            graph[u].pb(j);
            graph[j].pb(u);
        }

        ans |= n;
        for (int b = LG; b >= 0; b--) {
            if ((1 << b) & n) {
                mp[b]++;
            }
        }
    }

    for (int b = LG; b >= 0; b--) {
        if (mp[b] >= 2) {
            ans |= (2 << b) - 1;
        } else if (mp[b]) ans |= (1 << b);
    }


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
