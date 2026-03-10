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

const int N = 3e6 + 30, mod = 998244353, MOD = mod, INF = 1e18 + 10;

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

int fact[N]{1};

void factorial() { for (int i = 1; i < N; i++)fact[i] = mult(i, fact[i - 1]); }

int C(int n, int k) { return divide(fact[n], mult(fact[n - k], fact[k])); }

int starsandbars(int n, int k) {
    if (k == 0)return 1;
    return C(n + k - 1, n);
}

void Solve() {
    int one, two, three, four;
    cin >> one >> two >> three >> four;
    if (!one && !two && (!three || !four)) {
        cout << 1 << endl;
        return;
    }
    if (!one && !two) {
        cout << 0 << endl;
        return;
    }

    if (abs(one - two) > 1) {
        cout << 0 << endl;
        return;
    }

    if (one <= two) swap(one, two);

    int ans = 1;
    if (one == two) {
        int ans1 = 1, ans2 = 1;
        int blasa_three = starsandbars(four, one + 1);
        int blasa_four = starsandbars(three, one);
        ans1 = mult(blasa_four, blasa_three);
        blasa_three = starsandbars(four, one);
        blasa_four = starsandbars(three, one + 1);
        ans2 = mult(blasa_four, blasa_three);
        ans = add(ans1, ans2);
    } else {
        int blasa_three = starsandbars(four, one);
        int blasa_four = starsandbars(three, one);
        ans = mult(blasa_four, blasa_three);
    }

    cout << ans << endl;

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    factorial();
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}