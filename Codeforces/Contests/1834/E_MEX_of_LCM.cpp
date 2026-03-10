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

const int N = 1e7 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

using ul = uint64_t;
using db = long double;

ul modMul(ul a, ul b, const ul mod) {
    ll ret = a * b - mod * (ul) ((db) a * b / mod);
    return ret + ((ret < 0) - (ret >= (ll) mod)) * mod;
}

ul modPow(ul a, ul b, const ul mod) {
    if (b == 0) return 1;
    ul res = modPow(a, b / 2, mod);
    res = modMul(res, res, mod);
    return b & 1 ? modMul(res, a, mod) : res;
}

bool prime(ul n) { // not ll!
    if (n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
    ul A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n - 1), d = n >> s;
    for (auto a: A) {   // ^ count trailing zeroes
        ul p = modPow(a, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--) p = modMul(p, p, n);
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}

ul pollard(ul n) { // return some nontrivial factor of n
    auto f = [n](ul x) { return modMul(x, x, n) + 1; };
    ul x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) { /// speedup: don't take gcd every it
        if (x == y) x = ++i, y = f(x);
        if ((q = modMul(prd, max(x, y) - min(x, y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}

void factor_rec(ul n, map<ul, ll> &cnt) {
    if (n == 1) return;
    if (prime(n)) {
        ++cnt[n];
        return;
    }
    ul u = pollard(n);
    factor_rec(u, cnt), factor_rec(n / u, cnt);
}

vector<pair<int, int>> get(ul x) {

    vector<pair<int, int>> ret;

    map<ul, ll> mp;
    factor_rec(x, mp);
    for (auto x: mp)ret.pb({x.F, x.S});
    return ret;
}

vector<int> vs(N);
vector<pair<int, int>> st[N];

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);

    int n_mx = min(N, n * 150);
    set<array<int, 3>, greater<>> ind;

    for (int i = 0; i < n_mx; i++) {
        st[i].clear();
        vs[i] = 0;
    }

    auto lcm = [&](int a, int b) { return a / __gcd(a, b) * b; };

    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) {

        vector<pair<int, int>> vp = get(v[i]);


        for (auto [prime, puiss]: vp) {
            if (prime >= n_mx)break;

            while (!st[prime].empty() && st[prime].back().F <= puiss) {
                ind.erase({st[prime].back().S, prime, st[prime].back().F});
                st[prime].pop_back();
            }
            st[prime].pb({puiss,i});
            ind.insert({i, prime, puiss});
        }
        if (v[i] == 1)vs[1] = 1;

        int lc = v[i];
        for (auto j: ind) {
            lc = lcm(lc, v[j[0]]);
            if (lc <= 0 || lc >= n_mx) break;
            vs[lc] = 1;
        }
    }


    for (int i = 1; i < n_mx; i++)
        if (!vs[i]) {
            cout << i << endl;
            return;
        }

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