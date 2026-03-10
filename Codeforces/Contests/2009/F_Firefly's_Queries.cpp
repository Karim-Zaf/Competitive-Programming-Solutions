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
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 4), pref(n + 4);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];


    auto get = [&](int l, int r) {
        return pref[r] - pref[l - 1];
    };

    auto cnt = [&](int l, int r) {
        l = (l - 1) % n + 1;
        r = (r - 1) % n + 1;
        if (l <= r) return get(l, r);
        else return get(l, n) + get(1, r);
    };

    while (q--) {
        int l, r;
        cin >> l >> r;

        int c2 = (r - 1) / n;
        int c1 = (l - 1) / n;

        int l2 = l + (n - 1) - (l - 1) % n;
        int r2 = r - (r - 1) % n;
        int sum_lef = cnt(l + c1, l2 + c1);
        int sum_righ = cnt(r2 + c2, r + c2);


        int sum = (r2 - l2 - 1) / n * get(1, n);

        if (c1 == c2) {
            sum_lef = 0;
            sum_righ = 0;
            sum = cnt(l + c1, r + c1);
        }

        cout << sum + sum_lef + sum_righ << endl;
    }


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