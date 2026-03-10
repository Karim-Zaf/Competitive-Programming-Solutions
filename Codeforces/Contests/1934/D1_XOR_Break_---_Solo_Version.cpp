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

int n, m;

void yes() {
    cout << "1\n" << n << " " << m << endl;
}

int bit(int x, int b) {
    if ((1ll << b) & x)return 1;
    return 0;
}

void Solve() {
    cin >> n >> m;
    int ans = n ^ m;
    if (ans < n && ans > 0 && (ans ^ n) > 0 && (ans ^ n) < n) {
        cout << "1\n" << n << " " << m << endl;
        return;
    }
    vector<int> v;

    for (int i = 61; i >= 0; i--) {
        if (bit(n, i) && !bit(m, i)) {
            v.pb(i);
        }
    }

    int nw = n;
    for (int i = 61; i >= 0; i--) {
        if (!bit(n, i) && bit(m, i))
            nw += (1ll << i);
    }
    if (v.size() >= 1)nw -= (1ll << v[0]);


//    cout << bitset<3>(nw^n) << endl;
    if (nw >= n || nw <= 0 || (nw ^ n) <= 0 || (nw ^ n) >= n) {
        cout << -1 << endl;
        return;
    }


    ans = nw ^ m;
    if (ans >= nw || ans <= 0 || (ans ^ nw) <= 0 || (ans ^ nw) >= nw) {
        cout << -1 << endl;
        return;
    }

    cout << 2 << endl;
    cout << n << " " << nw << " " << m << endl;
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