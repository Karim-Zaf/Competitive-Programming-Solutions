/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "debug.cpp"
// #else
// #define kar(...)
// #endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> s;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;

            if (c == '1') s.insert({i, j});
        }


    int ans = 0;

    while (!s.empty()) {
        int x = -1, y = -1;
        ans++;
        set<pair<int, int>> er;
        auto it = s.begin();
        while (it != s.end()) {
            if (it->S >= y)er.insert(*it);
            x = it->F;
            y = max(y, it->S);
            auto prv_it = *it;

            it = s.lower_bound({x, y});

            if (it != s.end() && prv_it == *it) it++;
        }
        for (auto x: er) s.erase(x);
//        for (auto x: er) cout << x.F << " " << x.S << endl;
//        cout << endl;

    }

    cout << ans << endl;
}

int32_t main() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
//    #endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
