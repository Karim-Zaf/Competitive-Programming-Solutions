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
 
const int N = 1e3 + 30, mod = 1e9 + 7, INF = 1e5 + 10;
 
vector<int> graph[N], a(N), sz(N, 1), bchild(N), mask(N);
int n, lc = 1, nb_primes;
int dp[N][600];
vector<pair<int, int>> primes;
 
vector<int> parc[600];
 
// void dfs_init(int curr, int parent = 0) {
//     for (auto child : graph[curr]) {
//         if (child == parent) continue;
//         dfs_init(child, curr);
//         if (sz[child] > sz[bchild[curr]]) bchild[curr] = child;
//         sz[curr] += sz[child];
//     }
// }
 
void dfs(int curr, int parent = -1) {
    for (auto child : graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
    }
 
    for (auto child : graph[curr]) {
        if (child == parent) continue;
 
        for (int m = 0; m < (1 << nb_primes); m++) {
            for (int m2 = 0; m2 < (1 << nb_primes); m2++) {
                dp[curr][m | m2] = min(dp[curr][m | m2], dp[curr][m2] + dp[child][m]);
            }
            dp[curr][m | mask[curr]] = min(dp[curr][m | mask[curr]], dp[child][m]);
        }
    }
    for (int i = 0; i < (1 << nb_primes); i++) dp[curr][i] = min(dp[curr][i] + 1, INF);
}
 
void preprocess() {
    int cnt = 0;
    for (int i = 0; i < (1 << nb_primes); i++) {
        for (int j = 0; j < (1 << nb_primes); j++) {
            if ((i & j) == 0) {
                parc[i].pb(j);
                cnt++;
            }
        }
        reverse(all(parc[i]));
    }
}
 
vector<pair<int, int>> factors(int n) {
    vector<pair<int, int>> res;
    for (int d = 2; d * d <= n; d++) {
        if (n % d) continue;
        int cnt = 0;
        while (n % d == 0) {
            n /= d;
            cnt++;
        }
        res.pb({d, cnt});
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}
 
void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) lc = lc / __gcd(lc, a[i]) * a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
 
    // dfs_init(1);
    primes = factors(lc);
    nb_primes = primes.size();
 
    // processing masks
    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> vp = factors(a[i]);
        for (auto p : vp) {
            for (int j = 0; j < nb_primes; j++) {
                if (primes[j] == p) mask[i] += (1 << j);
            }
        }
    }
 
    preprocess();
    for (int i = 0; i <= n; i++) {
        for (int x = 1; x < (1 << nb_primes); x++) dp[i][x] = 1e5;
    }
    for (int i = 1; i <= n; i++) {
        for (int m = mask[i]; m; m = (m - 1) & mask[i]) {
            dp[i][m] = 0;
        }
    }
 
    dfs(1);
 
 
    int ans = n;
    for (int i = 1; i <= n; i++) ans = min(ans, dp[i][(1 << nb_primes) - 1]);
    cout << ans << endl;
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