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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x: v) cin >> x;
    vector<int> b(n - 1), pref(n), suff(n);
    for (int i = 0; i < n - 1; i++)b[i] = __gcd(v[i], v[i + 1]);
    pref[0] = 1;
    for (int i = 1; i < n - 1; i++) {
        pref[i] = pref[i - 1];
        pref[i] &= (b[i] >= b[i - 1]);
    }
    suff[n - 2] = 1;
    for (int i = n - 3; i >= 0; i--) {
        suff[i] = suff[i + 1];
        suff[i] &= (b[i] <= b[i + 1]);
    }
    if (suff[1] || pref[n - 3]) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i <= n - 3; i++) {
        int ok = 1;
        if (i > 0)ok &= pref[i - 1];
        if (i + 2 < n - 1)ok &= suff[i + 2];
        int g = __gcd(v[i], v[i + 2]);
        if (i > 0) ok &= g >= b[i - 1];
        if (i + 2 < n - 1) ok &= g <= b[i + 2];
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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