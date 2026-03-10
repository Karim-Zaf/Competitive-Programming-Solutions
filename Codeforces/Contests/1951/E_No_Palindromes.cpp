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


const int B1 = 9947, B2 = 1e9 + 3;
int pref[2][N], suff[2][N], n;

void Hash(string &s) {
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        pref[0][i] = add(pref[0][i - 1], mult(s[i], binpow(B1, i)));
        pref[1][i] = add(pref[1][i - 1], mult(s[i], binpow(B2, i)));
    }
    suff[0][n + 1] = suff[1][n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        suff[0][i] = add(suff[0][i + 1], mult(s[i], binpow(B1, n - i )));
        suff[1][i] = add(suff[1][i + 1], mult(s[i], binpow(B2, n - i )));
    }
}

pair<int, int> getHashpref(int l, int r) {
    pair<int, int> ret;
    ret.F = add(pref[0][r], -pref[0][l - 1]);
    ret.F = divide(ret.F, binpow(B1, l));

    ret.S = add(pref[1][r], -pref[1][l - 1]);
    ret.S = divide(ret.S, binpow(B2, l));
    return ret;
}

pair<int, int> getHashsuff(int l, int r) {
    pair<int, int> ret;

    int puiss = n - r + 1;
    ret.F = add(suff[0][l], -suff[0][r + 1]);
    ret.F = divide(ret.F, binpow(B1, puiss));

    ret.S = add(suff[1][l], -suff[1][r + 1]);
    ret.S = divide(ret.S, binpow(B2, puiss));
    return ret;
}

bool is_palindrome(int l, int r) {
    pair<int, int> pr = getHashpref(l, r);
    pair<int, int> suf = getHashsuff(l, r);
    return pr == suf;
}

void Solve() {
    string s;
    cin >> s;
    n = s.size();
    s = "#" + s;
    Hash(s);

    if (getHashpref(1, n) != getHashsuff(1, n)) {
        cout << "YES\n1\n";
        for (int i = 1; i <= n; i++) cout << s[i];
        cout << endl;
        return;
    }

    for (int i = 2; i < n; i++) {
        if (getHashpref(1, i) != getHashsuff(1, i) &&
            getHashpref(i + 1, n) != getHashsuff(i + 1, n)
                ) {
            cout << "YES\n2\n";
            for (int j = 1; j <= n; j++) {
                cout << s[j];
                if (j == i) cout << " ";
            }
            cout << endl;
            return;
        }

    }

    cout << "NO\n";
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