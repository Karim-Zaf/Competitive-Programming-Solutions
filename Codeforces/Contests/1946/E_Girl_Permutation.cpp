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
    return divide(fact[n], mult(fact[n - k], fact[k]));
}

int starsandbars(int n,int k){ return C(n + k - 1, n); }

void Solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> pref(m1), suff(m2);
    for (auto& x : pref) cin >> x;
    for (auto& x : suff) cin >> x;


    if (pref.front() != 1 || suff.back() != n || suff.front() != pref.back()) return void(cout << 0 << endl);

    int ans = C(n - 1, pref.back() - 1);
    int left_lef = pref.back() - 1;
    for (int i = m1 - 2; i >= 0; i--){
        int diff = pref[i + 1] - pref[i] - 1;

        left_lef--;
        ans = mult(ans, mult ( fact[diff],C(left_lef, diff)));
        left_lef -= diff;
    }

    int left_right = n - pref.back();

    for (int i = 1; i < m2; i++){
        int diff = suff[i] - suff[i - 1] - 1;
        left_right--;
        ans = mult(ans, mult ( fact[diff],C(left_right, diff)));
        left_right -= diff;
    }

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;

    factorial();
    inverses();
    cin >> Test_case;
    while (Test_case--) Solve();
}
