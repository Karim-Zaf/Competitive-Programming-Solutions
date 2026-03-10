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

int inv(int x) {
    int ret = 0;
    for (int b = 30; b >= 0; b--) {
        if (((1ll << b) & x) == 0)
            ret += (1ll << b);
    }
    return ret;
}

int bitt(int x, int b) {
    return (((1ll << b) & x) != 0);
}

void Solve() {
    int n, x, ans = 0;
    cin >> n >> x;

    vector<int> v(n + 1), pref(n + 1), bit(60, 0);


    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = pref[i - 1] ^ v[i];

        for (int b = 0; b <= 30; b++)
            bit[b] += (bitt(pref[i], b) == 0);

    }

    vector<int> vect;
    int flag = 0;
    for (int i = 1; i <= n; i++)vect.pb(pref[i]);

    for (int b = 30; b >= 0; b--) {
        vector<int> nw;
        int cnt = 0;
        for (auto elt: vect) {
            if (bitt(elt, b) == 0 && bitt(x, b) == 0)nw.pb(elt);
            if (bitt(x, b)) {
                nw.pb(elt);
            }
            cnt += (bitt(elt, b) == 0);
        }
        if (bitt(x, b) == 0 && bitt(pref[n], b)) {
            cout << (ans == 0 ? -1 : ans) << endl;
            return;
        }
        vect = nw;
        if (bitt(x, b) && bitt(pref[n],b)==0)ans = max(ans, cnt);
    }
    ans = max(ans, (int) vect.size());
    cout << (ans == 0 ? -1 : ans) << endl;

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