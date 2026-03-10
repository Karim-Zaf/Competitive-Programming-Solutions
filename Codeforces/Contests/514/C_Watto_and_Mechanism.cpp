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

const int N = 6e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;


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


const int B1 = 9947, B2 = 1e7 + 3;
int pref[2][N], suff[2][N];
int n;

void Hash(string &s) {
    for (int i = 1; i <= n; i++) {
        pref[0][i] = add(pref[0][i - 1], mult(s[i], binpow(B1, i)));
        pref[1][i] = add(pref[1][i - 1], mult(s[i], binpow(B2, i)));
    }
}

pair<int, int> getHashpref(int l, int r) {
    if (l > r) return {0, 0};
    pair<int, int> ret;
    ret.F = add(pref[0][r], -pref[0][l - 1]);
    ret.F = divide(ret.F, binpow(B1, l));

    ret.S = add(pref[1][r], -pref[1][l - 1]);
    ret.S = divide(ret.S, binpow(B2, l));
    return ret;
}

void Solve() {
    map<pair<int, int>, bool> mp;
    int m, q;
    cin >> m >> q;
    vector<string> s(m);
    for (auto &x: s) {
        cin >> x;
        n = x.size();
        x = '#' + x;

        Hash(x);


        for (int i = 1; i <= n; i++) {
            for (char c = 'a'; c <= 'c'; c++) {
                if (c==x[i])continue;
                pair<int, int> curr = getHashpref(1, i - 1);
                pair<int, int> curr2 = getHashpref(i + 1, n);
                curr.F = mult (curr.F,B1);
                curr.S = mult (curr.S,B2);
                curr.F = add(curr.F, mult(c, binpow(B1, i)));
                curr.S = add(curr.S, mult(c, binpow(B2, i)));
                curr.F = add(curr.F, mult(curr2.F, binpow(B1, i+1 )));
                curr.S = add(curr.S, mult(curr2.S, binpow(B2, i+1 )));
                curr.F = divide(curr.F,B1);
                curr.S = divide(curr.S,B2);
                mp[curr] = true;
            }
        }
    }


    while (q--) {
        string x;
        cin >> x;
        n = x.size();
        x = '#' + x;

        Hash(x);

        if (mp[getHashpref(1, n)])cout << "YES\n";
        else cout << "NO\n";
    }


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