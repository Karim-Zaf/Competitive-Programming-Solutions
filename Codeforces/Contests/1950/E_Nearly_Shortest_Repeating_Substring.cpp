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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> div;
    for (int i = 1; i <= n; i++) {
        if ( n%i) continue;
        div.pb(i);
    }
    for (auto d: div) {
        string curr = "";
        for (int j = 0; j < d; j++) curr += s[j];
        int cnt = 0, indx = 0;
        for (int j = 0; j < n; j++) {
            cnt += (s[j] != curr[indx]);

            indx++;
            indx %= d;
        }
        if (cnt<=1) {
            cout << d << endl;
            return ;
        }


        if (d+d>n) continue;
        curr = "";
        for (int j = d; j < d+d; j++) curr += s[j];
        cnt = 0, indx = 0;
        for (int j = 0; j < n; j++) {
            cnt += (s[j] != curr[indx]);

            indx++;
            indx %= d;
        }
        if (cnt<=1) {
            cout << d << endl;
            return ;
        }

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