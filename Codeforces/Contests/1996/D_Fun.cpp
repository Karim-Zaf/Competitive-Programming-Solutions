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
    int n, x, ans1 = 0, ans2 = 0, ans3 = 0;
    cin >> n >> x;

    int sq_n = sqrt(n);
    for (int a = 1; a <= min(n, x); a++) {

        for (int b = 1; b <= min(a - 1, n / a); b++) {
            int c = min((n - a * b) / (a + b), x - a - b);
            c = min({a - 1, b - 1, c});
            c = max(c, 0ll);
            if (a + b + c <= x && c < b && b < a) ans1 += c;
        }
    }

    ans1 *= 6;

    for (int a = 1; a <= max(n + 1, x + 1); a++) {
        int c = min((n - a * a) / (2 * a), x - 2 * a);
        c = max(c, 0ll);
        if (c >= a) {
            c--;
        }
        ans2 += c;
    }

    ans2 *= 3;

    for (int i = 1; i <= max(x + 1, n + 1); i++) {
        if (3 * i * i <= n && 3 * i <= x) ans3++;
    }


    cout << ans1 + ans2 + ans3 << endl;
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
