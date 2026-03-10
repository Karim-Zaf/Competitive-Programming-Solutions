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

const int N = 3e5 + 30, mod = 998244353, INF = 1e18 + 10;

int mult(int a, int b, int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }


int dp[105][105][105];
vector<int> mp[105][3];
int n;

int work(int pos, int lst_one, int lst_zero) {
    if (pos > n) return 1;
    int &ret = dp[pos][lst_one][lst_zero];
    if (ret != -1) return ret;
    ret = 0;

    // bch nhot one
    int nw_lst_one = pos, nw_lst_zero = lst_zero;
    bool ok = true;
    for (auto &lef: mp[pos][2]) {
        if (nw_lst_one >= lef && nw_lst_zero >= lef);// jawi behi
        else ok = false;
    }
    for (auto &lef: mp[pos][1]) {
        if (nw_lst_one >= lef && nw_lst_zero >= lef) ok = false; // jawi mch behi
    }
    if (ok) ret = add(ret, work(pos + 1, nw_lst_one, nw_lst_zero));

    // bch nhot zero
    nw_lst_one = lst_one, nw_lst_zero = pos;
    ok = true;

    for (auto &lef: mp[pos][2]) {
        if (nw_lst_one >= lef && nw_lst_zero >= lef);// jawi behi
        else ok = false;
    }
    for (auto &lef: mp[pos][1]) {
        if (nw_lst_one >= lef && nw_lst_zero >= lef) ok = false; // jawi mch behi
    }
    if (ok) ret = add(ret, work(pos + 1, nw_lst_one, nw_lst_zero));

    return ret;
}

void Solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int lef = 1; lef <= n; lef++) {
        for (int righ = lef, x; righ <= n; righ++) {
            cin >> x;
            mp[righ][x].pb(lef);
        }
    }
    cout << work(1, -1, -1);
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