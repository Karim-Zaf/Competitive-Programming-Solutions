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

const int N = 1 << 22, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

int ans[N];

void Solve() {
    int n;
    cin >> n;
    vector<int> v, a(n);

    for (auto &x: a) {
        cin >> x;
        ans[x] = x;
    }

    for (int x = 1; x < N; x++) {
        for (int i = 0; i <= 21; i++) {
            int bit = (1 << i) & x;
            if (!bit) continue;
            int mkabel = x - (1 << i);
            if (ans[mkabel]) ans[x] = ans[mkabel];
        }
    }
    for (auto x: a) {
        int inv = x ^ ((1 << 22) - 1);
        cout << (ans[inv] ? ans[inv] : -1) << " ";
    }
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