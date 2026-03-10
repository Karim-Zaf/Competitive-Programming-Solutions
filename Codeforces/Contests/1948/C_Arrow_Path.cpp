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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

int dp[2][N];

void Solve() {
    int n;
    string s[2];
    cin >> n >> s[0] >> s[1];
    for (int i = 0; i <= n; i++) dp[0][i] = dp[1][i] = 0;
    dp[0][0]= 1 ;

    for (int i= 1; i<n ;i++){
        for (int j= 0 ; j<2 ;j++){
            if (i>=2 && s[j][i-1]=='>') dp[j][i]|=dp[j][i-2];
            if (i>=1 && s[j][i-1]=='>') dp[j][i]|=dp[j^1][i-1];
        }
    }
//    for (int i = 0; i < n; i++) cout << dp[0][i] << " " ; cout << endl;
//    for (int i = 0; i < n; i++) cout << dp[1][i] << " " ; cout << endl;

    cout << (dp[1][n-1]? "YES" : "NO") << endl;
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}