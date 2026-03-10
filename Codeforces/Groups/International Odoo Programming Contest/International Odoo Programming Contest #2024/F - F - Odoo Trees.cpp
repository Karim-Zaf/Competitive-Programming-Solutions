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

vector<int> graph[N], a(N), ans(N, -1);
int timer = 0, start[N], endd[N];


vector<pair<int, int>> primes_k; // occurences corresponding to the ith prime
vector<int> spf(N), primes;


vector<int> factors(int n) {
    vector<int> res;
    set<int> temp;
    while (n > 1) {
        temp.insert(spf[n]);
        n /= spf[n];
    }
    for (int val: temp) res.push_back(val);
    return res;
}

void Euler_Tour(int curr, int parent) {
    start[curr] = ++timer;
    for (auto child: graph[curr])
        if (child != parent)
            Euler_Tour(child, curr);
    endd[curr] = timer;
}

void get_primes_k(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d)continue;
        int cnt = 0;
        while (x % d == 0) {
            cnt++;
            x /= d;
        }
        primes_k.pb({d, cnt});
    }
    if (x > 1) {
        primes_k.pb({x, 1});
    }
}

void Solve() {
    int n, k, q;
    cin >> n >> k >> q;
    get_primes_k(k);
    set<array<int, 3>> s[20];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2, u; i <= n; i++) {
        cin >> u;
        graph[i].pb(u);
        graph[u].pb(i);
    }
    Euler_Tour(1, 0);

    for (int i = 1; i <= n; i++) {
        int x = a[i], ehseb = 0;
        a[i] = 1;
        for (int j = 0; j < primes_k.size(); j++) {
            int cnt = 0;

            while (x % primes_k[j].F == 0) {
                cnt++;
                x /= primes_k[j].F;
            }

            int beki = max(0ll, primes_k[j].S - cnt);
            if (primes_k[j].S - cnt > 0) {
                s[j].insert({start[i], beki, i});
                ehseb++;
            }
            for (int z = 0; z < beki; z++)
                a[i] *= primes_k[j].F;
        }
        if (!ehseb) {
            ans[i] = 0;
        }
    }
//    for (int i= 1; i<=n ;i++) cout <<a[i]<< " " ; cout << endl;
    for (int t = 1; t <= q; t++) {
        int u, x;
        cin >> u >> x;
        vector<int> fact(11), indexes ;

        for (int j = 0; j < primes_k.size(); j++) {
            while (x % primes_k[j].F == 0) {
                fact[j]++;
                x /= primes_k[j].F;
            }
            if (fact[j])indexes.pb(j);
        }
        for (auto j : indexes) {
            array<int, 3> f = {start[u], -1, -1};
            auto it = s[j].lower_bound(f);

            set<array<int, 3>> er;

            while (it != s[j].end() && (*it)[0] <= endd[u]) {
                er.insert(*it);
                it++;
            }

            for (auto [id, val, node]: er) {
                s[j].erase({id, val, node});

                int nw_val = val - fact[j];

                for (int z = 0; z < min(val, fact[j]); z++) {
                    a[node] /= primes_k[j].F ;
                }
                if (nw_val > 0) {
                    s[j].insert({id, nw_val, node});
                }
                if (a[node] == 1) {
                    ans[node] = t;
                }
            }

        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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