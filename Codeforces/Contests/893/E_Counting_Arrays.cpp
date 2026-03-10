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


vector<int> spf(N), primes;

void sieve() {
    for (int i = 1; i < N; i++) spf[i] = i;
    for (int i = 2; i < N; i++) {
        if (spf[i] != i) continue;
        primes.push_back(i);
        for (int j = i; j < N; j += i) spf[j] = min(spf[i], i);
    }
}

vector<pair<int,int>> factors(int n) {
    vector<pair<int,int>> res;

    map<int,int> mp;

    while (n > 1) {
        mp[spf[n]]++;
        n /= spf[n];
    }
    for (auto val : mp) res.push_back(val);
    return res;
}

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

int fact[N]{1}, invfact[N]{1};
void factorial() { for (int i = 1; i < N; i++) fact[i] = mult(i, fact[i - 1]); }

void inverses() {
    invfact[N - 1] = modinv(fact[N - 1]);
    for (int i = N - 1; i >= 1; i--) invfact[i - 1] = mult(invfact[i], i);
}

int C(int n, int k) {
    if (n < k) return 0;
    return divide(fact[n], mult(fact[n - k], fact[k]));
}

int starsandbars(int n,int k) { return C(n + k - 1, n); }

void Solve() {

    int x, y, ans = 1;
    cin >> x >> y;

    vector<pair<int,int>> res = factors(x);

    for (auto [prime , occ] : res) {
        ans = mult(ans, starsandbars(occ, y));
    }

    ans = mult(ans, binpow(2, y - 1));
    cout << ans << endl;


}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    factorial();
    inverses();
    sieve();
    cin >> Test_case;
    while (Test_case--) Solve();
}
