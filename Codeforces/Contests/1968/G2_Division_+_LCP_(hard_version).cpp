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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void Solve() {
    int n, lef, righ, ans = 0;
    string s;
    cin >> n >> lef >> righ >> s;

    vector<int> z = z_function(s);

    vector<int> mp[n + 1], cnt(n + 1);
    set<int> ss;

    for (int i = 0; i < n; i++) {
        mp[z[i]].pb(i);
        if (z[i])ss.insert(i);
    }


    for (int i = 1; i <= n; i++) {
        int dep = i;
        while (true) {
            auto it = ss.lower_bound(dep);
            if (it == ss.end()) break;
            dep = *it + i;
            cnt[i]++;
        }

        for (auto x: mp[i])ss.erase(x);
    }



    ans = n;
    for (int j = lef; j <= righ; j++) {
        int l = 1, r = ans;
        ans = 0;
        while (l <= r) {
            int md = l + (r - l) / 2;

            if (cnt[md] + 1 >= j) {
                l = md + 1;
                ans = md;
            } else r = md - 1;
        }
        cout << ans << " ";
    }
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