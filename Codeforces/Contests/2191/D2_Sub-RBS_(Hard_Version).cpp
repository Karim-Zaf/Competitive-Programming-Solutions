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

const int N = 3e5 + 30, mod = 998244353, INF = 1e18 + 10;

const int M = 105;
int n;
string s;
int dp[8][M][M][M];
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

int work(int mask, int size, int pos, int sum = 0){
    if (size < 0) return 0;
    if (sum < 0) return 0;

    if (pos >= n && sum == 0 && size == 0 && mask == 7) return 1;
    if (pos >= n) return 0;

    int& ret = dp[mask][size][pos][sum];

    if (ret != -1) return ret;

    int nw_mask = mask;
    if (s[pos] == ')') nw_mask |= 4;
    if ((nw_mask & 4) && s[pos] == '('){
        if (nw_mask & 2) nw_mask |= 1;
        else nw_mask |= 2;
    }

    // take
    ret = work(nw_mask, size - 1, pos + 1, sum + (s[pos] == '(' ? 1 : -1));
    //leave
    ret = add(ret, work(mask, size, pos + 1, sum));

    return ret;
}

void Solve(){
    cin >> n >> s;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                for (int l = 0; l < 8; l++)
                    dp[l][i][j][k] = -1;

    int ans = 0;
    for (int sz = 6; sz <= n; sz += 2){ ans = add(ans, mult(sz - 2, work(0, sz, 0, 0))); }
    cout << ans << endl;
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
