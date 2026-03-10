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

int fact[N]{1}, invfact[N]{1};
void factorial(){ for (int i = 1; i < N; i++)fact[i] = mult(i, fact[i - 1]); }

void inverses(){
    invfact[N - 1] = modinv(fact[N - 1]);
    for (int i = N - 1; i >= 1; i--)invfact[i - 1] = mult(invfact[i], i);
}

int C(int n, int k){
    if (n < k)return 0;
    return mult(fact[n], mult(invfact[n - k], invfact[k]));
}

int starsandbars(int n,int k){ return C(n + k - 1, n); }

void Solve(){
    int n;
    cin >> n;
    vector<int> v(n), mp(n + 3), suff(n + 4);
    vector dp(2, vector<int>(n + 2));

    for (auto& x : v) cin >> x;
    for (auto x : v) mp[x]++;
    for (int i = n; i >= 0; i--) suff[i] = suff[i + 1] + mp[i];

    fill(all(dp[0]), 1);

    int mn = INF;
    int ans = 0;
    for (int x = 0; x <= n; x++){
        mn = min(mn, mp[x]);
        for (int i = 0; i <= mp[x] + 1; i++)dp[1][i] = 0;

        int tot = binpow(2ll, mp[x]);
        for (int i = 0; i <= mn; i++){
            tot = add(tot, -C(mp[x], i));
            dp[1][i] = add(dp[1][i], mult(C(mp[x], i), dp[0][i]));
            dp[1][i] = add(dp[1][i], mult(tot,  add(dp[0][i], -dp[0][i+1])));
        }

        for (int i = 1; i <= mn; i++){ ans = add(ans, mult(binpow(2ll, suff[x + 1]), mult(dp[1][i], i))); }

        for (int i = mp[x]; i >= 0; i--) dp[1][i] = add(dp[1][i], dp[1][i + 1]);

        swap(dp[0], dp[1]);
    }

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    factorial();
    inverses();
    while (Test_case--) Solve();
}
