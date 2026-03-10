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
#define endl '\n'

const int N = 505, mod = 1e9 + 7, INF = 1e18 + 10;

int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }

int ok[N];
int n, m, tot;
string a, b;
int dp[N][N];

int work(int pos, int moves) {

    if (moves > tot) return 0;

    if (pos >= n + 1)return 1;

    int &ret = dp[pos][moves];
    if (ret != -1) return ret;
    int curr = ok[pos] - ok[pos - 1];
    if (!curr) {
        ret = work(pos + 1, moves);
        return ret;
    }
    ret = 0;
    for (int i = pos + m - 1; i>=pos ; i--) {
        if (ok[i] - ok[i - 1]){
            ret = add(ret, work(i + m, moves + 1));
        }
    }

    return ret;
}

void Solve() {
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = "#" + a;
    b = "#" + b;

    for (int i = 0; i <= n + 2; i++)
        for (int j = 0; j <= n + 2; j++)
            dp[i][j] = -1;
    for (int i = 1; i <= n + 4; i++)ok[i] = 0;


    for (int i = 1; i <= n; i++) {
        ok[i] = 1;
        for (int j = 1; j <= m; j++) {
            if (i + j - 1 > n || b[j] != a[i + j - 1]) ok[i] = 0;
        }
        ok[i] += ok[i - 1];
    }

    int mn = 0, i = 1;
    while (i <= n) {
        if (!(ok[i] - ok[i - 1])) {
            i++;
            continue;
        }
        int nxt = i + m - 1, nwnxt = -1;
        int j = i;
        while (j <= nxt) {
            if (ok[j] - ok[j - 1]) {
                nwnxt = j + m;
            }
            j++;
        }
        i = max(nxt, nwnxt);
        mn++;
    }
    tot = mn;
    cout << mn << " "<< work(1, 0) << endl;
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