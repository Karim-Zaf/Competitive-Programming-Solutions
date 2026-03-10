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

const int B1 = 9947, B2 = 1e9 + 3;
int pref[2][N], suff[2][N], n;


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


void Hash(string &s) {
    for (int i = 1; i <= n; i++) {
        pref[0][i] = add(pref[0][i - 1], mult(s[i], binpow(B1, i)));
        pref[1][i] = add(pref[1][i - 1], mult(s[i], binpow(B2, i)));
    }
    suff[0][n + 1] = suff[1][n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        suff[0][i] = add(suff[0][i + 1], mult(s[i], binpow(B1, n - i)));
        suff[1][i] = add(suff[1][i + 1], mult(s[i], binpow(B2, n - i)));
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
    int ans = 0;
    string s;
    cin >> s;
    n = s.size();
    s = "#" + s;

    Hash(s);

    vector<int> v;

    for (int i = 1; i <= n; i++)
        if (s[i] != 'a') v.pb(i);

    if (v.empty()) return void(cout << n - 1 << endl);


    for (int i = 1; i <= n; i++) {
        int mn_inter = v[0];

        int pos = v[0], ok = 1, prv = 1;
        if (pos + i - 1 > n) continue;
        pair<int, int> h = getHashpref(pos, pos + i - 1);

        while (pos <= n) {
            int l = pos;
            if (l + i - 1 > n || getHashpref(l, l + i - 1) != h)ok = 0;
            mn_inter = min(mn_inter, pos - prv + 1);
            prv = pos + i;
            pos = upper_bound(all(v), l + i - 1) - v.begin();

            if (pos == v.size()) break;
            pos = v[pos];
        }
        ans += ok * mn_inter;
    }
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