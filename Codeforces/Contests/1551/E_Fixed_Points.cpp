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

int dp[2005][2005], suff[2005][2005];
vector<int> v;
int n, k;

int work(int pos, int remove) {
    if (pos <= 0 && remove) return -INF;
    if (pos <= 0) return 0;

    int &ret = dp[pos][remove];
    if (ret != -1) return ret;

    // I will keep it
    ret = (v[pos] == pos - remove) + work(pos - 1, remove);
    if (remove) ret = max(ret, work(pos - 1, remove - 1)); // I will remove it

    return ret;
}

void Solve() {
    cin >> n >> k;
    v.resize(n + 3);

    for (int i = 0; i < n + 5; i++)
        for (int j = 0; j < n + 5; j++)
            dp[i][j] = -1;

    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int remove = 0; remove <= n + 3; remove++) {
        if (work(n, remove) >= k) {
            cout << remove << endl;
            return;
        }
    }

    cout << -1 << endl;
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