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

void Solve() {
    map<pair<char, char>, char> mp;
    mp[{'A', 'A'}] = 'A';
    mp[{'B', 'B'}] = 'A';
    mp[{'A', 'B'}] = 'A';
    mp[{'C', 'C'}] = 'B';
    mp[{'A', 'C'}] = 'B';
    mp[{'B', 'C'}] = 'B';

    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < (n + 1) / 2; i++) {
        int j = n - i - 1;
        pair<char, char> p = {s[i], s[j]};
        if (s[i] > s[j])swap(p.F, p.S);
        kar (p);
        char c = mp[p];
        s[i] = s[j] = c;
    }
    cout << s << endl;
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
