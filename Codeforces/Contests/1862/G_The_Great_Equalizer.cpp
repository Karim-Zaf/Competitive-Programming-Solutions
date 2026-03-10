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
    // the observation is that the output will be max_elemnt of the array + max difference when a is sorted

    int n;
    cin >> n;
    vector<int> v(n);
    multiset<int> s, diff;
    for (auto &x: v) {
        cin >> x;
        s.insert(x);
    }

    vector<int> nw = v;
    sort(all(nw));
    for (int i = 1; i < n; i++)diff.insert(nw[i] - nw[i - 1]);

    diff.insert(0);

    int q;
    cin >> q;
    while (q--) {
        int x, i, one = -1, two = -1;
        cin >> i >> x;
        i--;


        int old_value = v[i];
        s.erase(s.find(old_value));
        auto it = s.lower_bound(old_value);


        if (it != s.end()) {
            one = *it;
            diff.erase(diff.find(one - old_value));
        }
        if (it != s.begin()) {
            two = *prev(it);
            diff.erase(diff.find(old_value - two));
        }

        if (one != -1 && two != -1) diff.insert(one - two);

        it = s.lower_bound(x);

        one = two = -1;
        if (it != s.end()) {
            one = *it;
            diff.insert(one - x);
        }
        if (it != s.begin()) {
            two = *prev(it);
            diff.insert(x - two);
        }

        if (one != -1 && two != -1) diff.erase(diff.find(one - two));

        v[i] = x;
        s.insert(v[i]);

        cout << *prev(s.end()) + *prev(diff.end()) << " ";
    }
    cout << endl;

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