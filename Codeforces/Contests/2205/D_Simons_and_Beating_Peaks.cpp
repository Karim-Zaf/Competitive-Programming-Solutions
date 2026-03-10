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
#define endl '\n'

const int N = 5e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve(){
    int n;
    cin >> n;
    vector<int> v(n + 2);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<pair<int, int>> vp;

    for (int i = 1; i <= n; i++) vp.push_back({v[i], i});
    sort(rall(vp));

    set<int> s;
    s.insert(0);
    s.insert(n + 1);
    vector<int> imin(n + 2), isar(n + 2);

    for (auto [val, pos] : vp){
        auto it = s.lower_bound(pos);

        imin[pos] = *it;
        isar[pos] = *prev(it);
        s.insert(pos);
    }

    vector<int> droite(n + 3), gauche(n + 2), dp(n + 2, INF);

    for (auto [val, pos] : vp){
        int dist_gauche = pos - isar[pos] - 1;
        int dist_droite = imin[pos] - pos - 1;

        dp[pos] = dist_gauche + dist_droite;
        dp[pos] += droite[imin[pos]];
        dp[pos] += gauche[isar[pos]];
        droite[pos] = droite[imin[pos]] + dist_droite;
        gauche[pos] = gauche[isar[pos]] + dist_gauche;
    }

    cout << *min_element(dp.begin(), dp.end()) << endl;
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
