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
#define endl '\n'

const int N = 2e7 + 30, mod = 1e9 + 7;


int Trie[N][2], mp[N][2], cnt = 1;


void Solve() {

    int n, k;
    ll ans = 0;
    cin >> n >> k;

    vector<int> v(n + 1), pref(n + 1);


    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = pref[i - 1] ^ v[i];
    }

    for (int i = 0; i <= n; i++) {
        int suff = 0, id = 1, id2 = 1;

        for (int j = 30; j >= 0; j--) {
            // I want to match the suffix of k and when it's 0 calc the subarrays having 1

            if ((1ll << j) & k) {
                if ((1 << j) & pref[i]);
                else suff += (1 << j);
            } else {
                // try to calc
                if ((1 << j) & pref[i]) {
                    ans += mp[id][0];
                    suff += (1 << j);
                } else ans += mp[id][1];
            }

            int ind = 0;
            if ((1 << j) & suff) ind = 1;

            if (j == 0) ans += mp[id][ind];

            id = Trie[id][ind];

            int ind2 = 0;
            if ((1 << j) & pref[i]) ind2 = 1;

            if (Trie[id2][ind2] == 0) Trie[id2][ind2] = ++cnt;

            mp[id2][ind2]++;
            id2 = Trie[id2][ind2];
        }
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