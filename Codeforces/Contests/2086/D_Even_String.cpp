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

const int N = 5e5 + 30, mod = 998244353, INF = 1e18 + 10;

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

//
// int C(int n, int k){
//     if (n < k)return 0;
//     return mult(fact[n], mult(invfact[n - k], invfact[k]));
// }

// int starsandbars(int n,int k){ return C(n + k - 1, n); }

int dp[26][N];

int tot;

vector<int> mp(26);
int work(int indx, int sum){
    if (sum > tot / 2) return 0;
    // if (indx >= 26 && sum == tot / 2){ kar(indx, sum); }
    if (indx >= 26 && sum == tot / 2) return 1;
    if (indx >= 26) return 0;

    int& ret = dp[indx][sum];
    if (ret != -1) return ret;

    ret = 0;
    // take
    if (mp[indx])ret = work(indx + 1, sum + mp[indx]);

    // leave
    ret = add(ret, work(indx + 1, sum));

    return ret;
}

void Solve(){
    for (auto& x : mp)cin >> x;

    tot = accumulate(all(mp), 0ll);
    for (int j = 0; j < 26; j++)for (int i = 0; i <= tot + 2; i++) dp[j][i] = -1;

    int wk = work(0, 0);


    int ans = mult(fact[tot / 2], fact[(tot + 1) / 2]);

    for (auto x : mp) ans = mult(ans, invfact[x]);

    ans = mult(ans, wk);
    cout << ans << endl;
    // meet in the middle

    // vector<int> cnt(26);
    // for (auto& x : cnt) cin >> cnt;
    // int sum = accumulate(all(cnt), 0ll);
    // vector<int> can;
    // can.pb(sum / 2);
    // can.pb(sum / 2 + sum % 2);
    //
    // vector<int> one, two;
    //
    // for (int j = 0; j < 13; j++)
    //     one.pb(cnt[j]);
    // for (int j = 13; j < 26; j++)two.pb(cnt[j]);
    //
    // auto work= [&](vector<int> vect ){
    //
    //     for (int mask= 0 ; mask < (1<<13)){
    //         for (int j= 0; j<13 ;j++){
    //             sum +=
    //         }
    //     }
    // }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    factorial();
    inverses();
    while (Test_case--) Solve();
}
