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

    int n, q;
    cin >> n >> q;

    vector<string> v(n + 1);
    map<string, set<int>> mp;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) mp[v[i]].insert(i);

    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = INF;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                if (v[x][i] == v[y][j]) {
                    ans = min(ans, abs(x - y));
                }
            }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                string curr = "";
                curr += v[x][i];
                curr += v[y][j];
                if (curr[0] > curr[1]) swap(curr[0], curr[1]);


                vector<int> act;
                auto it = mp[curr].lower_bound(x);
                if (it != mp[curr].end()) act.pb(*it);
                if (it != mp[curr].begin()) act.pb(*prev(it));


                it = mp[curr].lower_bound(y);
                if (it != mp[curr].end()) act.pb(*it);
                if (it != mp[curr].begin()) act.pb(*prev(it));

                int curr_ans = INF;
                for (auto pos : act) {
                    curr_ans = min(curr_ans, abs(x - pos) + abs(pos - y));
                }


                ans = min(ans, curr_ans);
            }

        cout << (ans == INF ? -1 : ans) << endl;
    }


}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
