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
#pragma gcc optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e9 + 10;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

uint64_t random_address() {
    char* p = new char;
    delete p;
    return uint64_t(p);
}

struct safe_hash {
    static unsigned hash32(unsigned x) {
        // https://groups.google.com/g/prng/c/VFjdFmbMgZI
        x += 0x9e3779b9;
        x = (x ^ (x >> 16)) * 0x85ebca6b;
        x = (x ^ (x >> 13)) * 0xc2b2ae35;
        return x ^ (x >> 16);
    }

    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template <typename T> uint64_t operator()(T x) const {
        static const uint64_t FIXED_RANDOM = splitmix64(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
        return sizeof(x) <= 4 ? hash32(unsigned(x ^ FIXED_RANDOM)) : splitmix64(x ^ FIXED_RANDOM);
    }
};

void Solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n + 1), pref(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];

    int dp[n + 2][n + 2];

    gp_hash_table<int, array<pair<int, int>, 2>, safe_hash> mp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            dp[j][i] = max(0, i - j);
        }


    for (int r = 1; r <= n; r++) {

        for (int l = r; l >= 1; l--) {
            if (l == r - 1 && v[l] != v[r]) dp[l][r] = 1;
            int sum = pref[r] + pref[l - 1];

            int l1 = l, r2 = r;

            if (mp.find(sum) != mp.end()) {
                if (true) {
                    auto [r1,l2] = mp[sum][0];
                    dp[l1][r2] = min(dp[l1][r2], r1 - l1 + r2 - l2 + dp[r1 + 1][l2 - 1]);
                }
                auto [l2,r1] = mp[sum][1];
                dp[l1][r2] = min(dp[l1][r2], r1 - l1 + r2 - l2 + dp[r1 + 1][l2 - 1]);
            }
            ans += dp[l][r];

        }
        for (int l = r; l >= 1; l--) {
            int sum = pref[r] + pref[l];
            if (!mp[sum][0].F) mp[sum][0] = {l, r + 1};
            mp[sum][1] = {r + 1, l};
        }
    }

    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
