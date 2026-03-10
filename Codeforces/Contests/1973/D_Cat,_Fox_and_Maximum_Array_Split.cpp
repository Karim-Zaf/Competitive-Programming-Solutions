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

int ask(int pos, int x) {
    cout << "? " << pos << " " << x << endl;
    cout.flush();
    int xx;
    cin >> xx;
    return xx;
}

void ans(int x) {
    cout << "! " << x << endl;
    cout.flush();
    int xx;
    cin >> xx;
    if (xx == -1) exit(0);
}

void Solve() {
    int n, k;
    cin >> n >> k;
    int mx;
    for (int i = 1; i <= n; i++) {
        int curr = ask(1, n * i);
        if (curr == n) mx = i;
    }

    for (int sz = 1; sz <= n / k; sz++) {
        int p = 1, cnt = 0;

        while (p <= n && cnt < k) {
            cnt++;
            p = ask(p, sz * mx) + 1;
        }

        if (cnt == k && p == n + 1) {
            ans(sz * mx);
            return;
        }
    }
    ans(-1);
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