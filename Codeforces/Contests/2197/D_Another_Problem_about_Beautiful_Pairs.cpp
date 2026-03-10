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

const int N = 2e5 + 10;

const int SQ = 449;

void Solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    int sq = sqrt(n + 5);

    for (auto& x : v) cin >> x;

    vector<vector<int>> pos(sq + 10);
    for (int i = 0; i < n; i++){ if (v[i] <= sq){ pos[v[i]].pb(i); } }

    ll ans = 0;
    vector<int> mp(n + 10);

    for (int x = 0; x <= sq; x++){
        for (auto p : pos[x])mp[p]++;

        for (auto i : pos[x]){
            if (v[i] * v[i] + i >= 0 && v[i] * v[i] + i <= n)
                ans += mp[v[i] * v[i] + i];
        }

        for (auto p : pos[x])mp[p]--;
    }

    // for (int i = 2; i <= sq; i += 2)
    //     ans -= dp[i][i * i / 2];
    // ans /= 2;

    for (int j = 0; j <= sq; j++){
        for (auto p : pos[j])mp[p]++;

        for (int i = 0; i < n; i++){
            if (j >= v[i]) continue;
            if (j * v[i] + i >= 0 && j * v[i] + i <= n){ ans += mp[j * v[i] + i]; }
            if (-j * v[i] + i >= 0 && -j * v[i] + i <= n){ ans += mp[-j * v[i] + i]; }
        }
        for (auto p : pos[j])mp[p]--;
        kar(ans);
    }

    cout << ans << '\n';
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
