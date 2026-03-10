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

using cd = complex<double>;
const double PI = acos(-1);

const ll root = 15311432; // which is basically 3 ^ 119
const ll root_1 = 469870224;
const ll root_pw = (1 << 23);

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

void ntt(vector<ll>& a, bool invert){
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++){
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1){
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len){
            int w = 1;
            for (int j = 0; j < len / 2; j++){
                int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert){
        int n_1 = modinv(n, mod);
        for (ll& x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b){
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + (int)b.size()){ n <<= 1; }
    fa.resize(n);
    fb.resize(n);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; ++i){ fa[i] = fa[i] * fb[i] % mod; }
    ntt(fa, true);
    while (fa.size() > 1 && fa[fa.size() - 1] == 0){ fa.pop_back(); }

    return fa;
}

void Solve(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> vs(n), ks(n);

    int shift = n - 1;
    for (int i = 0; i < n; i++){
        if (s[i] == 'K') ks[i] = 1;
        if (s[i] == 'V') vs[-i + shift] = 1;
    }
    vector<int> t = multiply(ks, vs);


    vector<int> ans;
    for (int i = 1; i <= n; i++){
        int ok = 1;

        for (int j = 0; j < n; j += i){kar(j+shift,t[j+shift]);
            if (t[j + shift]) ok = 0;
            if (t[-j + shift]) ok = 0;
        }
        if (ok) ans.pb(i);
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
