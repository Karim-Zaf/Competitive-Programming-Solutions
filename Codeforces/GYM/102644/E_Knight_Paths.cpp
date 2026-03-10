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

const int N = 3e5 + 30, mod = (1ll<<32), MOD = mod, INF = 1e18 + 10;

const int N_mat = 70;

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
                    product.a[i][j] += (a[i][k] * other.a[k][j]) % MOD;
                    (product.a[i][j] +=MOD)%= MOD;
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

int dx[] = {-1, -2, 2, 1, 1, 2, -1, -2};
int dy[] = {-2, -1, 1, 2, -2, -1, 2, 1};


int code(int i, int j) {
    return (i - 1) * 8 + j;
}

void Solve() {
    int n;
    cin >> n;
    Matrix ans;

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            int cell = code(i, j);
            for (int p = 0; p < 8; p++) {
                int x = i + dx[p];
                int y = j + dy[p];
                if (x > 8 || y > 8 || x < 1 || y < 1)continue;
                int can = code(x, y);
                ans.a[cell][can] = 1;
            }
        }
    }
    kar (mod)
    for (int i = 1; i <= 65; i++) ans.a[65][i] = 1;
    ans = expo_power(ans, n + 1);
    cout << ans.a[65][1];
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