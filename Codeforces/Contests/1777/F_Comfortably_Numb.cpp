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

const int N = 1e7 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

const int LG = 30;

int Trie[N][2], nxt = 0;
vector<int> stock[N];

auto bit = [](int x, int b) {
    return ((1 << b) & x) != 0;
};

void build(int x, int pos) {
    int curr = 0;
    for (int i = LG - 1; i >= 0; i--) {
        if (!Trie[curr][bit(x, i)]) Trie[curr][bit(x, i)] = ++nxt;
        stock[Trie[curr][bit(x, i)]].pb(pos);
        curr = Trie[curr][bit(x, i)];
    }
}

int work(int x, int l, int r) {
    if (l > r) return 0;
    int curr = 0, ret = 0;
    for (int i = LG - 1; i >= 0; i--) {
        int act = 1 ^ bit(x, i);

        if (!Trie[curr][act]) {
            ret += (act ^ 1) << i;
            curr = Trie[curr][act ^ 1];
            continue ;
        }

        auto& mp = stock[Trie[curr][act]];
        int pos = upper_bound(all(mp), r) - mp.begin();
        if (pos == 0) {
            ret += (act ^ 1) << i;
            curr = Trie[curr][act ^ 1];
            continue ;
        }
        pos--;
        if (mp[pos] < l) {
            ret += (act ^ 1) << i;
            curr = Trie[curr][act ^ 1];
            continue ;
        }
        ret += act << i;
        curr = Trie[curr][act];
    }
    return ret;
}

void Solve() {
    for (int i = 0; i <= nxt; i++) {
        stock[i].clear();
        Trie[i][0] = Trie[i][1] = 0;
    }
    nxt = 0;

    int n, ans = 0;
    cin >> n;
    vector<int> v(n + 1), pref(n + 1);
    vector<pair<int, int>> vp;

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ v[i];

    for (int i = 1; i <= n; i++) vp.pb({v[i], i});
    sort(rall(vp));

    for (int i = 0; i <= n; i++) build(pref[i], i);


    set<int> s{0, n + 1};

    for (auto [val , pos] : vp) {
        auto it = s.lower_bound(pos);

        int l = *prev(it), r = *it - 1;

        if (abs(pos - l) <= abs(pos - r)) {

            for (int i = l; i < pos; i++) {
                int pot = work(pref[i] ^ val, pos, r);
                ans = max(ans, pot ^ pref[i] ^ val);
            }
        } else {

            for (int i = pos; i <= r; i++) {
                int pot = work(pref[i] ^ val, l, pos - 1);
                ans = max(ans, pot ^ pref[i] ^ val);
            }
        }

        s.insert(pos);
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
