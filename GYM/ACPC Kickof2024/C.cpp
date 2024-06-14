/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "debug.cpp"
// #else
// #define kar(...)
// #endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 1e6 + 10, mod = 1e9 + 7, INF = 1e18 + 10;

int dp[N], sum[N], mp[N];

int binpow(int a, int k, int res = 1, int Mod = mod) {
    while (k) {
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a, int Mod = mod) { return binpow(a, Mod - 2); }

int mult(int a, int b, int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }

int divide(int a, int b, int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}

int fact[N]{1}, invfact[N]{1};

void factorial() { for (int i = 1; i < N; i++)fact[i] = mult(i, fact[i - 1]); }

void inverses() {
    invfact[N - 1] = modinv(fact[N - 1]);
    for (int i = N - 1; i >= 1; i--)invfact[i - 1] = mult(invfact[i], i);
}

int C(int n, int k) {
    if (n < k)return 0;
    return mult(fact[n], mult(invfact[n - k], invfact[k]));
}

int starsandbars(int n, int k) { return C(n + k - 1, n); }

void Solve() {
    factorial();
    inverses();
    int n, k;
    cin >> n >> k;

    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) sum[v[i]]++;
    for (int i = 1; i <= n; i++) mp[v[i]]++;
    for (int i = 1; i < N; i++)
        for (int j = i + i; j < N; j += i)
            sum[i] += sum[j];

    for (int i = N - 1; i >= 1; i--) {
        for (int j = i; j < N; j += i) {
            dp[i] = add(dp[i], mult(j,mult(mp[j], C(sum[i] - 1, k - 1))));
        }
        for (int j = i + i; j < N; j += i)
            dp[i] = add(dp[i], -dp[j]);
    }
    cout << dp[1];
}

int32_t main() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
//    #endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
