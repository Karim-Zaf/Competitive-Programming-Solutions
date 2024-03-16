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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

string s, a, b;
int n;

bool work(int x) {
    if (2 * x > n)return false;
    a = "", b = "";
    for (int i = 0; i < 2 * x; i++) {
        if (i < x)a += s[i];
        else b += s[i];
    }
    string ap = a, bp = b;
    while (bp.size() < n) {
        string curr = ap + bp;
        ap = bp;
        bp = curr;
    }
    if (bp == s) return true;
    swap(a, b);
    ap = a, bp = b;
    while (bp.size() < n) {
        string curr = ap + bp;
        ap = bp;
        bp = curr;
    }
    return bp == s;
}

void Solve() {
    cin >> n >> s;
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i)continue;
        divisors.pb(i);
        divisors.pb(n / i);
    }
    sort(all(divisors));
    for (auto d: divisors) {
        if (work(d)) {
            cout << d << endl << a << endl << b << endl;
            return;
        }
    }
    cout << -1 << endl;
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
