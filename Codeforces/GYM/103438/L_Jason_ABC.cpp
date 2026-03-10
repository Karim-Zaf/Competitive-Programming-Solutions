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
    // 1st observation : Max answer = 3  by making string :
    // AAAAAAAAAAAA then AAAABBBBBBBB then AAAABBBBCCCC

    int n;
    string s;
    cin >> n >> s;


    s = "#" + s;
    vector<int> mp[3], v(3 * n + 1), cnt(3);


    for (int i = 0; i < 3; i++) mp[i].resize(3 * n + 1);

    for (char c = 'A'; c <= 'C'; c++) {
        cnt[c - 'A'] = count(all(s), c);
    }

    if (cnt[0] == n && cnt[1] == n && cnt[2] == n) {
        cout << 0 << endl;
        return;
    }


    for (int i = 1; i <= 3 * n; i++) {
        mp[s[i] - 'A'][i]++;
        for (int j = 0; j < 3; j++) {
            mp[j][i] += mp[j][i - 1];
        }
    }



    // one operation ;
    for (int r = 1; r <= 3 * n; r++) {
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < a; b++) {
                if (cnt[a] < n || cnt[b] < n) continue;
                int third = 3 - a - b;

                int suff_a = mp[a][3 * n] - mp[a][r], suff_b = mp[b][3 * n] - mp[b][r];
                int one = lower_bound(all(mp[a]), n - suff_a) - mp[a].begin();
                int two = lower_bound(all(mp[b]), n - suff_b) - mp[b].begin();

                if (mp[a][one] == n - suff_a && mp[b][one] == n - suff_b) {
                    cout << 1 << endl;
                    cout << one + 1 << " " << r << " " << char('A' + third) << endl;
                    return;
                }

                if (mp[a][two] == n - suff_a && mp[b][two] == n - suff_b) {
                    cout << 1 << endl;
                    cout << two + 1 << " " << r << " " << char('A' + third) << endl;
                    return;
                }
            }
        }
    }


    // two operations
    for (int fixed = 0; fixed < 3; fixed++) {
        if (cnt[fixed] < n) continue;
        int l = 1, r, indx1, indx2;
        if (fixed == 0) indx1 = 1, indx2 = 2;
        if (fixed == 1) indx1 = 0, indx2 = 2;
        if (fixed == 2) indx1 = 0, indx2 = 1;

        int zeyed = cnt[fixed] - n;

        r = lower_bound(all(mp[fixed]), n) - mp[fixed].begin();
        if (mp[indx1][r] <= n && mp[indx2][r] <= n) {
            cout << 2 << endl;
            cout << r + 1 << " " << 3*n << " " << char('A' + indx1) << endl;
            cout << r + 1 << " " << r + (n - mp[indx2][r]) << " " << char('A' + indx2) << endl;
            return ;
        }


    }

    assert (true);

    cout << 3 << endl;
    cout << 1 << " " << n << " A" << endl;
    cout << n + 1 << " " << 2 * n << " B" << endl;
    cout << 2 * n + 1 << " " << 3 * n << " C" << endl;

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