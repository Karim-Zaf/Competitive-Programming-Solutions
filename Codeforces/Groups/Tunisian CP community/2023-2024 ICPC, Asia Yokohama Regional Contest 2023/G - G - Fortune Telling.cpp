/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#pragma gcc optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define endl '\n'

const int N = 3e5 + 5, mod = 998244353;

int binpow(ll a, ll k, ll res = 1, int Mod = mod) {
    while (k) {
        if (k % 2) res = (res * 1ll * a) % Mod;
        a = (a * 1ll * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a, int Mod = mod) { return binpow(a, Mod - 2); }

int mult(int a, int b, int Mod = mod) {
    b %= Mod;
    return a % Mod * 1ll * b % Mod;
}

int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) * 1ll % Mod + Mod) % Mod; }

int divide(int a, int b, int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * 1ll * b) % Mod;
}

unordered_map<int, int> dp[N];
int prep[10];

int work(int pos, int rem) {
    if (rem == 1) return 1;
    if (dp[pos].count(rem)) return dp[pos][rem];

    int& ret = dp[pos][rem];

    ret = 0;

    for (int i = 0; i < min(rem, 6); i++) {
        if (i == pos % 6) continue;
        ret = add(ret, mult(prep[min(rem, 6)], work(pos - (pos / 6) - (pos % 6 > i), rem - (rem / 6) - (rem % 6 > i))));
    }
    return ret;
}

void Solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= 6; i++) prep[i] = divide(1, i);

    for (int i = 0; i < n; i++) cout << work(i, n) << endl;
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
