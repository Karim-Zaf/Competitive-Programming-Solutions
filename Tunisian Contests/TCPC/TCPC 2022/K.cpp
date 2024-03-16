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

string a, b;
int n, x, y;

int dp[105][105][105], value[10];

int bit(int val, int i) {
    return (val & (1 << i)) != 0;
}

int work(int pos, int remx, int remy) {
    if (remx < 0 || remy < 0)return 0;
    if (pos == n)return 1;
    int &ret = dp[pos][remx][remy];
    if (ret != -1)return ret;
    ret = 0;
    int one = a[pos] - '0', two = b[pos] - '0', diff = 0;
    for (int i = 0; i < 7; i++) {
        diff += (bit(value[one], i) != bit(value[two], i));
    }
    for (int i = 0; i <= diff; i++) {
        int xx = i, yy = diff - i;
        ret |= work(pos + 1, remx - xx, remy - yy);
    }
    return ret;
}

int v(int e) { return (1 << e); }

void Solve() {
    cin >> n >> x >> y >> a >> b;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= y + 1; j++)
            for (int k = 0; k <= x + 1; k++)
                dp[i][k][j] = -1;
    cout << (work(0, x, y) ? "YES" : "NO") << endl;
}

void pre() {
    value[0] = v(0) + v(1) + v(2) + v(3) + v(4) + v(5);
    value[1] = v(1) + v(2);
    value[2] = v(0) + v(1) + v(3) + v(4) + v(6);
    value[3] = v(0) + v(1) + v(2) + v(3) + v(6);
    value[4] = v(1) + v(2) + v(5) + v(6);
    value[5] = v(0) + v(2) + v(3) + v(5) + v(6);
    value[6] = v(0) + v(2) + v(3) + v(4) + v(5) + v(6);
    value[7] = v(0) + v(1) + v(2);
    value[8] = v(0) + v(1) + v(2) + v(3) + v(4) + v(5) + v(6);
    value[9] = v(0) + v(1) + v(2) + v(3) + v(5) + v(6);
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    pre();
    while (Test_case--) Solve();
}
