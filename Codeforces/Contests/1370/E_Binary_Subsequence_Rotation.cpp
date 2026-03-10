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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

void Solve() {
    int n, ans = 0, cnt[2]{0, 0};
    string a, b;
    cin >> n >> a >> b;
    set<int> s[2];
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) s[a[i] - '0'].insert(i);
        cnt[0] += (a[i] == '0');
        cnt[1] += (b[i] == '0');
    }
    if (cnt[0] != cnt[1]) {
        cout << -1 << endl;
        return;
    }
    while (!s[0].empty() || !s[1].empty()) {
        int ebda = 0;
        if (s[0].empty() || !s[1].empty() && *s[1].begin() < *s[0].begin()) ebda = 1;
        int curr = -1;
        while (true) {
            auto it = s[ebda].upper_bound(curr);
            if (it == s[ebda].end())break;
            curr = *it;
            s[ebda].erase(curr);
            ebda ^= 1;
        }
        ans++;
    }
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}