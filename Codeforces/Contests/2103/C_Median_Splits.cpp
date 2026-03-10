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
    int n, k;
    cin >> n >> k;

    vector<int> v(n + 1), pref(n + 1), suff(n + 4);

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++){
        if (v[i] <= k) pref[i] = -1;
        if (v[i] > k) pref[i] = 1;
        suff[i] = pref[i];
        pref[i] += pref[i - 1];
    }
    for (int i = n; i >= 1; i--)suff[i] += suff[i + 1];

    int mn = -INF;
    for (int i = 1; i < n; i++){
        kar(mn);
        if (pref[i] <= 0 && mn >= pref[i]) return void(cout << "YES\n");
        if (pref[i] <= 0) mn = max(pref[i], mn);
    }
    int lst_neg = -INF;
    for (int i = 1; i <= n; i++){ if (suff[i] <= 0){ lst_neg = i; } }
    for (int i = 1; i <= n; i++){ if (pref[i] <= 0 && i <= lst_neg - 2){ return void(cout << "YES\n"); } }

    reverse(v.begin() + 1, v.end());
    fill(all(pref), 0ll);
    fill(all(suff), 0ll);

    for (int i = 1; i <= n; i++){
        if (v[i] <= k) pref[i] = -1;
        if (v[i] > k) pref[i] = 1;
        suff[i] = pref[i];
        pref[i] += pref[i - 1];
    }
    for (int i = n; i >= 1; i--)suff[i] += suff[i + 1];
    mn = -INF;
    for (int i = 1; i < n; i++){
        kar(mn);
        if (pref[i] <= 0 && mn >= pref[i]) return void(cout << "YES\n");
        if (pref[i] <= 0) mn = max(pref[i], mn);
    }

    cout << "NO\n";
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
