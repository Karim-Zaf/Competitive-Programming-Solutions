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
    int n, ans = 0;
    string s;
    cin >> n >> s;
    int cntr = count(all(s), '?');
    int cntl = 0;


    map<char, int> mp;
    mp['c'] = count(all(s), 'c');
    mp['?'] = count(all(s), '?');

    for (auto &x: s) {
        cntr -= (x == '?');
        mp['c'] -= (x == 'c');
        if (x == 'b' || x == '?') {
            int pairs_of_quest = mult(cntl, cntr);
            pairs_of_quest = mult(pairs_of_quest, binpow(3, cntl + cntr - 2));
            int a_c = mult(mult(mp['a'], mp['c']), binpow(3, cntl + cntr));

            int a_quest = mult(mp['a'], mult(cntr, binpow(3, cntr + cntl - 1)));
            int c_quest = mult(mp['c'], mult(cntl, binpow(3, cntr + cntl - 1)));

            if (cntl + cntr - 2 < 0)pairs_of_quest = 0;
            if (cntr + cntl - 1 < 0)a_quest = 0;
            if (cntr + cntl - 1 < 0)c_quest = 0;
            ans = add(ans, add(pairs_of_quest, add(a_c, add(a_quest, c_quest))));
            kar (ans);
        }
        cntl += (x == '?');
        mp['a'] += (x == 'a');
    }

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