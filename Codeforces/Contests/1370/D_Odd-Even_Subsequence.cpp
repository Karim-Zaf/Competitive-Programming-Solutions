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
vector<int> v;
vector<pair<int, int>> vp;
int n, k;


int cnt(int x, int indx) {
    pair<int, int> p = {x, INF};

    vector<int> curr;
    int pos = upper_bound(all(vp), p) - vp.begin(), ret = 0, prev = -5;
    for (int i = 0; i < pos; i++) curr.pb(vp[i].S);
    sort(all(curr));

    if ((indx == 2 || indx == 4) && curr.back() == n - 1)curr.pop_back();
    if ((indx == 3 || indx == 2) && curr[0] == 0)curr.erase(curr.begin());

    for (auto c: curr)
        if (c - prev >= 2)
            prev = c, ret++;

    return ret;
}

void Solve() {
    cin >> n >> k;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v.pb(x);
        vp.pb({x, i});
    }
    sort(all(vp)), sort(all(v));

    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        int md = l + (r - l) / 2;

        int one = cnt(v[md], 2);
        int two = cnt(v[md], 1);
        int three = cnt(v[md], 3);
        int four = cnt(v[md], 4);

        if (k % 2 && (one >= k / 2 || two >= k / 2 + 1)) {
            r = md - 1;
            ans = md;
        } else if (k % 2 == 0 && (four >= k / 2 || three >= k / 2)) {
            r = md - 1;
            ans = md;
        } else l = md + 1;
    }
    cout << v[ans] << endl;
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