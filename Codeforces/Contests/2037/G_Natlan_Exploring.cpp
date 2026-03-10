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

const int N = 1e6 + 30, mod = 998244353, INF = 1e18 + 10;

int binpow(int a, int k, int res = 1,int Mod = mod) {
    while (k) {
        if (k % 2) res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a,int Mod = mod) { return binpow(a, Mod - 2); }
int mult(int a, int b,int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b,int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }
int divide(int a, int b,int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}


vector<int> factors(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        if (n % i) continue;
        res.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) res.push_back(n);
    return res;
}


void Solve() {
    int n;
    cin >> n;

    vector<int> v(n), dp(N), ans(n);
    for (auto& x : v) cin >> x;


    for (int i = 0; i < n; i++) {
        vector<int> primes = factors(v[i]);
        int sz = primes.size();

        for (int mask = 1; mask < (1 << sz); mask++) {
            int prd = 1;
            for (int j = 0; j < sz; j++) if (mask & (1 << j)) prd *= primes[j];

            if (__builtin_popcount(mask) % 2) ans[i] = add(ans[i], dp[prd]);
            else ans[i] = add(ans[i], -dp[prd]);
        }
        if (i == 0) ans[i] = 1;

        for (int mask = 1; mask < (1 << sz); mask++) {
            int prd = 1;
            for (int j = 0; j < sz; j++) if (mask & (1 << j)) prd *= primes[j];

            dp[prd] = add(dp[prd], ans[i]);
        }
    }

    cout << ans.back() << endl;
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
