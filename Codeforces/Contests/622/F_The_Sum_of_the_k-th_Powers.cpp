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
    return divide(fact[n], mult(fact[n - k], fact[k]));
}

int starsandbars(int n, int k) { return C(n + k - 1, n); }

void Solve() {
    int n, k;
    cin >> n >> k;

    factorial();


    // formule lagrange
    /*
     * f(1) = 1^k
     * f(2) = 1^k + 2^k
     * f(3) = 1^k + 2^k + 3^k
     * f(x) = 1^k + 2^k + 3^k + ... + x^k = formule de la grang (k+1) --> (1,f(1)) , (2 , f(2)) ....
     * we can calculate the (k+1) first point in linear time as (k <= 10^6)
     */

    int p = 0;

    vector<pair<int, int>> points(k + 2);

    int f_i = 0;
    for (int i = 0; i <= k + 1; i++) {
        f_i = add(f_i, binpow(i, k));
        points[i] = {i, f_i};
    }

    auto laGrange = [](int x, int deg, vector<pair<int, int>> &points) {
        // f(x) = sum [ yi * product (( x - a0 ) , (x -a1) ,....(x - ai-1), ... (x - ai+1) ... ,(x -asz))
        // divided by (product (( ai - a0 ) , (ai -a1) ,....(ai - ai-1), ... (ai - ai+1) ... ,(ai -asz))

        int sz = points.size();
        int ans = 0;

        int prod = 1;

        for (auto &[ai, yi]: points) {
            prod = mult(prod, (x - ai));
        }
        for (int i = 1; i < sz; i++) {
            // here in this PROBLEM (ai - ai-1) = 1
            prod = divide(prod, -i);
        }

        for (int i = 0; i < sz; i++) {
            auto &[ai, yi] = points[i];
            prod = divide(prod, (x - ai));

            kar(prod);
            ans = add(ans, mult(yi, prod));
            kar(ans);

            prod = mult(prod, (x - ai));

            prod = mult(prod, i - deg - 1);
            prod = divide(prod, i + 1);
        }

        return ans;
    };

    if (k == 0) return void(cout << n << endl);
    cout << (n <= k + 1 ? points[n].S : laGrange(n, k, points));
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