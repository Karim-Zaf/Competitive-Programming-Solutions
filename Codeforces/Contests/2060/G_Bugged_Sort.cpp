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

vector<array<int, 3>> vp;
int dp[2][2][N];
int n;

bool work(int indx, int prev, int curr) {
    array<int, 3> a = vp[curr];
    array<int, 3> p = vp[curr -1];

    if (prev) swap(p[1], p[2]);

    if (curr == n-1) {
        if (indx) swap(a[1], a[2]);
        return a[1] > p[1] && a[2] > p[2];
    }
    int &ret = dp[indx][prev][curr];
    if (ret != -1) return ret;
    ret = 0;
    if (a[1] > p[1] && a[2] > p[2]) ret |= work(indx, 0, curr + 1);
    
    // ekleb
    swap(a[1], a[2]);
    if (a[1] > p[1] && a[2] > p[2]) ret |= work(indx ^ 1, 1, curr + 1);

    return ret;
}


void Solve() {
    cin >> n;
    vp.resize(n);
    for (auto &[mn, a, b]: vp) cin >> a;
    for (auto &[mn, a, b]: vp) cin >> b;
    for (auto &[mn, a, b]: vp)mn = min(a, b);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                dp[j][k][i] = -1;

    sort(all(vp));
    int ans = 0;
    ans |= work(1, 1, 1);
    ans |= work(0, 0, 1);
    cout << (ans ? "YES" : "NO") << endl;


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