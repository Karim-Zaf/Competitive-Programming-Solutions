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

string s;
int n;

bool ok(int md) {
    string curr = s, comp = "";
    for (int j = 1; j <= n; j++)comp += "1";
    vector<int> pref(n + 5);
    for (int i = 0; i <= n - md; i++) {
        if (i)pref[i] += pref[i - 1];
        if (pref[i] % 2) {
            if (curr[i] == '0') curr[i] = '1';
            else curr[i] = '0';
        }
        if (curr[i] == '0') {
            pref[i]++;
            pref[i + md]--;
            curr[i] = '1';
        }
    }
    for (int i = n - md + 1; i < n; i++) {
        if (i)pref[i] += pref[i - 1];
        if (pref[i] % 2) {
            if (curr[i] == '0') curr[i] = '1';
            else curr[i] = '0';
        }
    }
    return curr == comp;
}

void Solve() {

    cin >> n >> s;

    int l = 0, r = n, ans = -1;

    for (int i = 1; i <= n; i++) {
        if (ok(i))ans = i;
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