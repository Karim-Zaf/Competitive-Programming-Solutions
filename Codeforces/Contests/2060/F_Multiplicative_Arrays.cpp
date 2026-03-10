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

const int N = 1e5 + 30, mod = 998244353, INF = 1e18 + 10;

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

const int M = 50;
int prep[M][M];

int C(int n, int k){
    if (n < M && k < M && prep[n][k] != -1) return prep[n][k];
    // n!/ (n-k)! k!

    if (n < k)return 0;
    int ret = 1;
    for (int i = n - k + 1; i <= n; i++) ret = mult(ret, i);
    for (int i = 1; i <= k; i++) ret = divide(ret, i);
    return ret;
    return divide(fact[n], mult(fact[n - k], fact[k]));
}

int starsandbars(int n,int k){ return C(n + k - 1, n); }

vector<pair<int,int>> factors(int n){
    vector<pair<int,int>> res;
    for (int d = 2; d * d <= n; d++){
        if (n % d) continue;
        int cnt = 0;
        while (n % d == 0){
            n /= d;
            cnt++;
        }
        res.push_back({d, cnt});
    }
    if (n > 1)res.push_back({n, 1});
    return res;
}

void Solve(){
    int k, n;
    cin >> k >> n;

    for (int i = 1; i <= k; i++){
        int ans = 0;
        int sum_coeff = 0;
        vector<pair<int,int>> vp = factors(i);

        for (auto [prime , occ] : vp)sum_coeff += occ;

        int prv = 0;

        vector<int> dp(sum_coeff + 1, 1);
        for (int taille = 1; taille <= sum_coeff; taille++){
            for (auto [prime , occ] : vp){ dp[taille] = mult(dp[taille], starsandbars(occ, taille)); }

            for (int j = 1; j < taille; j++){ dp[taille] = add(dp[taille], -mult(dp[j], C(taille, j))); }
        }
        for (int taille = 1; taille <= sum_coeff; taille++){ ans = add(ans, mult(dp[taille], C(n + 1, taille + 1))); }

        cout << (i == 1 ? n : ans) << " ";
    }

    cout << endl;
}

void preprocess(){
    memset(prep, -1, sizeof(prep));
    for (int i = 0; i < M; i++){ for (int j = 0; j < M; j++){ prep[i][j] = C(i, j); } }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    factorial();
    preprocess();
    while (Test_case--) Solve();
}
