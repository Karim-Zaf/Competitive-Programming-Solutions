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
 
int binpow(int a, int k, int res = 1, int Mod = mod) {
    while (k) {
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}
 
int modinv(int a, int Mod = mod) { return binpow(a, Mod - 2); }
 
int mult(int a, int b, int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}
 
int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }
 
int divide(int a, int b, int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}
 
int fact[N]{1}, invfact[N]{1};
 
void factorial() { for (int i = 1; i < N; i++)fact[i] = mult(i, fact[i - 1]); }
 
void inverses() {
    invfact[N - 1] = modinv(fact[N - 1]);
    for (int i = N - 1; i >= 1; i--)invfact[i - 1] = mult(invfact[i], i);
}
 
int C(int n, int k) {
    if (n < k)return 0;
    return divide(fact[n], mult(fact[n - k], fact[k]));
}
 
int starsandbars(int n, int k) { return C(n + k - 1, n); }
 
 
vector <int> pos[5005];
 
int determine_mx(vector <int> &v, int n, int k) {
    vector <int> dp(n + 1);
 
    for (int i = 1; i <= n; i++) {
        pos[v[i]].pb(i);
 
        int sz = pos[v[i]].size();
 
        if (sz >= k) {
            int pos_lst = pos[v[i]][sz - k];
            dp[i] = dp[pos_lst - 1] + 1;
        }
 
        dp[i] = max(dp[i], dp[i - 1]);
    }
 
    return dp[n];
}
 
int dp[5005][5005];
int n, k, mx;
 
 
int work(int indice, int blocs, vector <int> &v) {
 
    if (blocs == mx) return 1ll;
    if (indice > n) return 0;
 
    int &ret = dp[indice][blocs];
 
    if (ret != -1) return ret;
 
    auto &mp = pos[v[indice]];
 
    int ps = lower_bound(all(mp), indice) - mp.begin();
 
    ps += k - 1;
 
    ret = 0;
 
    ret = add(ret, work(indice + 1, blocs, v));
 
    for (int j = ps, cnt = k; j < mp.size(); j++, cnt++) {
        int res = work(mp[j] + 1, blocs + 1, v);
        int prod = C(cnt - 2, k - 2);
 
        if (k == 1) prod = 1;
 
        res = mult(res, prod);
 
        ret = add(ret, res);
    }
 
    return ret;
}
 
void Solve() {
    cin >> n >> k;
 
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) pos[i].clear();
 
    mx = determine_mx(v, n, k);
 
    for (int i = 0; i <= n + 4; i++)
        for (int j = 0; j <= mx + 4; j++)
            dp[i][j] = -1;
 
    cout << work(1, 0, v) << endl;
 
}
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    factorial();
    while (Test_case--) Solve();
}