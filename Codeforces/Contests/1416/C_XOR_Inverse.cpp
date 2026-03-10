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
#define all(x) x.begin(),x.end()
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {
    ll inversions = 0;
    int n, x = 0;

    cin >> n;

    vector<int> v(n);
    vector<vector<int>> a(1);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        a[0].pb(i);
    }


    for (int bit = 30; bit >= 0; bit--) {

        ll one = 0, two = 0;
        vector<vector<int>> nw_a;

        for (auto &vect: a) {
            
            vector<int> v_one, v_two, cnt(2);
            cnt[1] = cnt[0] = 0ll;

            for (auto pos: vect) {
                if (v[pos] >> bit & 1) {
                    cnt[1]++;
                } else cnt[0]++;
            }

            for (auto pos: vect) {
                if (v[pos] >> bit & 1) {
                    cnt[1]--;
                    v_one.pb(pos);
                    one += (cnt[0]);
                } else {
                    cnt[0]--;
                    v_two.pb(pos);
                    two += (cnt[1]);
                }
            }

            if (!v_one.empty())nw_a.pb(v_one);
            if (!v_two.empty())nw_a.pb(v_two);
        }

        if (one <= two) {
            inversions += one;
        } else {
            inversions += two;
            x += (1 << bit);
        }

        a = nw_a;
    }

    cout << inversions << " " << x << endl;

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