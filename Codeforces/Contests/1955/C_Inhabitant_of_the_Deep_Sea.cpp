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

void Solve() {
//    int one , two , three , four ;
//    cin >> one>> two >> three >> four ;
//
//    string s ="" ;
//    s+= char (one%2+'0');
//    s+= char (two%2+'0');
//    s+= char (three%2+'0');
//    s+= char (four%2+'0');
//    if (s=="000"){
//
//    }

    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for (auto &x: v) cin >> x;
    int isar = (m + 1) / 2;
    int imin = m / 2;

    int l = 0, r = n - 1;
    while (l < n && isar) {
        int mn = min(v[l], isar);
        isar -= mn;
        v[l] -= mn;
        if (v[l]==0)
        l++;
    }
    while (r >= 0 && imin) {
        int mn = min(v[r], imin);
        imin -= mn;
        v[r] -= mn;
        if (v[r]==0)
            r--;
    }
    cout << max(0ll, n - max(0ll, (r - l + 1))) << endl;
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