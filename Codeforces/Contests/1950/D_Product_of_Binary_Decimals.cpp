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

int dp[N];

void Solve() {

    int n;
    cin >> n;
    cout << (dp[n] ? "YES" : "NO") << endl;


}

void pre() {
    vector<int> vect{1, 10, 100, 1000, 10000}, s;
    for (int i = 1; i < (1 << 5); i++) {
        int add = 0;
        for (int j = 0; j < 5; j++) {
            if ((1 << j) & i)
                add += vect[j];

        }
        dp[add] = 1;
        s.pb(add);
    }
    for (int i = 0; i < N; i++) {
        for (auto x: s) {
            if (i % x == 0 && dp[i / x]) dp[i] = 1;
        }
    }

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;

    pre();
    while (Test_case--) Solve();
}