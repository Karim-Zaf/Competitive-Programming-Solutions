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
    int cost = 0, pref = 0;
    string s;
    cin >> s;
    int n = s.size();
    string oth = s;

    vector<int> l(n + 1), r(n + 1);

    if (n % 2) return void(cout << -1 << endl);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    set<int> seti;

    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            cin >> l[i] >> r[i];
            s[i] = ')';
            cost += r[i];
            pq.push({-r[i] + l[i], i});
        }
        pref += (s[i] == '(');
        pref -= (s[i] == ')');

        if (pref < 0 && seti.find(pref) == seti.end()) {
            if (pq.empty())return void(cout << "-1\n");
            auto [c, p] = pq.top();
            pq.pop();
            cost += c;
            pref += 2;
            s[p] = '(';
        }
        seti.insert(pref);
    }

    pref = 0;
    for (int i = 0; i < n; i++) {
        pref += (s[i] == '(');
        pref -= (s[i] == ')');
        if (pref < 0) return void(cout << "-1\n");
    }

    if (pref != 0)return void(cout << "-1\n");

    cout << cost << endl << s << endl;
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