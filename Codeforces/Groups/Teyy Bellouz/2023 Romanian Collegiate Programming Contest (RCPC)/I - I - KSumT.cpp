/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE

#include "debug.cpp"

#else
#define kar(...)
#endif
#define endl '\n'

const int N = 5e6 + 5, Mod = 1e9 + 7;


int binpow(int a, int k, int res = 1) {
    while (k) {
        if (k % 2)res = 1ll * res * a % Mod;
        a = 1ll * a * a % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a) { return binpow(a, Mod - 2); }

int mult(int a, int b) {
    b %= Mod;
    return 1ll * a % Mod * b % Mod;
}

int add(int a, int b) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }

vector<int> fact(N,1), invfact(N,1);

void factorial() { for (int i = 1; i < N; i++)fact[i] = mult(i, fact[i - 1]); }

void inverses() {
    invfact[N - 1] = modinv(fact[N - 1]);
    for (int i = N - 1; i >= 1; i--)invfact[i - 1] = mult(invfact[i], i);
}

int C(int n, int k) {
    if (n < k)return 0;
    return mult(fact[n], mult(invfact[n - k], invfact[k]));
}

int starsandbars(int n, int k) { return C(n - 1, k - 1); }


void Solve() {
    int k, sum, t, ans = 0;
    cin >> k >> sum >> t;
    factorial();
    inverses();

    int block1 = k / t + 1, block2 = k / t;

    // sizeof blocks exple : 123|45  123|45  123|45  123

    if (k % t == 0) {
        if (sum % block2) {// sum cannot be divided ;
            cout << 0 << endl;
        } else {
            cout << starsandbars(sum / block2, t) << endl;
        }
        return;
    }
    for (int i = 0; i <= sum; i++) {
        int sum1 = i;
        int sum2 = sum - i;

        if (sum1 % block1 || sum2 % block2) continue;

        sum1 /= block1;
        sum2 /= block2;

        int curr = mult(starsandbars(sum1, k % t), starsandbars(sum2, t - k % t));
        ans = add(ans, curr);
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}