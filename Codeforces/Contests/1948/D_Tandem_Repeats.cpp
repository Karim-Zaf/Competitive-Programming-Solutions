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
    string s;
    cin >> s;
    int n = s.size();
    s = "#" + s;
    int ans = 0;
    for (int len = 1; len <= n; len++) {
        vector<int> verif(n + 1);

        for (int j = 1; j <= n; j++) {
            int nxt = j + len;
            if (nxt > n) break;
            if (s[nxt] == s[j] || s[j] == '?' || s[nxt] == '?')
                verif[j] = 1;
        }
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (verif[j] == 0) sum = 0;
            else sum++;
            if (sum >= len) ans = len;
        }

    }
    cout << 2*ans << endl;

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