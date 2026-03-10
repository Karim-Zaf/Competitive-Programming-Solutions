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
    int n, k;
    cin >> n >> k;

    if (n >= 60) {
        cout << "YES " << n - 1 << endl;
        return;
    }

    int unit = n, left = 1, iteration = 1, move = 0, extramoves = 0;

    while (unit >= 1) {
        int alll = left * 4; // number of left squares after divide
        move += left;
        left = (2ll << iteration) - 1; // cells in the path


        int curr = alll - left; // we can divide them as we want
        unit--;
        extramoves += curr * (powl(4ll, unit) - 1) / 3;// they are of size unit so we can divide them unit times
        // suite arithmetique
        if (move >= 0 && move <= k && (move + extramoves >= k || extramoves < 0)) {
            cout << "YES " << unit << endl;
            return;
        }

        iteration++;
    }
    cout << "NO\n";

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