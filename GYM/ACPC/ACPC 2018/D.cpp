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


vector<int> multiples[N], divisors[N], mp(N), ans(N), prv(N);

void sieve() {
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divisors[j].pb(i);
}

void Solve() {
    int n, res = 0;
    cin >> n;
    vector<int> v(n), div, calc(n + 4);
    for (auto &x: v) cin >> x;
    for (auto &x: v) {
        for (auto d: divisors[x]) {
            mp[d] += x;
        }
    }

    int sum = accumulate(all(v), 0ll);
    sort(all(v));

    for (auto x: v) {
        sum -= x;
        int cnt = sum;

        vector<int> divisors_x = divisors[x];
        set<int, greater<>> parc;
        reverse(all(divisors_x));

        for (auto d: divisors[x]) mp[d] -= x;

        for (auto gcd: divisors_x)
            for (auto d: divisors[gcd])
                multiples[d].clear();

        for (auto gcd: divisors_x) {
            for (auto d: divisors[gcd]) {
                multiples[d].pb(gcd);
                parc.insert(d);
            }
        }

        vector<int> curr(all(parc));

        for (auto gcd: curr) {
            prv[gcd] += mp[gcd];
            for (auto m: multiples[gcd]) {
                if (m == gcd) continue;
                prv[gcd] -= prv[m];
            }
        }

        for (auto gcd: curr) {
            cnt -= prv[gcd];
            cnt += prv[gcd] / gcd;
        }
        res = add(res, mult(cnt, x));

        // clearing prv
        for (auto gcd: divisors_x) {
            for (auto d: multiples[gcd]) {
                prv[d] = 0;
            }
        }
    }


    cout << add(mult(2, res), accumulate(all(v), 0ll)) << endl;

}

int32_t main() {
    freopen("lcm.in", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    sieve();
    while (Test_case--) Solve();
}
