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
#define int ll

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;


const int LG = 60;
vector<int> prep[LG];

ll binpow(ll a, int k, ll n, ll res = 1, int Mod = mod) {
    while (k) {
        if (k % 2) {
            // if (a > n / res) return 2e18;
            res = (res * a);
        }
        // if (a > n / a) return 2e18;
        a = (a * a);
        k /= 2;
    }
    if (res <= 0) return 2e18;
    return res;
}

ll work(ll n) {
    if (n == 0) return 0;
    ll ans = 0;

    vector<ll> sv(70);

    for (int b = LG; b >= 2; b--) {

        if (b == 2) sv[b] = sqrtl(n) - 1;
        else if (b == 3) sv[b] = cbrtl(n) - 1;
        else sv[b] = upper_bound(all(prep[b]), n) - prep[b].begin();

        for (int j = b + b; j <= LG; j += b) sv[b] -= sv[j];
        ans += sv[b];
    }


    return ++ans;
}


void Solve() {
    ll l, r;
    cin >> l >> r;
    cout << work(r) - work(l - 1) << endl;
}

void preprocess() {
    for (int i = 4; i < LG; i++) {
        for (int b = 2; ; b++) {
            int curr = binpow(b, i, INF);
            if (curr == 2 * INF) break ;
            prep[i].pb(curr);
        }
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    ll Test_case = 1;
    preprocess();
    cin >> Test_case;
    while (Test_case--) Solve();
}
