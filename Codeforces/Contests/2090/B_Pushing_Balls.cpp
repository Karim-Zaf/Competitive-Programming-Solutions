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

void Solve(){
    int n, m;
    cin >> n >> m;
    char c[n + 1][m + 1];
    int pref[2][n + 1][m + 1];;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++){
            c[i][j] = '0';
            pref[0][i][j] = pref[1][i][j] = 0;
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];

    for (int i = 1; i <= n; i++){ for (int j = 1; j <= m; j++){ pref[0][i][j] = pref[0][i][j - 1] + (c[i][j] - '0'); } }
    for (int j = 1; j <= m; j++){ for (int i = 1; i <= n; i++){ pref[1][i][j] = pref[1][i - 1][j] + (c[i][j] - '0'); } }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){ cout << pref[0][i][j] << " "; }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (c[i][j] == '1' && pref[0][i][j] != j && pref[1][i][j] != i)return void(cout << "NO\n");
        }
    }
    cout << "YES\n";
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
