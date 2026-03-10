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
    int n, k;
    string s;
    cin >> n >> k >> s;


    int nb = count(all(s), '1');
    if (nb % k) return void(cout << "NO\n");
    nb /= k;


    int cnt = 0;

    reverse(all(s));
    string ss = "";
    string act = "";
    cnt = 0;
    for (int i = 0; i < n; i++) {
        act += s[i];
        if (s[i] == '1') {
            cnt++;
            if (cnt == nb) {
                if (ss.empty()) {
                    ss = act;
                    cnt = 0;
                    act = "";
                    continue;
                }
                reverse(all(act));
                while (act.size() > ss.size()) act.pop_back();
                reverse(all(act));

                if (act != ss)return void(cout << "NO\n");
                cnt = 0;
                act = "";
            }
        }
    }


    cout << "YES\n";
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    freopen("abdouz.in", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}