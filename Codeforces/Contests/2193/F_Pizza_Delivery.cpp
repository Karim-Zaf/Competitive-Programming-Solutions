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
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector<int> x(n), y(n);
    for (auto& xx : x) cin >> xx;
    for (auto& xx : y) cin >> xx;

    map<int, pair<int,int>> mp;
    mp[ax] = {ay, ay};
    mp[bx] = {by, by};
    kar(x, y);
    for (int i = 0; i < n; i++){
        if (mp.count(x[i]) == 0) mp[x[i]] = {y[i], y[i]};
        mp[x[i]].F = min(mp[x[i]].F, y[i]);
        mp[x[i]].S = max(mp[x[i]].S, y[i]);
    }

    kar(mp);
    int ans = 0;

    int lst_x = ax;
    pair<int,int> dp{0,0};
    for (auto [x, cnt] : mp){
        auto [l,r] = cnt;
        auto [lst_l, lst_r] = mp[lst_x];

        pair dpp = {INF, INF};


        dpp.S = min(dpp.S , dp.F + abs(lst_l- l) + (r-l));
        dpp.S = min(dpp.S , dp.S + abs(lst_r- l) + (r-l));
        dpp.S = min(dpp.S , dp.F + abs(lst_l- r) + 2*(r-l));
        dpp.S = min(dpp.S , dp.S + abs(lst_r- r) + 2*(r-l));


        dpp.F = min(dpp.F , dp.F + abs(lst_l- l) + 2*(r-l));
        dpp.F = min(dpp.F , dp.S + abs(lst_r- l) + 2*(r-l));
        dpp.F = min(dpp.F , dp.F + abs(lst_l- r) + (r-l));
        dpp.F = min(dpp.F , dp.S + abs(lst_r- r) + (r-l));

        swap( dp , dpp);

        lst_x = x;
    }

    ans = min( dp.F , dp.S);
    ans += bx - ax;
    cout << ans << endl;
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
