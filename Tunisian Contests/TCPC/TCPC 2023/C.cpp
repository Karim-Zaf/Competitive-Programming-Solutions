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

const int N = 2e6 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

vector<int> mp(N);
int ans = 0;

void sieve() {
    for (int i = 1; i < N / 2; i++)
        for (int j = i; j < N; j += i) {
            if (j % 2)continue;
            int x = j / 2 + i;
            if (x >= N) continue;
            ans += mp[j / 2] * mp[x];
        }
}

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x: v) {
        cin >> x;
        mp[x]++;
    }
    sieve();
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
