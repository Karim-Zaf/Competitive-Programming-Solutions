/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

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
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

void Solve() {
    int n;
    string s;
    cin >> n >> s;
    s = "#" + s;

    indexed_set imin, isar;
    vector<int> pref(n + 5), suff(n + 5);

    for (int i = 1; i <= n; i++) {
        pref[i] = (s[i] == '>') * i;
        suff[i] = (s[i] == '<') * i;
    }

    for (int i = 1; i <= n; i++)pref[i] += pref[i - 1];
    for (int i = n; i >= 0; i--)suff[i] += suff[i + 1];

    for (int i = 1; i <= n; i++) {
        if (s[i] == '<')
            isar.insert(i);
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == '<') isar.erase(i);

        int sz = min(imin.size(), isar.size());
        int ans = 0;

        int l = -1, r = -1;


        if (sz <= imin.size() && sz) l = -*imin.find_by_order(sz - 1);
        if (sz <= isar.size() && sz)r = *isar.find_by_order(sz - 1);


        if (l != -1)ans -= 2 * (pref[i - 1] - pref[l - 1]);
        if (r != -1)ans += 2 * (suff[i + 1] - suff[r + 1]);


        if (s[i] == '>' && imin.size() == isar.size()) {
            ans += abs(n - i + 1);
        } else if (s[i] == '<' && imin.size() == isar.size()) {
            ans += abs(i);
        } else if (s[i] == '>' && imin.size() > isar.size()) {
            ans += abs(n - i + 1);
        } else if (s[i] == '>') {
            ans += 2 * *isar.find_by_order(sz) - 2 * i;
            ans += i;
        } else if (s[i] == '<' && imin.size() < isar.size()) {
            ans += i;
        } else {
            ans += 2 * i - 2 * -*imin.find_by_order(sz);
            ans += abs(n + 1 - i);
        }


        if (s[i] == '>')imin.insert(-i);

        cout << ans << " ";
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