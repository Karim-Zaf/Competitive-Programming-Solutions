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

int vis[N];

void Solve() {

    int n, k, cnt = 1;
    cin >> n >> k;


    vector<int> v(n);
    vector<int> s;
    for (auto& x : v) cin >> x;
    for (auto x : v) {
        if (x <= k && k % x == 0) {
            vector<int> nw;
            for (auto xx : s) {
                if (x * xx > k) continue;
                if (!vis[x * xx]) nw.pb(x * xx);
                vis[x * xx] = 1;
            }
            for (auto xx : s) nw.pb(xx);

            if (!vis[x]) nw.pb(x);
            vis[x] = 1;

            s = nw;
        }
        if (vis[k]) {
            cnt++;
            for (auto x : s) vis[x] = 0;
            s.clear();
        }
        if (x <= k && __gcd(x, k) != 1 && !vis[x]) {
            vis[x] = 1;
            s.pb(x);
        }
    }
    for (auto x : s) vis[x] = 0;
    cout << cnt << endl;


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
