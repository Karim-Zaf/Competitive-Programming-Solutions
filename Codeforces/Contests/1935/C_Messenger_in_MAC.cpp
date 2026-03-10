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
    int n, l, ans = 0, all_sum;
    cin >> n >> l;
    vector<pair<int, int>> vp(n);

    map<int, multiset<int>> mp;

    for (int i = 0; i < n; i++) {
        cin >> vp[i].S >> vp[i].F;
        mp[vp[i].F].insert(vp[i].S);
    }

    vector<int> b;

    for (auto x: mp) b.pb(x.F);
    sort(rall(b));

    for (int i = 0; i < b.size(); i++) {
        int one = *mp[b[i]].begin();
        if (one <= l) ans = max(ans, 1ll);

        mp[b[i]].erase(mp[b[i]].find(one));

        priority_queue<int> pq;
        all_sum = 0;

        for (int j = i; j < b.size(); j++) {
            if (mp[b[j]].empty())continue;

            int sum = b[i] - b[j] + one ;
            int reste = l - sum;

            for (auto x: mp[b[j]]){
                pq.push(x);
                all_sum += x;
            }

            while (!pq.empty() && all_sum > reste) {
                int rass = pq.top();
                pq.pop();
                all_sum -= rass;
            }

            if (sum <= l) ans = max(ans, 1ll + (int) pq.size());

        }
    }

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