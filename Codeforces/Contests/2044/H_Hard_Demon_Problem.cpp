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

const int N = 2050, mod = 1e9 + 7, INF = 1e18 + 10;

int t[N][N];
int pref[N][N], suff[N][N], suff_star[N][N];
int n, q;

void init() {
    for (int i = 0; i <= n + 20; i++)
        for (int j = 0; j <= n + 20; j++) {
            pref[i][j] = suff[i][j] = suff_star[i][j] = t[i][j] = 0;
        }
}

void Solve() {
    cin >> n >> q;
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> t[i][j];
        }
    for (int i = 1; i <= n + 3; i++)
        for (int j = 1; j <= n + 3; j++) {
            pref[i][j] = t[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }

    auto get_sum = [&](int x1, int y1, int x2,int y2) {
        int sum = 0;
        sum += pref[x2][y2];
        sum -= pref[x1 - 1][y2];
        sum -= pref[x2][y1 - 1];
        sum += pref[x1 - 1][y1 - 1];
        return sum;
    };
    for (int i = 0; i <= n + 2; i++) {
        for (int j = n + 2; j >= 0; j--) {
            suff[i][j] = suff[i][j + 1] + get_sum(i, j, i, n);
        }
    }

    for (int i = n + 2; i >= 0; i--) {
        for (int j = n + 2; j >= 0; j--) {
            suff[i][j] += suff[i + 1][j];
        }
    }
    for (int i = n + 2; i >= 0; i--) {
        for (int j = n + 2; j >= 0; j--) {
            suff_star[i][j] = suff_star[i + 1][j] + get_sum(i + 1, j, n, n);
        }
    }
    auto calculate = [&](int x1, int y1, int x2, int y2)-> int {
        int ans = 0, deg = 0, partie_isar = 0;

        ans += suff[x1][y1];
        ans -= suff[x2 + 1][y1];

        partie_isar += suff[x1][y2 + 1];
        partie_isar -= suff[x2 + 1][y2 + 1];

        partie_isar += get_sum(x1, y2 + 1, x2, n) * (y2 - y1 + 1);

        ans -= partie_isar;


        deg += suff_star[x1][y1] - suff_star[x1][y2 + 1];
        deg -= (suff_star[x2 + 1][y1] - suff_star[x2 + 1][y2 + 1] + get_sum(x2 + 1, y1, n, y2) * (x2 - x1 + 1));
        deg *= (y2 - y1 + 1);

        ans += deg;
        return ans;
    };

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << calculate(x1, y1, x2, y2) << " ";
    }
    cout << endl;

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
