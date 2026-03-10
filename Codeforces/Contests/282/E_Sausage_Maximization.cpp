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
#define aint(x) x.begin(),x.end()
#define raint(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 1e7 + 30, mod = 1e9 + 7;

bool bit(int x, int b) {
    return ((1ll << b) & x) != 0;
}

int Trie[N][2], nxt = 0;

void build(int x) {
    int curr = 0;
    for (int j = 40 - 1; j >= 0; j--) {
        int bit = (x >> j) & 1;
        if (!Trie[curr][bit]) Trie[curr][bit] = ++nxt;
        curr = Trie[curr][bit];
    }
}


void Solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ v[i];

    int ans = *max_element(aint(pref));


    unordered_map<int, int> mp[40];
    for (int i = 0; i <= n; i++) {

        int curr = 0, j = 40 - 1, req = 0;
        while (j >= 0) {
            int want = 0;

            if (bit(pref[n], j) == bit(pref[i], j)) want = 1;

            if (Trie[curr][want]) {
                curr = Trie[curr][want];
            } else if (Trie[curr][want ^ 1]) {
                curr = Trie[curr][want ^ 1];
                want ^= 1;
            } else break ;

            req += want * (1ll << j);

            j--;
        }

        if (j == -1) ans = max(ans, pref[n] ^ pref[i] ^ req);

        build(pref[i]);
    }
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
