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

const int N = 3e5 + 30, mod = 998244353, INF = 1e18 + 10;

int binpow(int a, int k, int res = 1,int Mod = mod){
    while (k){
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a,int Mod = mod){ return binpow(a, Mod - 2); }
int mult(int a, int b,int Mod = mod){
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b,int Mod = mod){ return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }
int divide(int a, int b,int Mod = mod){
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}

const int M = 3005;
vector<int> dv[M];

void sieve(){
    for (int i = 1; i < M; i++)
        for (int j = i; j < M; j += i)
            dv[j].push_back(i);
}

void Solve(){
    int n, m;
    cin >> n >> m;

    vector dp(m + 1, vector<int>(m + 1));

    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++)cin >> v[i];
    if (v[1] && v[1] != 1) return void(cout << 0 << endl);

    v[1] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (auto d : dv[j]){ if (j - d >= 0){ dp[i][j] = add(dp[i][j], dp[i - 1][j - d]); } }
        }
        for (int j = 1; j <= m; j++){ if (v[i] && j != v[i]) dp[i][j] = 0; }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) ans = add(ans, dp[n][i]);
    if (v[n]) ans = dp[n][v[n]];
    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    sieve();
    cin >> Test_case;
    while (Test_case--) Solve();
}
