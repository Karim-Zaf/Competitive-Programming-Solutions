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
#pragma gcc optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

const int N = 1e7 + 3, mod = 1e9 + 7, INF = 1e18 + 10;

int sv[N];

ll lcm(int a, int b) {
    ll ret = a;
    ret *= b;
    ret /= __gcd(a, b);
    return ret;
}

void Solve() {
    int n, ansa = 1, ansb = 2;
    ll lc = 1e18;
    cin >> n;
    vector<int> v(n + 1), ans;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (!sv[v[i]])sv[v[i]] = i;
        else if (v[i] < lc) {
            ansa = sv[v[i]], ansb = i;
            lc = v[i];
        }
    }

    for (int i = N - 1; i >= 1; i--) {
        vector<int> p;
        for (int j = i; j < N; j += i) {
            if (sv[j])p.pb(sv[j]);
            if (p.size() == 2) break;
        }
        if (p.size() >= 2 && lcm(v[p[0]], v[p[1]]) < lcm(v[ansa], v[ansb])) {
            ansa = p[0], ansb = p[1];
        }
    }
    assert(ansa != -1);
    if (ansa > ansb)swap(ansa, ansb);
    cout << ansa << " " << ansb << endl;
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