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

int ask(int i, int j) {
    int ret;
    cout << "? " << i << " " << j << endl;
    cout.flush();
    cin >> ret;
    return ret;
}

void ans(int i, int j) {
    cout << "! " << i << " " << j << endl;
    cout.flush();
}

void Solve() {
    int n, m;
    cin >> n >> m;
    int one = ask(1, 1), two = ask(n, m), three = ask(n, 1);
    pair<int, int> p1, p2;
    p1.S = one + three - n + 1;

    if (p1.S % 2)p1 = {INF, INF};
    else {
        p1.S /= 2;
        p1.F = one - p1.S;
    }


    if (p1.F > n || p1.F < 0 || p1.S > m || p1.S < 0)p1 = {INF, INF};
    if (p2.F > n || p2.F < 0 || p2.S > m || p2.S < 0)p2 = {INF, INF};

    p2.F = m + 2 * n - 3 - two - three;
    if (p2.S % 2)p2 = {INF, INF};
    else {
        p2.F /= 2;
        p2.S = three + p2.F - n + 1;
    }

    p1.F++, p2.F++, p1.S++, p2.S++;
    if (p2.F >= INF) {
        ans(p1.F, p1.S);
    }
    if (p1.F >= INF) {
        ans(p2.F, p2.S);
    } else {
        int four = ask(p1.F, p1.S);
        if (!four) ans(p1.F, p1.S);
        else ans(p2.F, p2.S);
    }
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