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
    int n, m;
    cin >> n >> m;
    int t[n + 2][m + 2];
    int pref[n + 2][m + 2];

    int cnt_ones = 0;
    memset(t, 0, sizeof(t));
    memset(pref, 0, sizeof(pref));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){ cnt_ones += t[i][j]; }
    for (int j = 1; j <= m; j++){ for (int i = n; i >= 1; i--){ pref[i][j] = pref[i + 1][j] + t[i][j]; } }

    int curr = 0;

    string ret = "";
    for (int j = 1; j <= m; j++){
        if (curr + pref[1][j] <= cnt_ones / 2){
            ret += 'R';
            curr += pref[1][j];
            continue;
        }
        int pos = 1;
        while (pos <= n && curr + pref[pos][j] > cnt_ones / 2){
            ret += 'D';
            pos++;
        }
        curr += pref[pos][j];
        ret += 'R';
        break;
    }

    int cnt_d = count(all(ret), 'D');
    int cnt_r = count(all(ret), 'R');

    while (cnt_d < n){
        ret += 'D';
        cnt_d++;
    }
    while (cnt_r < m){
        ret += 'R';
        cnt_r++;
    }

    cout << cnt_ones / 2 * (cnt_ones - cnt_ones / 2) << endl;
    cout << ret << endl;
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
