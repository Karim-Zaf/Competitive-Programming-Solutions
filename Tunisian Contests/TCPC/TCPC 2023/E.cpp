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

int binpow(int a, int k, int res = 1, int Mod = mod) {
    while (k) {
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}


int mult(int a, int b, int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }


int work(string &s) {
    int ret = 1;
    for (int i = 0; i < (s.size() + 1) / 2; i++) {
        int j = s.size() - i - 1;
        if (s[i] == '?' && s[j] == '?') ret = mult(ret, 26);
        if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) ret = 0;
    }
    return ret;
}

void Solve() {
    int n;
    string s, s1 = "";
    cin >> n >> s;
    int ans1 = work(s);

    if (n <= 2) {
        cout << ans1 << endl;
        return;
    }

    for (int i = 2; i < n; i++) s1 += s[i];
    int ans2 = work(s1);

    if (s[0] == '?' && s[1] == '?')ans2 = mult(ans2, 26);
    if (s[0] != '?' && s[1] != '?' && s[0] != s[1]) ans2 = 0;
    int ans = add(ans1, ans2);

    set<char> ss;

    for (auto c: s) ss.insert(c);

    int ans3 = 0;
    if (ss.size() == 1 && s[0] == '?')ans3 = 26;
    else if (ss.size() == 1)ans3 = 1;
    else if (ss.size() == 2 && *ss.begin() == '?')ans3 = 1;

    ans = add(ans, -ans3);

    cout << ans << endl;
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
