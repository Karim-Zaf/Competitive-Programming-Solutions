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
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<pair<int,int>> suff(3 * n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    for (int i = 0; i < 2 * n; i++)a.pb(a[i]);
    for (int i = 0; i < 2 * n; i++)b.pb(b[i]);

    for (int i = 0; i < 3 * n; i++) suff[i].F = a[i] - b[i];
    for (int i = 3 * n - 2; i >= 0; i--) suff[i].F += suff[i + 1].F;
    for (int i = 0; i < 3 * n; i++) suff[i].S = i;

    sort(rall(suff));

    set<int> indx;

    for (auto [val, i] : suff){
        auto it = indx.lower_bound(i);
        if (it != indx.end()) ans = max(ans, *it - i);
        indx.insert(i);
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
