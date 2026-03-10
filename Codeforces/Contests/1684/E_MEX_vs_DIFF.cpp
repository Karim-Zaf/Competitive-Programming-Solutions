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
    int n, k, res = INF, sum = 0, curr = 0, cnt = 0;
    cin >> n >> k;
    vector<int> v(n), req(n + 2);
    map<int, int> mp, ans;

    for (auto &x: v) cin >> x;
    for (auto &x: v) mp[-x]++;
    sort(all(v));

    priority_queue<int> pq;
    for (auto [val, occ]: mp) {
        cnt++;
        sum += occ;
        curr += occ;
        pq.push(occ);
        while (curr > k) {
            int rass = pq.top();
            pq.pop();
            curr -= rass;
        }
        ans[val] = cnt - pq.size();
    }

    set<int> s;
    for (int i = n - 1; i >= 0; i--)req[i] = ans[-v[i]];


    for (int mex = 0, p = -1, dup = 0; mex <= n; mex++) {
        while (p + 1 < n && v[p + 1] < mex) {
            p++;
            if (s.find(v[p]) != s.end())dup++;
            s.insert(v[p]);
        }
        int inter = req[p + 1];


        int required = mex - (int) s.size();
        if (n - p - 1 >= required - dup && required <= k) {
            res = min(res, inter);
        }
    }

    cout << res << endl;
    assert (res != INF);
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