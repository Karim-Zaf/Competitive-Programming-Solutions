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

const int N = 2e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> sz, parent;
map<int, int> mp[N];
int mx = 0, check[N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent.pb(i);
        sz.pb(1);
    }
}

int get(int a) { return (parent[a] == a ? a : parent[a] = get(parent[a])); }


int factors(int n) {

    int res = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i) continue;
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt % 2) res *= i;
    }
    if (n > 1)res *= n;
    return res;
}


int arith(int x) { return x * (x - 1) / 2; }

void merge(map<int, int> &a, map<int, int> &b, int indxa, int indxb) {
    if (a.size() < b.size()) a.swap(b);

    parent[indxb] = indxa;
    check[indxa] += check[indxb];

    for (auto [key, occ]: b) {
        check[indxa] -= arith(a[key]);
        check[indxa] -= arith(occ);
        a[key] += occ;
        check[indxa] += arith(a[key]);
    }
    mx = max(mx, check[indxa]);
}

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n + 5), order(n + 5), blocked(n + 5, 1), ans(n + 5);

    init(n + 4);

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> order[i];

    for (int i = n; i >= 1; i--) {
        int index = order[i];
        int curr = factors(v[index]);

        mp[index][curr]++;

        int imin = get(index + 1), isar = get(index - 1);

        if (!blocked[imin])
            merge(mp[index], mp[imin], index, imin);

        int nw_index = get(index);

        if (!blocked[isar])
            merge(mp[nw_index], mp[isar], nw_index, isar);


        blocked[index] = 0;
        ans[i] = mx;
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";cout << endl;
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