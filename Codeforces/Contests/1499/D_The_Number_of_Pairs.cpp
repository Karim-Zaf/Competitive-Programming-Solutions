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

const int N = 2e7 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

int nbprimedivsors[N];

void sieve() {
    for (int i = 2; i < N; i++) {
        if (nbprimedivsors[i]) continue;
        for (int j = i; j < N; j += i)
            nbprimedivsors[j]++;
    }
}

void Solve() {
    int c, d, x, ans = 0;
    cin >> c >> d >> x;
    vector<int> divisors;

    for (int i = 1; i * i <= x; i++) {
        if (x % i)continue;
        divisors.pb(i);
        if (i == x / i) continue;
        divisors.pb(x / i);
    }

    for (auto divi: divisors) {
        int curr = (divi + d) / c;
        if ((divi + d) % c)continue;
        ans += 1ll << nbprimedivsors[curr];
    }
    cout << ans << endl;
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    sieve();
    cin >> Test_case;
    while (Test_case--) Solve();
}