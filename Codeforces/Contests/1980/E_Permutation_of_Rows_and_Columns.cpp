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
    int n, m;
    cin >> n >> m;


    int a[n + 2][m + 2], b[n + 3][m + 2];
    vector<pair<int, int>> pos(n * m + 4), req(n * m + 3);

    vector<int> col(m + 1), rev_col(m + 1), lig(n + 1), rev_lig(n + 1);

    for (int i = 1; i <= n; i++) lig[i] = rev_lig[i]=i;
    for (int i = 1; i <= m; i++)col[i] = rev_col[i]=i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            pos[a[i][j]] = {i, j};
            req[b[i][j]] = {i, j};
        }

    for (int i = 1; i <= n * m; i++) {
        pair<int, int> here = pos[i];

//        here.F = lig[here.F] ;
//        here.S = col[here.S] ;

        pair<int, int> to = req[i];
        int position_lig = rev_lig[to.F];
        int position_col = rev_col[to.S];


        swap(lig[here.F], lig[position_lig]);
        swap(col[here.S], col[position_col]);

        rev_lig[lig[here.F]]= here.F;
        rev_lig[lig[position_lig]]= position_lig;
        rev_col[col[here.S]]= here.S;
        rev_col[col[position_col]]= position_col;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pair<int, int> p = pos[b[i][j]];
            if (a[i][j]==b[lig[i]][col[j]])continue;
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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