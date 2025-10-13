/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    vector<vector<int>> subsets;

    for (int mask = 1; mask < (1 << n); mask++){
        vector<int> curr_subset;

        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                curr_subset.pb(v[i]);

        subsets.pb(curr_subset);
    }

    sort(all(subsets));

    int m = subsets.size();
    vector pref(n, vector<int>(m + 2, 0));

    int q;
    cin >> q;

    auto get_index = [&](int x){ // not the most optimised
        for (int i = 0; i < n; i++)
            if (v[i] == x)
                return i;
    };

    while (q--){
        int l, r, val;
        cin >> l >> r >> val;

        l--, r--;

        int indx_ofval = get_index(val);
        pref[indx_ofval][l] += 1;
        pref[indx_ofval][r + 1] -= 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            pref[i][j] += pref[i][j - 1];

    vector<int> ans(m, 1);

    for (int i = 0; i < m; i++){
        vector<int> occ(n);
        for (auto x : subsets[i])
            occ[get_index(x)]++;

        for (int j = 0; j < n; j++)
            occ[j] += pref[j][i];

        for (int j = 0; j < n; j++){
            ans[i] *= (occ[j] % 2 == 1 ? v[j] : 1);
            ans[i] %= mod;
        }
    }

    for (auto x : ans) cout << x << " ";
    cout << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
