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

const int N = 1e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;


vector<int> graph[N], a(N), pref(N);

const int LG = 28;

int t[LG][N][2];
int ans = 0;

void dfs(int curr, int parent = 0) {
    pref[curr] = pref[parent] ^ a[curr];

    for (auto child : graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
    }


    for (int bit = 0; bit < LG; bit++) {
        int bit_curr_a = ((1 << bit) & a[curr]) != 0;
        int bit_curr = ((1 << bit) & pref[curr]) != 0;
        int bit_parent = ((1 << bit) & pref[parent]) != 0;
        int cnt = 0;


        for (auto child : graph[curr]) {
            for (int b = 0; b < 2 && child != parent; b++) t[bit][curr][b] += t[bit][child][b];
        }

        for (auto child : graph[curr]) {
            if (child == parent) continue;
            if (bit_curr_a == 0) {
                for (int b2 = 0; b2 < 2; b2++) {
                    cnt += t[bit][child][b2] * (t[bit][curr][b2 ^ 1] - t[bit][child][b2 ^ 1]);
                }
            } else {
                for (int b2 = 0; b2 < 2; b2++) {
                    cnt += t[bit][child][b2] * (t[bit][curr][b2] - t[bit][child][b2]);
                }
            }
        }

        t[bit][curr][bit_curr]++;
        cnt += 2 * t[bit][curr][bit_parent ^ 1];


        ans += (1 << bit) * cnt;
    }
}

void Solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);
    cout << ans / 2 << endl;
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
