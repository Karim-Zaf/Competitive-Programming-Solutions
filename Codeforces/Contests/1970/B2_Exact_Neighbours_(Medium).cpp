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

    vector<int> v(n + 1);
    vector<pair<int, int>> vp;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (i != 1)vp.pb({v[i], i});
    }


    sort(rall(vp));

    vector<int> ans(n + 1);
    vector<pair<int, int>> pos(n + 1);

    ans[1] = 1;
    pos[1] = {1, 1};

    int prv = 1, cnt = 1;

    kar (vp);
    for (auto [val, wiz]: vp) {


        if (val == 0) {
            ans[wiz] = wiz;
            pos[wiz] = {++cnt,1};
            prv = wiz;
            continue;
        }

        if (val == 1) {
            ans[wiz] = prv;
            pos[wiz] = {++cnt,pos[prv].S};
            prv = wiz;
            continue;
        }

        int pot1 = pos[prv].S + val - 1;
        int pot2 = pos[prv].S - val + 1;

        if (pot1 >= 1 && pot1 <= n) {
            pos[wiz] = {++cnt,pot1};
        } else if (pot2 >= 1 && pot2 <= n) {
            pos[wiz] = {++cnt,pot2};
        } else {
            cout << "NO\n";
            return;
        }
        ans[wiz] = prv;
        prv = wiz;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << pos[i].F << " " << pos[i].S << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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