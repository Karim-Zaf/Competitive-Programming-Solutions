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

    vector<int> v(n + 1), jeyin(n + 1);
    unordered_map<int, int> finite, vis, pref, vis2, mp;

    for (int i = 1; i <= n; i++)cin >> v[i];
    for (int i = -2 * n; i <= 0; i++) finite[i] = INF;
    for (int i = n + 1; i <= 3 * n; i++) finite[i] = INF;


    int pos = 1, oth = n, ok = 1;

    while (true) {
        if (pos <= 0 || pos > n)break;

        if (vis2[pos]) {
            ok = 0;
            break;
        }

        vis2[pos] = 1;
        mp[pos] = finite[pos] = vis[pos] = pos;

        pos += v[pos];
    }

    pos = 1;
    vis2.clear();

    while (!ok) {
        if (vis2[pos]) break;

        vis2[pos] = 1;

        mp[pos] = finite[pos] = 0;
        vis[pos] = 1;
        pos += v[pos];
    }
    function<int(int)> work = [&](int point) -> int {
        if (point <= 0 || point >= n + 1) return INF;

        int &ret = finite[point];
        if (vis[point]) return ret;

        vis[point] = 1;

        ret = work(point + v[point]);
        return ret;
    };

    for (int i = n; i >= 1; i--)
        if (!vis[i] && !mp[i])
            work(i);

    for (int i = -2 * n; i <= 3 * n; i++) {
        pref[i] += pref[i - 1] + (finite[i] != 0);
        if (finite[i] <= n) jeyin[finite[i]]++;
    }


    int cnt = 0;
    pos = 1;

    vis2.clear();

    while (true) {
        if (pos <= 0 || pos > n)break;

        if (vis2[pos]) break;

        vis2[pos] = 1;

        ans += pref[pos + n] - pref[pos - n - 1];


        cnt += jeyin[pos];
        
        if (ok)ans -= cnt;
        pos += v[pos];

        oth--;
    }
    while (oth-- > 0 && finite[1]) {
        ans += 2 * n + 1;
    }
    cout << ans << endl;
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