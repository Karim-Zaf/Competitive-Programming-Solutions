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

    vector<int> v(n + 1), pref(n + 1);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] ^ v[i];
        mp[pref[i]].pb(i);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int xr = pref[r] ^ pref[l - 1];

        if (l == r)cout << "NO\n";
        else if (xr == 0) cout << "YES\n";
        else {

            // i will divide it into three ;
            int one = pref[l - 1] ^ xr;
            int two = one ^ xr;

            int posone = lower_bound(all(mp[one]), l) - mp[one].begin();
            if (posone == mp[one].size()) {
                cout << "NO\n";
                continue;
            }

            posone = mp[one][posone];

            int postwo = upper_bound(all(mp[two]), posone) - mp[two].begin();
            if (postwo == mp[two].size()) {
                cout << "NO\n";
                continue;
            }
            postwo = mp[two][postwo];

            if (postwo < r)cout << "YES\n";
            else cout << "NO\n";

        }


    }
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