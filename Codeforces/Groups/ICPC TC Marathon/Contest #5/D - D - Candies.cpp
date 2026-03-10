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

const int N = 1e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int dp[104][N];
int n, k;


int add(int a, int b,int Mod = mod){ return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }

void Solve(){
    cin >> n >> k;

    for (int i = 0; i <= k; i++)dp[0][i] = 1;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for (int j = 0; j <= k; j++){ dp[i][j] = add(dp[i - 1][j], (j - x -1>= 0 ? -dp[i - 1][j - x-1] : 0)); }
        for (int j = 1; j <= k; j++){ dp[i][j] = add(dp[i][j], dp[i][j - 1]); }
    }
    cout << add ( dp[n][k], - dp[n][k-1]);
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
