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

vector<int> graph[N], depth(N);

void Solve() {
    int a, b, c, node = 1;
    cin >> a >> b >> c;
    array<int, 3> mp={0,0,0};
    mp[0] = 1;
    queue<int> q;
    q.push(1);
    int cnt = 0;
    while (cnt < a && !q.empty()) {
        int parent = q.front();
        q.pop();
        mp[0]--;
        mp[2]++;
        int one = ++node, two = ++node;

        graph[parent].pb(one);
        graph[parent].pb(two);

        depth[one] = depth[parent] + 1;
        depth[two] = depth[parent] + 1;

        q.push(one);
        q.push(two);

        mp[0] += 2;

        cnt++;
    }

    cnt = 0;

    while (cnt < b && !q.empty()) {
        int parent = q.front();
        q.pop();
        mp[0]--;
        mp[1]++;
        int one = ++node;

        graph[parent].pb(one);

        depth[one] = depth[parent] + 1;

        q.push(one);

        mp[0]++;

        cnt++;
    }
    int mn = 0;
    swap(mp[0],mp[2]);
    kar (mp[0], mp[1],mp[2]);
    for (int i = 1; i <= node; i++)mn = max(mn, depth[i]);

    if (mp[0]==a && mp[1]==b && mp[2]== c) {
        cout << mn << endl;
    } else cout << -1 << endl;

    for (int i = 1; i <= node; i++) {
        graph[i].clear();
        depth[i] = 0;
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