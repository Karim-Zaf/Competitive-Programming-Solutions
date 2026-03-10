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
    string a, b, aa, bb;
    cin >> n;

    cin >> a >> b;
    a = "#" + a;
    b = "#" + b;
    aa = a;
    bb = b;


    for (int i = 1; i <= n - 2; i++)
        if (a[i] == a[i + 2] && a[i] == '0')
            b[i + 1] = '1';

    for (int i = 1; i <= n - 2; i++)
        if (b[i] == b[i + 2] && b[i] == '1')
            a[i + 1] = '1';


    vector<int> pref(n + 3);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + (a[i] == '1');

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = 0;
        ans += (aa[l] == '1');

        int ok = 0;
        if (l + 1 <= r) ok = (aa[l + 1] == '1');

        int lef = 0, righ = 0;
        lef = (bb[l] == '1');
        righ = (l + 2 <= r && bb[l + 2] == '1' ||
                l + 3 <= r && aa[l + 1] == aa[l + 3]);
        ok |= (lef & righ);
        ans += ok;

        if (r > l + 1) ans += (aa[r] == '1');

        ok = lef = righ = 0;
        if (r - 1 > l + 1) ok = (aa[r - 1] == '1');

        lef = (bb[r] == '1');
        righ = (r - 2 >= l && bb[r - 2] == '1' ||
                r - 3 >= l && aa[r - 1] == aa[r - 3]);

        ok |= (lef & righ);
        if (r - 1 <= l + 1)ok = 0;
        ans += ok;

        if (r - 2 > l + 1)
            ans += pref[r - 2] - pref[l + 1];

        cout << ans << endl;
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