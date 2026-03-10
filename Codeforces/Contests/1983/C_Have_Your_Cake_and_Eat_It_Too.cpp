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
    vector<int> t[3], pref[3], suff[3];
    for (int i = 0; i < 3; i++) {
        t[i].resize(n + 4);
        for (int j = 1; j <= n; j++) cin >> t[i][j];
    }
    for (int i = 0; i < 3; i++) {
        pref[i].resize(n + 1);
        suff[i].resize(n + 1);
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i][j - 1] + t[i][j];
        }
        for (int j = n; j >= 1; j--) {
            suff[i][j] = suff[i][j + 1] + t[i][j];
        }
    }
    int tot = 0;

    for (int j = 1; j <= n; j++) tot += t[0][j];

    int req = (tot + 2) / 3;

    pair<int,int> lef[3], righ[3];
    for (int i = 0; i < 3; i++) righ[i] = lef[i] = {-1, -1};

    for (int i = 0; i < 3; i++) {

        for (int j = 1; j <= n; j++) {
            int p = pref[i][j] - req;
            int pos = upper_bound(all(pref[i]), p) - pref[i].begin() - 1;

            if (pos >= 0 && pos < j) {
                if (lef[i].F == -1) lef[i] = {pos + 1, j};

                if (pos + 1 >= righ[i].F) {
                    righ[i] = {pos + 1, j};
                }
            }
        }


    }
    

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            int p = pref[i][j] - req;
            int pos = upper_bound(all(pref[i]), p) - pref[i].begin() - 1;


            pair<int,int> ind;
            if (i == 0) ind = {1, 2};
            if (i == 1) ind = {0, 2};
            if (i == 2) ind = {0, 1};
            if (pos >= 0 && pos < j) {
                int l = pos + 1, r = j;

                array<pair<int,int>, 3> ans;
                if (lef[ind.F].F != -1 && righ[ind.S].F != -1 && lef[ind.F].S < l && righ[ind.S].F > r) {
                    ans[ind.F] = lef[ind.F];
                    ans[ind.S] = righ[ind.S];
                    ans[i] = {l, r};

                    for (int x = 0; x < 3; x++) {
                        cout << ans[x].F << " " << ans[x].S << " ";
                    }
                    cout << endl;
                    return;
                }
                swap(ind.F, ind.S);
                if (lef[ind.F].F != -1 && righ[ind.S].F != -1 && lef[ind.F].S < l && righ[ind.S].F > r) {
                    ans[ind.F] = lef[ind.F];
                    ans[ind.S] = righ[ind.S];
                    ans[i] = {l, r};

                    for (int x = 0; x < 3; x++) {
                        cout << ans[x].F << " " << ans[x].S << " ";
                    }
                    cout << endl;
                    return;
                }


            }
        }

    }

    cout << -1 << endl;

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
