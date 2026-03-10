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


const int LG = log2(N) + 2;
int dp[N][LG];


void Solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 4);

    for (int i = 1; i <= n; i++) cin >> v[i];


    auto bit = [&](int x, int b) {
        return ((1 << b) & x) != 0;
    };

    for (int i = 1; i <= n; i++) for (int j = 0; j < LG; j++) dp[i][j] = INF;

    vector<int> nxt(LG, -1);
    for (int i = n; i >= 1; i--) {

        for (int j = 0; j < LG; j++) {
            if (bit(v[i], j)) {
                dp[i][j] = i;
                if (nxt[j] == -1) continue;
                for (int k = 0; k < LG; k++) {
                    dp[i][k] = min(dp[i][k], dp[nxt[j]][k]);
                }
            }

        }


        for (int j = 0; j < LG; j++) {
            if (bit(v[i], j)) {
                nxt[j] = i;
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;

        bool ret = false;
        for (int i = 0; i < LG; i++) {
            if (bit(v[y], i) && dp[x][i] <= y) {
                ret = true;
            }
        }


        cout << (ret ? "Shi" : "Fou") << endl;
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
