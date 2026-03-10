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


void Solve() {
    int l, r, x;
    cin >> l >> r >> x;
    if (x >= 10) return void(cout << 0 << endl);

//    auto calc = [&](int x) {
//        string s = to_string(x);
//        int ss = 0;
//        for (auto c: s) {
//            ss += (c - '0');
//        }
//        return ss;
//    };
//
//    for (int i = binpow(10, l); i < binpow(10, r); i++) {
//        if (calc(i * x) == x * calc(i)) {
//            kar(i);
//        }
//
//    }

    auto suite = [&](int r, int n) {

        int ans = binpow(r, n );
        ans = add(ans, -1);
        ans = mult(ans, r);
        ans = divide(ans, r - 1);
        return ans;
    };
    int cnt = 0;
    for (int i = 1; i <= 9; i++) {
        cnt += (i * x <= 9);
    }

    int ans = suite(cnt + 1, r);
    ans = add(ans, -suite(cnt + 1, l));
    ans = divide(ans, cnt + 1);
    ans = mult(ans, cnt);
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}