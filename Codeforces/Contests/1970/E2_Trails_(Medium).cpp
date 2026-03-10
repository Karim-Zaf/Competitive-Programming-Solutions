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


const int N_mat = 105;

struct Matrix {
    long long a[N_mat][N_mat];

    Matrix() {
        for (int i = 0; i < N_mat; i++)
            for (int j = 0; j < N_mat; j++)
                a[i][j] = 0;
    }

    Matrix operator*(Matrix other) {
        Matrix product;
        for (int i = 0; i < N_mat; i++)
            for (int j = 0; j < N_mat; j++)
                for (int k = 0; k < N_mat; k++) {
                    product.a[i][j] += (a[i][k] * other.a[k][j]) % mod;
                    product.a[i][j] %= mod;
                }
        return product;
    }
};

void print(Matrix s) {
    for (int i = 0; i < N_mat; i++) {
        for (int j = 0; j < N_mat; j++)
            cout << s.a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

Matrix expo_power(Matrix a, long long k) {
    Matrix ret;
    for (int i = 0; i < N_mat; i++) ret.a[i][i] = 1; //identity
    while (k) {
        if (k % 2)
            ret = ret * a;
        a = a * a;
        k /= 2;
    }
    return ret;
}

vector<int> s(105), l(105);


void Solve() {
    int n, m;
    cin >> m >> n;

    Matrix dp;

    for (int i = 1; i <= m; i++)cin >> s[i];
    for (int i = 1; i <= m; i++)cin >> l[i];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            int one = mult(s[i], l[j]);
            int two = mult(l[i], s[j]);
            int three = mult(s[i], s[j]);
            int sum = one;
            sum = add(sum, two);
            sum = add(sum, three);
            dp.a[i][j] = sum;
        }
    }

    dp = expo_power(dp, n);

    int ans = 0;

    for (int i = 1; i <= m; i++) ans = add(ans, dp.a[1][i]);

    cout << ans << endl;
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