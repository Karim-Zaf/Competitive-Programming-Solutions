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

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void Solve() {
    int l = 2, r = 999, ans = -1;
    while (l <= r) {
        int md1 = l + (r - l) / 3;
        int md2 = l + 2 * (r - l) / 3;
        int x = ask(md1, md2);

        kar(md1, md2);
        if (x == (md1 + 1) * (md2 + 1)) {
            ans = md1;
            r = md1 - 1;
        } else if (x == md1 * md2)l = md2 + 1;
        else {
            ans = md2;
            l = md1 + 1, r = md2 - 1;
        }
    }

    assert (ans != -1);
    cout << "! " << ans << endl;
    cout.flush();
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