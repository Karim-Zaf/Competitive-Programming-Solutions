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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<long long> primes;

void sieve() {
    vector<int> visited(N);
    for (int i = 2; i < N; i++) {
        if (visited[i]) continue;
        primes.push_back(i);
        for (int j = i; j < N; j += i)
            visited[j] = 1;
    }
}

void Solve() {
    int n, ans = 1;
    cin >> n;
    sieve();
    vector<int> coef;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            coef.pb(i);
        }
    }
    if (n > 1) coef.pb(n);

    sort(rall(coef));


    for (int i = 0; i < coef.size(); i++)
        for (int j = 0; j < coef[i] - 1; j++)
            ans *= primes[i];

    int res = ans, coef2 = coef.front();

    for (int i = coef.size() - 1; i >= 0; i--) {
        for (int j = 0; j < coef[i] - 1; j++)
            ans /= primes[i];
        for (int j = 0; j < coef2 - 1; j++)ans /= 2;
        coef2 *= coef[i];
        for (int j = 0; j < coef2 - 1; j++)ans *= 2;
        if (ans > 0)
            res = min(ans, res);
    }
    cout << res << endl;
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