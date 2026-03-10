/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int ll
#define endl '\n'
 
const int mod = 1e9 + 7, N = 1e6 + 10;
 
int fact[N]{1}, modinv[N];
 
int mult(int a, int b) {
    a %= mod, b %= mod;
    return a * b % mod;
}
 
 
int binpow(int a, int k) {
    int res = 1;
    while (k) {
        if (k % 2) res = mult(res, a);
        a = mult(a, a);
        k /= 2;
    }
    return res;
}
 
int divide(int a, int b) {
    a %= mod, b %= mod;
    return mult(a, binpow(b, mod - 2));
}
 
int add(int a, int b) {
    a %= mod, b %= mod;
    return ((a + b) % mod + mod) % mod;
}
 
int choose(int n, int k) {
    return mult(fact[n], mult(modinv[n - k], modinv[k]));
}
 
int starsandbras(int n, int k) {
    return choose(n + k - 1, n);
}
 
 
void Solve() {
    int n, s, g;
    cin >> n >> s >> g;
 
    if (s < g * n || s % g) return void(cout << "0\n");
 
    if (n == 1) {
        if (s == g) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
        return;
    }
 
 
    s /= g;
 
    if (s % n) {
        int reste = s % n;
        cout << choose(n, reste) << endl;
        return;
    }
 
    if (s == n) {
        cout << "1\n";
        return;
    }
 
    if (n == 2) return void(cout << 2 << endl);
 
    int ans = 0;
 
    int cnt = (n + 1) / 2 - 1;
    if (n % 2 == 0 && __gcd(s / n - 1, s / n + 1) == 1) cnt++;
    for (int i = 1; i <= cnt; i++) {
        int nw = choose(n, i);
        nw = mult(nw, choose(n - i, i));
        ans = add(ans, nw);
    }
 
 
    cout << ans << endl;
 
 
}
 
void prep() {
 
    for (int i = 1; i < N; i++) fact[i] = mult(fact[i - 1], i);
 
    modinv[N - 1] = divide(1, fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) modinv[i] = mult(modinv[i + 1], (i + 1));
}
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    prep();
 
    cin >> Test_case;
    while (Test_case--) Solve();
}