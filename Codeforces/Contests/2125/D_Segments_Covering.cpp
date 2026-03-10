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

void Solve(){
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 3, 0), prod(m + 3, 1);

    vector<vector<pair<int,int>>> mp(m + 4);

    for (int i = 1; i <= n; i++){
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        mp[r].pb({l, divide(p, q)});
        prod[r] = mult(prod[r], add(1, -divide(p, q)));
    }

    for (int i = 1; i <= m; i++) prod[i] = mult(prod[i], prod[i - 1]);

    auto get = [&](int l, int r){ return add(dp[r], -dp[l - 1]); };

    dp[0]= 1 ;
    for (int i = 1; i <= m; i++){
        sort(rall(mp[i]));
        for (auto [l, prob] : mp[i]){
            kar(divide(prod[i], prod[l - 1]), add(1, -prob))
            int curr = mult(mult(dp[l - 1], prob), divide(divide(prod[i], prod[l - 1]), add(1, -prob)));
            kar(curr) ;
            dp[i] = add(dp[i], curr);
        }
        kar(mp[i]);
        kar(dp[i]);

    }
    kar(dp);

    cout << dp[m] << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
