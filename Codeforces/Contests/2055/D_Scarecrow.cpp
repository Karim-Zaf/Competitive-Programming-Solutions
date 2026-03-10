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
    int n, k, l;
    cin >> n >> k >> l;

    vector<int> v(n);
    for (auto &x: v)cin >> x;

    int prev = -1;
    double time = 0;
    double pos = k;
    time += *v.begin() ;


    sort(all(v));
    for (auto &x: v) {
        if (prev == -1) {
            prev = x;
            continue;
        }
        if (x < pos) {
            double mx = min(pos, x + time);
            pos = mx + k;
            prev = x;
            continue;
        }

        double blasa = max(pos, x - time);

        // ytkablou fl west

        double md = pos + (blasa - pos) / 2;
        time += (blasa - pos) / 2;
        pos = md + k;
        prev = x;
    }
    cout << (int)(2 * (time + max(double(0), l - pos)) )<< endl;
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
