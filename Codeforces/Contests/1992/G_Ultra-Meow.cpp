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

const int N = 5005, mod = 1e9 + 7, INF = 1e18 + 10;

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


int Comb[N][N];
int C(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return Comb[n][k];
}

void Solve() {
    int n, ans = 0;
    cin >> n;

    for (int i = 1; i <= 2 * n + 1; i++) {
        for (int k = 0; k <= n && i <= n; k++) {
            int lekhor = min(n, i) - k - 1;
            if (lekhor > k) continue;
            ans = add(ans, mult(i, mult(C(i - 1, k), C(n - i, k - lekhor))));
        }
        for (int k = 0; k <= n && i > n; k++) if (k + k + 1 == i) ans = add(ans, mult(i, C(n, k)));
    }
    cout << ans << endl;
}


void preprocess() {
    Comb[0][0] = 1;
    for (int j = 1; j < N; j++) Comb[j][0] = 1;
    for (int i = 1; i < N; i++) for (int j = 1; j < N; j++) Comb[i][j] = add(Comb[i - 1][j], Comb[i - 1][j - 1]);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    preprocess();
    while (Test_case--) Solve();
}
