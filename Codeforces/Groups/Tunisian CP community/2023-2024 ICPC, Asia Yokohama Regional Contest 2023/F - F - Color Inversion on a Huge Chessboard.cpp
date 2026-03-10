/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {
    int n, q;
    cin >> n >> q;

    vector<int> columns(n + 1), rows(n + 1);
    for (int i = 1; i <= n; i += 2) columns[i] = rows[i] = 1;

    int r = n, c = n;


    while (q--) {
        string s;
        int x;
        cin >> s >> x;

        if (s[0] == 'R') {
            r -= (x != 1 && rows[x] != rows[x - 1]);
            r -= (x + 1 <= n && rows[x + 1] != rows[x]);

            rows[x] ^= 1;

            r += (x != 1 && rows[x] != rows[x - 1]);
            r += (x + 1 <= n && rows[x + 1] != rows[x]);

        } else {
            c -= (x != 1 && columns[x] != columns[x - 1]);
            c -= (x + 1 <= n && columns[x + 1] != columns[x]);

            columns[x] ^= 1;

            c += (x != 1 && columns[x] != columns[x - 1]);
            c += (x + 1 <= n && columns[x + 1] != columns[x]);
        }

        cout << r * c << endl;
    }


}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
