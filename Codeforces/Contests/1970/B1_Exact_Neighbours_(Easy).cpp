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
    vector<int> v(n);
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vp[i] = {v[i], i + 1};
    }

    vector<int> ans(n + 1), pos(n + 1), ans_fin(n + 1);

    sort(rall(vp));

    for (int i = 0; i < n; i += 2) {
        auto [val, wiz] = vp[i];
        pos[i + 1] = wiz;
        ans[wiz] = i + 1;
    }


    for (int i = 1; i < n; i += 2) {
        auto [val, wiz] = vp[i];
        pos[n - i + (n % 2 == 0)] = wiz;
        ans[wiz] = n - i + (n % 2 == 0);
    }


    for (int wiz = 1; wiz <= n; wiz++) {
        int x = v[wiz - 1] / 2;
        int my_position = ans[wiz];

        int oth1 = my_position - x;
        int oth2 = my_position + x;


        if (oth1 >= 1 && oth1 <= n) {
            kar (oth1, oth2);
            kar (pos[oth1])
            ans_fin[wiz] = pos[oth1];
        } else if (oth2 >= 1 && oth2 <= n) {
            ans_fin[wiz] = pos[oth2];
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " " << ans[i] << endl;
    }

    for (int i = 1; i <= n; i++) cout << ans_fin[i] << " ";
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