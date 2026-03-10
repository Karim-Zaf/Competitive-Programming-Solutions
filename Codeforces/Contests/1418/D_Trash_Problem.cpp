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

void Solve() {
    int n, q;
    cin >> n >> q;

    multiset<int> s, diff;
    vector<int> v(n);

    auto add = [&](int x) {
        auto it = s.lower_bound(x);
        if (it != s.end()) {
            diff.insert(*it - x);
            if (it != s.begin()) {
                diff.erase(diff.find(*it - *prev(it)));
            }
        }
        if (it != s.begin()) {
            diff.insert(x - *prev(it));
        }
        s.insert(x);
    };

    auto er = [&](int x) {
        s.erase(x);
        auto it = s.lower_bound(x);
        if (it != s.end()) {
            diff.erase(diff.find(*it - x));
            if (it != s.begin()) {
                diff.insert(*it - *prev(it));
            }
        }
        if (it != s.begin()) {
            diff.erase(diff.find(x - *prev(it)));
        }
    };

    auto query = [&] {
        int ans = 0;
        if (!s.empty()) ans = *prev(s.end()) - *s.begin();
        if (!diff.empty())ans -= *prev(diff.end());
        return ans;
    };

    for (auto &x: v) {
        cin >> x;
        s.insert(x);
    }
    sort(all(v));

    for (int i = 1; i < n; i++)diff.insert(v[i] - v[i - 1]);

    cout << query() << endl;

    while (q--) {
        int ind, x;
        cin >> ind >> x;
        if (ind == 1) add(x);
        else er(x);
        cout << query() << endl;
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