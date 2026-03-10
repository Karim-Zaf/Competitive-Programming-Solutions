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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<long long> dv[N];

vector<long long> primes(N);

void sieve2() {
    vector<int> visited(N);
    for (int i = 2; i < N; i++) {
        if (visited[i]) continue;
        primes[i] = 1;
        for (int j = i; j < N; j += i) visited[j] = 1;
    }
}

void sieve() {

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) dv[j].pb(i);
    }
}

vector<int> dp(N);

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));


    int prime = -1;
    int cnt = 0;
    for (auto x : v) cnt += primes[x];
    for (auto x : v) if (primes[x]) prime = x;
    kar(cnt);
    if (cnt >= 2) return void(cout << -1 << endl);
    if (cnt == 0) return void(cout << 2 << endl);


    for (auto x : v) {
        if (x == prime) continue;
        if (x == 2 * prime) continue;
        if (x < 2 * prime) return void(cout << "-1\n");
        if (x % 2 == 0) continue;
        int ok = 0;
        for (auto d : dv[x]) {
            if (x - d >= 2 * prime) ok = 1;
        }
        if (!ok) return void(cout << -1 << endl);
    }
    cout << prime << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    sieve();
    sieve2();
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
