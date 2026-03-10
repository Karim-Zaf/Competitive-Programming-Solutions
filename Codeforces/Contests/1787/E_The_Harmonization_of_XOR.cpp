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
    int n, k, x, xr = 0;
    cin >> n >> k >> x;

    vector<int> vis(n + 1);

    for (int i = 1; i <= n; i++) xr ^= i;

    int lg_n = log2(n) + 1, lg_x = ceil(log2(x));

    kar (xr);
    if (lg_x > lg_n || xr != x && k % 2 || xr != 0 && k % 2 == 0) {
        cout << "NO\n";
        return;
    }

    vector<vector<int>> ans;
    for (int submask = x; submask && ans.size() < k - 1; submask = (submask - 1) & x) {
        if (submask == x) {
            if (x <= n) {
                ans.pb({x});
                vis[x] = vis[0] = 1;
            }else continue;
        }else {
            int one = submask, two = x ^ submask;
            if (one > n || two > n || vis[one] || vis[two])continue;

            ans.pb({one, two});
            vis[one] = vis[two] = 1;
        }


        int opp = ((1 << lg_n) - 1) ^ submask;


        for (int nw_sub = opp; nw_sub && ans.size() < k - 1; nw_sub = (nw_sub - 1) & opp) {
            int nw_one = submask + nw_sub;
            int nw_two = x ^ nw_one;

            if (nw_one > n || nw_two > n || vis[nw_one] || vis[nw_two])continue;

            vis[nw_one] = vis[nw_two] = 1;

            ans.pb({nw_one, nw_two});
        }
    }
    vector<int> fin;
    for (int i = 1; i <= n; i++) if (!vis[i])fin.pb(i);

    ans.pb(fin);
    if (ans.size() < k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto vect: ans) {
        cout << vect.size() << " ";
        for (auto xx: vect) cout << xx << " ";
        cout << endl;
    }
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