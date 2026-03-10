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

const int N = 2e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int n, q;
int a[N], x[N], y[N], id[N], val[N], ans[N];
int freq[N];
int l, r, k, cnt = 0;

vector<int> spf(N);
vector<pair<int, int>> primes[N], primesval[N];

void sieve() {
    for (int i = 1; i < N; i++) spf[i] = i;
    for (int i = 2; i < N; i++) {
        if (spf[i] != i) continue;
        for (int j = i; j < N; j += i)
            spf[j] = i;
    }
}

vector<pair<int, int>> factors(int n) {
    vector<pair<int, int>> res;
    map<int, int> mp;
    while (n > 1) {
        mp[spf[n]]++;
        n /= spf[n];
    }
    for (auto val: mp) res.push_back(val);
    return res;
}

void add(int x) {

    for (auto [prime , occ]: primes[x]) freq[prime]+= occ ;
}

void rmv(int x) {
    for (auto [prime , occ]: primes[x]) freq[prime]-= occ ;
}

void update(int id) {
    while (r < y[id]) add(++r);
    while (l > x[id]) add(--l);
    while (r > y[id]) rmv(r--);
    while (l < x[id]) rmv(l++);
}

void mo() {
    int B = sqrt(n);
    sort(id, id + q, [&](ll a, ll b) {
        return make_pair(x[a] / B, y[a]) < make_pair(x[b] / B, y[b]);
    });
    cnt = 0, l = 0, r = -1;
    for (int i = 0; i < q; i++) {
        int currid = id[i];
        update(currid);

        int currans = 1;
        for (auto [prime, occ]: primesval[currid]) {
            if (freq[prime] < occ) currans= 0 ;
        }
        ans[currid] = currans;
    }
}

void Solve() {
    cin >> n ;
    sieve();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        primes[i] = factors(a[i]);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i] >> val[i];
        id[i] = i;
        primesval[i] = factors(val[i]);
        kar (primesval[i]);
    }
    mo();
    for (int i = 0; i < q; i++) cout << (ans[i]? "Yes" : "No")  << endl;
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