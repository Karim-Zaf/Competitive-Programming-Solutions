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


int grundy[N], mp[N];
vector<int> nakkes[N];

void Solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    int xr = 0;
    for (auto& x : v) cin >> x;
    for (auto& x : v) xr ^= grundy[x];
    cout << (xr ? "Alice" : "Bob") << endl;

}

void prep() {
    for (int i = 1; i < N; i++) grundy[i] = INF;
    int g = 1;
    grundy[1] = 1;
    for (int i = 3; i < N; i++) {
        if (i % 2 && grundy[i] == INF) {
            grundy[i] = ++g;
            for (int j = i; j < N; j += 2 * i) grundy[j] = min(grundy[i], grundy[j]);
        }
    }
    for (int i = 1; i < N; i++) if (grundy[i] == INF) grundy[i] = 0;
}

// grundy: [0 1 0 2 0 3 0 4 0 2 0 5 0 6 0 2 0 7 0 8 0 2 0 9 0 3 0 2 0 10 0 11 0 2 0 3 0 12 0 2 0 13 0 14 0 2 0 15 0 4 0 2 0 16 0 3 0 2 0 17 0 18 0 2 0 3 0 19 0 2 0 20 0 21 0 2 0 4 0 22 0 2 0 23 0 3 0 2 0 24 0 4 0 2 0 3 0 25 0 2 0 26 0 27 0 2 0 28 0 29 0 2 0 30 0 3 0 2 0 4 0 5 0 2 0 3 0 31 0 2 0 32 0 4 0 2 0 33 0 34 0 2 0 5 0 3 0 2 0 35 0 36 0 2 0 3 0 37 0 2 0 4 0 38 0 2 0 39 0 6 0 2 0 40 0 3 0 2 0 41 0 42 0 2 0 3 0 5 0 2 0 43 0 44 0 2 0 45 0 46 0 2 0 4 0 3 0 2 0 5 0 47 0 2 0 3 0 4 0 2 0 6 0 48 0 2 0 49 0 50 0 2 0 51 0 3 0 2 0 52 0 53 0 2 0 3 0 6 0 2 0 54 0 5 0 2 0 55 0 4 0 2 0 56 0 3 0 2 0 57 0 58 0 2 0 3 0 59 0 2 0 60 0 61 0 2 0 4 0 7 0 2 0 62 0 3 0 2 0 6 0 4 0 2 0 3 0 63 0 2 0 64 0 65 0 2 0 66 0 5 0 2 0 7 0 3 0 2 0 4 0 67 0 2 0 3 0 68 0 2 0 5 0 4 0 2 0 69 0 70 0 2 0 71 0 3 0 2 0 72 0 8 0 2 0 3 0 73 0 2 0 4 0 74 0 2 0 6 0 75 0 2 0 76 0 3 0 2 0 77 0 7 0 2 0 3 0 78 0 2 0 79 0 6 0 2 0 5 0 80 0 2 0 4 0 3 0 2 0 81 0 82 0 2 0 3 0 4 0 2 0 83 0 84 0 2 0 8 0 85 0 2 0 86 0 3 0 2 0 87 0 5 0 2 0 3 0 88 0 2 0 89 0 90 0 2 0 91 0 4 0 2 0 5 0 3 0 2 0 92 0 6 0 2 0 3 0 93 0 2 0 94 0 7 0 2 0 4 0 95 0 2 0 96 0 3 0 2 0 97 0 4 0 2 0 3 0 5 0 2 0 98 0 99 0 2 0 7 0 9 0 2 0 6 0 3 0 2 0 4 0 100 0 2 0 3 0 101 0 2 0 8 0 4 0 2 0 102 0 6 0 2 0 103 0 3 0 2 0 104 0 105 0 2 0 3 0 106 0 2 0 4 0 5 0 2 0 107 0 8 0 2 0 108 0 3 0 2 0 109 0 110 0 2 0 3 0 111 0 2 0 6 0 112 0 2 0 113 0 114 0 2 0 4 0 3 0 2 0 7 0 115 0 2 0 3 0 4 0 2 0 116 0 117 0 2 0 118 0 5 0 2 0 119 0 3 0 2 0 120 0 121 0 2 0 3 0 9 0 2 0 5 0 122 0 2 0 123 0 4 0 2 0 124 0 3 0 2 0 6 0 125 0 2 0 3 0 7 0 2 0 126 0 8 0 2 0 4 0 127 0 2 0 9 0 3 0 2 0 128 0 4 0 2 0 3 0 129 0 2]


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;

    prep();
    while (Test_case--) Solve();
}
