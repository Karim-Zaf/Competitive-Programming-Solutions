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
    int n, k, cnt = 1;
    cin >> n >> k;
    vector<int> grp(n + 1), value(n + 1);
    int lst = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> verif(n + 1);

        int md = lst + (i - lst) / 2;

        int curr = lst;
        for (int j = md; j >= lst; j--) verif[j] = curr++;
        for (int j = i; j >= md + 1; j--) verif[j] = curr++;

        bool ok = true;
        for (int u = lst; u <= i; u++)
            for (int v = lst; v <= i; v++)
                if (abs(u - v) + abs(verif[u] - verif[v]) > k) {
                    ok = false;

                }

        if (ok) {
            for (int j = lst; j <= i; j++)grp[j] = cnt;
            for (int j = lst; j <= i; j++)value[j] = verif[j];
        } else {
            cnt++;
            grp[i] = cnt;
            value[i] = i;
            lst = i;
        }
    }

    for (int i = 1; i <= n; i++)cout << value[i] << " ";
    cout << endl;
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)cout << grp[i] << " ";
    cout << endl;

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