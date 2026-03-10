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
#define int ll
#define endl '\n'

const int N = 2e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<long long> primes, vis(N);

void sieve() {
    vector<int> visited(N);
    for (int i = 2; i < N; i++) {
        if (visited[i]) continue;
        primes.push_back(i);
        vis[i] = 1;
        for (int j = i; j < N; j += i) visited[j] = 1;
    }
}

void Solve() {

    // kar(primes);
    // vis[0] = 1;
    // for (auto x : primes) {
    //
    //     string ss = to_string(x);
    //     int len = ss.size();
    //
    //     int ok = 1;
    //     for (int i = 0; i < len; i++) {
    //         for (int j = i; j < len; j++) {
    //             string nw = "";
    //             for (int k = i; k <= j; k++) nw += ss[k];
    //
    //             int curr = stoll(nw);
    //             if (!vis[curr]) ok = 0;
    //         }
    //     }
    //     if (ok)
    //         kar(x);
    //
    // }


    vector<int> pot_primes{2, 3, 5, 7, 23, 37, 53, 73, 373};

    int l, r;
    cin >> l >> r;

    int ans = 0;

    for (auto x : pot_primes) {
        ans += (l <= x && x <= r);
    }

    cout << ans << endl;
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    // sieve();
    while (Test_case--) Solve();
}
