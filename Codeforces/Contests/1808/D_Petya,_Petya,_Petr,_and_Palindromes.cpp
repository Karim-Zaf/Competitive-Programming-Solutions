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

vector<int> t[N][2];


int get(int l, int r, int x, int indx) {
    vector<int> &vect = t[x][indx % 2];
    int lef = lower_bound(all(vect), l) - vect.begin();
    int righ = upper_bound(all(vect), r) - vect.begin();
    int ret = righ - lef ;
    return ret;
}

void Solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> v(n + 3);
    for (int i = 1; i <= n; i++)cin >> v[i];
    for (int i = 1; i <= n; i++) t[v[i]][i % 2].pb(i);


    for (int i = 1; i <= n; i++) {


        int first_center = max(i, 1 + k / 2);
        int last_center = min(i + k / 2, n - k / 2);

        if (last_center < first_center) continue;

        int l = i + (first_center - i) * 2;
        int r = i + (last_center - i) * 2;

        int req = (last_center - first_center + 1);

        ans +=  req - get(l, r, v[i], i) ;
    }
    cout << ans << endl;
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