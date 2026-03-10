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
#define int ll 
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

#define endl '\n'

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> sv[N], dv[N];
vector<pair<int, int>> queries[N];

void Solve() {

    int n, m;
    int x, y;
    cin >> n >> m >> x >> y;;
    if (min(n, m) == 1) cout << 1 << endl;
    else if (n == 2) {
        cout << (y - 1) / 2 + (m - y) / 2 + 1 << endl;
    } else if (m == 2) {
        cout << (x - 1) / 2 + (n - x) / 2 + 1 << endl;
    } else if (n == 3 && m == 3) {
        if (x == 2 && y == 2) cout << 1 << endl;
        else cout << 8 << endl;
    } else cout << n * m << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
